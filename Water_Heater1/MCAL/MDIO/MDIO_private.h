/*
 * MDIO_private.h
 *
 * Created: 2/2/2023 3:46:17 PM
 *  Author: 20100
 */ 


#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_
/***************************************************************************************************/
/*                                         DIO Registers                                           */
/***************************************************************************************************/

/*PORTA registers*/
#define MDIO_PORTA_ADDRESS                   ((volatile u8_t*)(0x3B))
#define MDIO_DDRA_ADDRESS                    ((volatile u8_t*)(0x3A))
#define MDIO_PINA_ADDRESS                    ((volatile u8_t*)(0x39))

/*PORTB registers*/
#define MDIO_PORTB_ADDRESS                   ((volatile u8_t*)(0x38))
#define MDIO_DDRB_ADDRESS                    ((volatile u8_t*)(0x37))
#define MDIO_PINB_ADDRESS                    ((volatile u8_t*)(0x36))

/*PORTC registers*/
#define MDIO_PORTC_ADDRESS                   ((volatile u8_t*)(0x35))
#define MDIO_DDRC_ADDRESS                    ((volatile u8_t*)(0x34))
#define MDIO_PINC_ADDRESS                    ((volatile u8_t*)(0x33))

/*PORTD registers*/
#define MDIO_PORTD_ADDRESS                   ((volatile u8_t*)(0x32))
#define MDIO_DDRD_ADDRESS                    ((volatile u8_t*)(0x31))
#define MDIO_PIND_ADDRESS                    ((volatile u8_t*)(0x30))





#endif /* MDIO_PRIVATE_H_ */