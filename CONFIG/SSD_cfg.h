/*
 * SSD_cfg.h
 *
 *  Created on: Feb 18, 2023
 *      Author: NTI
 */

#ifndef SSD_CFG_H_
#define SSD_CFG_H_

/*
 * choose SSD pins
 */

#define SSD_A_PIN	DIO_PB0
#define SSD_B_PIN	DIO_PB1
#define SSD_C_PIN	DIO_PB2
#define SSD_D_PIN	DIO_PB4
/*
 * choose enable pins
 */
#define SSD_DIG1_EN		DIO_PA3
#define SSD_DIG2_EN		DIO_PA2
#define SSD_DIG3_EN		DIO_PB5
#define SSD_DIG4_EN		DIO_PB6

#define SSD_DISPLAY_TIME 	250 //1000 msec
#endif /* SSD_CFG_H_ */
