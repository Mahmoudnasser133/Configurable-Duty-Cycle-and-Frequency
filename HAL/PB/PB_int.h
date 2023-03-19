/*
 * PB_int.h
 *
 *  Created on: Feb 18, 2023
 *      Author: NTI
 */



#ifndef PB_PB_INT_H_
#define PB_PB_INT_H_

#define PB1_ID	1
#define PB2_ID	2
#define PB3_ID	3
#define PB4_ID	4

#define ACTIVE_LOW		0
#define ACTIVE_HIGH		1

#define PB_PREESED		1
#define PB_RELEASED		0

u8 H_PB_u8_Read(u8 PB_ID);

#endif /* PB_PB_INT_H_ */
