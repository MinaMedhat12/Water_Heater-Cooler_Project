/*
 * ASET_MODE_interface.h
 *
 * Created: 2/1/2023 3:02:30 PM
 *  Author: 20100
 */ 


#ifndef ASET_MODE_INTERFACE_H_
#define ASET_MODE_INTERFACE_H_

/**
 * @brief This function is responsible for initializing the set mode
 */
void aset_mode_init(void);

/**
 * @brief This function is responsible for starting the set mode
 *
 */
void aset_start_app(void);

/**
 * @brief This function is responsible for comparing the setTemp and the current temp
 *
 * @param curnt_temp
 * @param set_temp
 */
void acompare_temp(u8_t curnt_temp, u8_t set_temp);

/**
 * @brief This function is responsible for controlling the led
 *
 */
void heating_element_led(void);

/**
 * @brief This function is responsible for reading the temp of the sensor
 *
 */
void asensor_Read(void);

#endif /* ASET_MODE_INTERFACE_H_ */