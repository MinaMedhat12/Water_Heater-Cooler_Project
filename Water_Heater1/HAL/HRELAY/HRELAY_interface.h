/*
 * HRELAY_interface.h
 *
 * Created: 2/2/2023 3:08:22 PM
 *  Author: 20100
 */ 


#ifndef HRELAY_INTERFACE_H_
#define HRELAY_INTERFACE_H_
/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This Function to initialize Relay pin status
 * 
 */
void hrelay_init(void);

/**
 * @brief This Function to switch relay on 
 * 
 */
void hrelay_switchON(void);

/**
 * @brief This Function to switch relay on
 * 
 */
void hrelay_switchOFF(void);




#endif /* HRELAY_INTERFACE_H_ */