/*
 * MEXTI_interface.h
 *
 * Created: 2/2/2023 3:48:44 PM
 *  Author: 20100
 */ 


#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/*External interrupts' numbers*/
#define INT0_REQ_NUM             (0)
#define INT1_REQ_NUM             (1)
#define INT2_REQ_NUM             (2)

/*External interrupt modes*/
#define LOW_LEVEL_MODE           (0) 
#define LOGICAL_CHANGE_MODE      (1) 
#define FALLING_EDGE_MODE        (2) 
#define RISING_EDGE_MODE         (3) 

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function is used to enable specific external interrupt [0, 1 or 2]
 * 
 * @param au8_interruptNumber 
 */
void mexti_enableExternalInterrupt(u8_t au8_interruptNumber);

/**
 * @brief This function is used to disable specific external interrupt [0, 1 or 2]
 * 
 * @param au8_interruptNumber 
 */
void mexti_disableExternalInterrupt(u8_t au8_interruptNumber);

/**
 * @brief This function is used to attach function to a specific ISR [0, 1 or 2] with specific interrupt mode
 * 
 * @param au8_interruptNumber 
 * @param au8_interruptMode 
 * @param fptr_isrFunction 
 */
void mexti_attachISR(u8_t au8_interruptNumber, u8_t au8_interruptMode, void (*fptr_isrFunction)(void));




#endif /* MEXTI_INTERFACE_H_ */