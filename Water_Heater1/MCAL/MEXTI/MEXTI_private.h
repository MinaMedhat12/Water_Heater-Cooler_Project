/*
 * MEXTI_private.h
 *
 * Created: 2/2/2023 3:49:01 PM
 *  Author: 20100
 */ 


#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

/***************************************************************************************************/
/*                                         EXTI Registers                                          */
/***************************************************************************************************/

#define MEXTI_MCUCSR                    (*(volatile u8_t*)(0x54))
#define MEXTI_MCUCR                     (*(volatile u8_t*)(0x55))
#define MEXTI_GIFR                      (*(volatile u8_t*)(0x5A))
#define MEXTI_GICR                      (*(volatile u8_t*)(0x5B))

/***************************************************************************************************/
/*                                       EXTI Registers' bits                                      */
/***************************************************************************************************/

/*GICR bits*/
#define MEXTI_GICR_INT0_BIT             (6)
#define MEXTI_GICR_INT1_BIT             (7)
#define MEXTI_GICR_INT2_BIT             (5)

/*MCUCSR bits*/
#define MEXTI_MCUCSR_ISC2_BIT           (6)




#endif /* MEXTI_PRIVATE_H_ */