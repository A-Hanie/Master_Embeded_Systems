/*
 * BIT_MATH.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Hany
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)	(REG |= 1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)	((REG>>BIT_NUM) & 0x01)
#define CLR_BIT(REG,BIT_NUM)	(REG &= ~(1<<BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)	(REG ^= (1<<BIT_NUM))

#endif /* BIT_MATH_H_ */
