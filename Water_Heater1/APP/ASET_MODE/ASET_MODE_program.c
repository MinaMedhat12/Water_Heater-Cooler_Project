/*
 * ASET_MODE_program.c
 *
 * Created: 2/1/2023 3:02:54 PM
 *  Author: 20100
 */ 

// includes needed
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "util/delay.h"

#include "MTWI_interface.h"
#include "MADC_interface.h"
#include "MTIMER_interface.h"
#include "MTWI_interface.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "avr/interrupt.h"
#include "HEEP_interface.h"
#include "HPBUTT_interface.h"
#include "HSEV_SEG_interface.h"
#include "HTEMP_SENSOR_interface.h"
#include "HLED_interface.h"
#include "HELEMENT_interface.h"

#include "ASET_MODE_cfs.h"
#include "ASET_MODE_interface.h"

// status of the 3 buttons to check whether it's pressed or not
u8_t butt0_status;
u8_t butt1_status;
u8_t butt2_status;

// variables for set temp and current temp
u8_t current_temp;
u8_t set_temp;

// variable to count time after pressing up or down
static u8_t gu8_validtime = 0 ;

// flag for interrupt mode
u8_t int_mode = OFF ;

// flag to check if heating or cooling element is on
u8_t heating = OFF;
u8_t cooling = OFF;

static void Increment(void)
{
	// check the status of the up button
	hpbutt_getStatus(PUSH_BUTTON_1,&butt1_status);
	
	// enter setting mode for First Time
	if(butt1_status == LOW && int_mode == OFF )
	{
		//raising set mode flag to ON
		int_mode = ON ;

		//Reset Default of set temperature (60)
		set_temp = Initial_Temp;
	}

	// if set mode are already on
	else if (int_mode == ON)
	{
		// reset valid time
		gu8_validtime = 0 ;
		
		// if set temp reach min temp
		if(set_temp == Max_Temp )
		{
			set_temp = Max_Temp ;
		}
		else
		{
			// increment by five
			set_temp += 5 ;
		}
	}
	else
	{
		// Do Nothing
	}

	// Return Function
	return;
}

static void Decrement(void)
{
	// check the status of the down button
	hpbutt_getStatus(PUSH_BUTTON_2,&butt2_status);
	
	// enter setting mode for First Time
	if(butt2_status == LOW && int_mode == OFF )
	{
		//raising set mode flag to ON
		int_mode = ON ;

		//Reset Default of set temperature (60)
		set_temp = Initial_Temp;
	}

	// if set mode are already on
	else if (int_mode == ON)
	{
		// reset valid time
		gu8_validtime = 0 ;
			
		// if set temp reach min temp
		if(set_temp == Min_Temp )
		{
			set_temp = Min_Temp ;
		}
		else
		{
			// decrement by five
			set_temp -= 5 ;
		}
	}
	else
	{
		// Do Nothing
	}

	// Return Function
	return;	
}

void aset_mode_init()
{
	//initialize push button for On/Off
	hpbutt_init(PUSH_BUTTON_0);
	//initialize push button for Up
	hpbutt_init(PUSH_BUTTON_1);
	//initialize push button for Down
	hpbutt_init(PUSH_BUTTON_2);
	
	//initialize seven segments
	hsev_seg_init(SEV_SEG_1);
	hsev_seg_init(SEV_SEG_2);
	
	//initialize temp sensor
	htemp_sensor_init();
	
	//enable global interrupt
	sei();
	
	//initialize led
	hled_init(LED0); 
	
	//initialize eeprom
	heeprom_init();
	
	//for heating and cooling element
    helement_init();
	
	//initialize timer0
	mtimer_init(TIMER_CHANNEL_0,TIMER0_PWM_MODE,TIMER_PRESCALER_64);
	
	//initialize interrupt 0 and 1
	mexti_enableExternalInterrupt(INT0_REQ_NUM);
	mexti_enableExternalInterrupt(INT1_REQ_NUM);
	
	//firing an interrupt if increment or decrement functions are called
	mexti_attachISR(INT0_REQ_NUM , FALLING_EDGE_MODE  , Increment );
	mexti_attachISR(INT1_REQ_NUM , FALLING_EDGE_MODE  , Decrement );
	
	return;
}

