/*
 * HSEV_SEG_cfg.h
 *
 * Created: 2/2/2023 3:12:25 PM
 *  Author: 20100
 */ 


#ifndef HSEV_SEG_CFG_H_
#define HSEV_SEG_CFG_H_

/***************************************************************************************************/
/*                                       Configuration macros                                      */
/***************************************************************************************************/

/*Seven segment 1 configurations*/
#define SEV_SEG_1_EN_PORT       (PORTB)
#define SEV_SEG_1_EN_PIN        (PIN4)

/*Seven segment 2 configurations*/
#define SEV_SEG_2_EN_PORT       (PORTB)
#define SEV_SEG_2_EN_PIN        (PIN5)

/*Decoder input pins*/
#define SEV_SEG_DECODER_PORT    (PORTA)
#define SEV_SEG_A_PIN           (PIN4)
#define SEV_SEG_B_PIN           (PIN5)
#define SEV_SEG_C_PIN           (PIN6)
#define SEV_SEG_D_PIN           (PIN7)



#endif /* HSEV_SEG_CFG_H_ */