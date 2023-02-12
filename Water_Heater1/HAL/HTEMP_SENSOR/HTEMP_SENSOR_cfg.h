/*
 * HTEMP_SENSOR_cfg.h
 *
 * Created: 2/2/2023 3:16:30 PM
 *  Author: 20100
 */ 


#ifndef HTEMP_SENSOR_CFG_H_
#define HTEMP_SENSOR_CFG_H_

/***************************************************************************************************/
/*                                       Configuration macros                                      */
/***************************************************************************************************/

/*  

    LM35 Tempreture Sensor used 
    Sensor gain (mV/Deg C)	10

*/

/*sensor connected to channel0 in microcontroller  */
#define config_TEMPSENSOR_CHANNEL        (ADC_CHANNEL_0)

/*sensor connected to PORTA*/
#define config_TEMPSENSOR_PORT           (PORTA)

/*sensor connected to pin0*/
#define config_TEMPSENSOR_PIN            (PIN0)


#endif /*__HTEMP_SENSOR_CFG_H__*/