void aset_start_app(){
	
	//writing the set temp value in the eeprom
	heeprom_writeByte(EEPROM_BLOCK_0,10, set_temp);
	
	//checking the status of the on/off button
	hpbutt_getStatus(PUSH_BUTTON_0,&butt0_status);

	//if the on/off button is on
	if(butt0_status == HIGH)
	{
		//if up or down button is pressed
		if (int_mode == ON)
		{
			//display 1 second
			for(u8_t i = 0 ; i < 10 ; i++)
			{
				hsev_seg_displayNumber(set_temp);
				
				//delay 1 sec
				_delay_ms(1000);
			}

			//increment valid time in setting mode
			gu8_validtime ++ ;

			//waiting for 5 second cause program time out
			if(gu8_validtime == 5 )
			{
				//comparing set temp with current temp
				acompare_temp(set_temp,current_temp);
				
				//Reset validation time
				gu8_validtime = 0 ;

				//Reset int_mode flag
				int_mode = OFF ;
				
				//set default current temp
				set_temp = Initial_Temp ;
			}
			else
			{
				/*Do Nothing*/
			}

			/*Blinking 1 second*/
			
		}
		
		
		else
		{
			// read temp of the sensor
			htemp_sensor_Read(&current_temp);
			
			// display temp
			hsev_seg_displayNumber(current_temp);
		}
	}
	else
	{
		// disable seven segments
		hsev_seg_disable(SEV_SEG_1);
		hsev_seg_disable(SEV_SEG_2);
	}
	
	
	return;
}


void acompare_temp(u8_t temp_1, u8_t temp_2)
{
	// sensor read temp
	htemp_sensor_Read(&temp_2);
	
	// while set temp and current temp not equal
	while(temp_1 != temp_2)
	{
		// get status of on/off button
		hpbutt_getStatus(PUSH_BUTTON_0,&butt0_status);
		
		//if on/off button is on
		if(butt0_status == HIGH)
		{
			//read current temp
			htemp_sensor_Read(&temp_2);
			
			//if difference between them bigger than 5
			if ((temp_1 - temp_2) > 5)
			{
				// turn off cooling and turn on heating
				hcooling_element_off();
				hheating_element_on();
				cooling = OFF;
				heating = ON;
				heating_element_led();
					
			}
			//if difference is smaller than -5
			else if ((temp_1 - temp_2) <= -5)
			{
				//turn off heating and turn on cooling
				heating = OFF;
				hheating_element_off();
				hcooling_element_on();
				cooling = ON;
				heating_element_led();
				
				
			}
			else
			// turn of every thing
			{
				hcooling_element_off();
				hheating_element_off();
				hled_ledValueOFF(LED0);
				return;
			}
			hsev_seg_displayNumber(temp_2);
		}
		else
		{
			heeprom_readByte(EEPROM_BLOCK_0,10,&set_temp);
			hcooling_element_off();
			hheating_element_off();
			hled_ledValueOFF(LED0);
			acompare_temp(temp_1,temp_2);
		}
	}
}


void heating_element_led(void)
{
	// if heating element is on toggle led
	if (heating == ON)
	{
		hled_toggleLedValue(LED0);	
	}
	// if cooling element is on turn on led
	else if (cooling == ON)
	{
		hled_ledValueON(LED0);
	}
	// else turn off the led
	else
	{
		hled_ledValueOFF(LED0);
	}
}

void asensor_Read(void)
{
	// read sensor temperature
	htemp_sensor_Read(&current_temp);
	
	return;
}