/*
 * HPBUTT_interface.h
 *
 * Created: 2/1/2023 3:30:37 PM
 *  Author: 20100
 */ 


#ifndef HPBUTT_INTERFACE_H_
#define HPBUTT_INTERFACE_H_


/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*System push buttons*/
#define PUSH_BUTTON_0    (0)
#define PUSH_BUTTON_1    (1)
#define PUSH_BUTTON_2    (2)

/* Push button status:
 * PRESSED  (HIGH -> 1)
 * RELEASED (LOW -> 0)
 */
#define PRESSED          (1)
#define RELEASED         (0)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is responsible for initializing the push button as input
 * 
 * @param au8_pbNumber 
 */
void hpbutt_init(u8_t au8_pbNumber);

/**
 * @brief This function is resposible for getting the push button status [PRESSED / RELEASED]
 * 
 * @param au8_pbNumber 
 * @param pu8_pbStatus 
 */
void hpbutt_getStatus(u8_t au8_pbNumber, u8_t* pu8_pbStatus);


#endif /* HPBUTT_INTERFACE_H_ */