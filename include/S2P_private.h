/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   14/Sept/2020
 *  Type    :   S2P MATRIX Private File
 *  Version :   V1.0
 */

#ifndef S2P_PRIVATE_H
#define S2P_PRIVATE_H

enum S2P_PINS{
	STP_Q0 ,
	STP_Q1,
	STP_Q2,
	STP_Q3,
	STP_Q4,
	STP_Q5,
	STP_Q6,
	STP_Q7,

	STP_Q0i,
	STP_Q1i,
	STP_Q2i,
	STP_Q3i,
	STP_Q4i,
	STP_Q5i,
	STP_Q6i,
	STP_Q7i
};
u16 S2P_voidAllocateArrayTwoRegisters ( u16 Copy_u16Data);

#endif
