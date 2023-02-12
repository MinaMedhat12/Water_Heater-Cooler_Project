/*
 * HELEMENT_program.c
 *
 * Created: 2/8/2023 3:44:58 PM
 *  Author: 20100
 */ 


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HELEMENT_cfg.h"
#include "HELEMENT_interface.h"
#include "util/delay.h"



void helement_init(void)
{
	/*Setting the heating element pin to output*/
	mdio_setPinStatus(element_port , cooling_element_pin , OUTPUT);
	
	/*Setting the heating element pin to output*/
	mdio_setPinStatus(element_port , heating_element_pin , OUTPUT);
	
	/*Return from this function*/
	return;
}

void hheating_element_on(void)
{
	/*Setting the heating element pin to HIGH*/
	mdio_setPinValue(element_port , heating_element_pin , HIGH);
	
	/*Return from this function*/
	return;
}

void hcooling_element_on(void)
{
	/*Setting the cooling element pin to HIGH*/
	mdio_setPinValue(element_port , cooling_element_pin , HIGH);
	
	/*Return from this function*/
	return;
}

void hheating_element_off(void)
{
	/*Setting the heating element pin to LOW*/
	mdio_setPinValue(element_port , heating_element_pin , LOW);
	
	/*Return from this function*/
	return;
}

void hcooling_element_off(void)
{
	/*Setting the cooling element pin to LOW*/
	mdio_setPinValue(element_port , cooling_element_pin , LOW);
	
	/*Return from this function*/
	return;
}

