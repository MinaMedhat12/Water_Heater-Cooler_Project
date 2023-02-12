/*
 * HTEMP_SENSOR_interface.h
 *
 * Created: 2/2/2023 3:16:49 PM
 *  Author: 20100
 */ 


#ifndef HTEMP_SENSOR_INTERFACE_H_
#define HTEMP_SENSOR_INTERFACE_H_

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This Function to initialize sensor pins 
 * 
 */
void htemp_sensor_init(void);


/**
 * @brief This Function to read analog signal from specified Pin
 * 
 * @param u8_temp 
 */
void htemp_sensor_Read(u8_t* u8_temp);




#endif /* HTEMP_SENSOR_INTERFACE_H_ */