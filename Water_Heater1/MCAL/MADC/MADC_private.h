/*
 * MADC_private.h
 *
 * Created: 2/2/2023 3:43:10 PM
 *  Author: 20100
 */ 


#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/***************************************************************************************************/
/*                                         ADC Registers                                           */
/***************************************************************************************************/

#define MADC_ADMUX                 (*(volatile u8_t*)(0x27))
#define MADC_ADCSRA                (*(volatile u8_t*)(0x26))
#define MADC_ADCH                  (*(volatile u8_t*)(0x25))
#define MADC_ADCL                  (*(volatile u8_t*)(0x24))
#define MADC_ADC                   (*(volatile u16_t*)(0x24))

/***************************************************************************************************/
/*                                       ADC Registers' bits                                       */
/***************************************************************************************************/

/*ADMUX register*/
#define MADC_ADMUX_ADLAR_BIT           (5)

/*ADCSRA register*/
#define MADC_ADCSRA_ADSC_BIT           (6)
#define MADC_ADCSRA_ADIF_BIT           (4)




#endif /* MADC_PRIVATE_H_ */