/*
 * LBIT_MATH.h
 *
 * Created: 2/2/2023 3:20:53 PM
 *  Author: 20100
 */ 


#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

/*Bit manipulation operations*/
#define SET_BIT(REG, BIT)        (REG |= (1 << BIT))
#define CLEAR_BIT(REG, BIT)      (REG &= ~(1 << BIT))
#define TOGGLE_BIT(REG, BIT)     (REG ^= (1 << BIT))
#define GET_BIT(REG, BIT)        ((REG >> BIT) & 0x1)




#endif /* LBIT_MATH_H_ */