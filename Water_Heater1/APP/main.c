/*
 * Water_Heater1.c
 *
 * Created: 2/1/2023 1:49:17 PM
 * Author : 20100
 */ 

#include <avr/io.h>

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "avr/interrupt.h"
int main(void)
{
	
	/*Initializing the system */
	aset_mode_init();

	while(1)
	{
	
	aset_start_app();
			
    }
	
	return 0;
}