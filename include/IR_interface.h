/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   02/Sept/2020
 *  Type    :   IR Interface File
 *  Version :   V1.0
 */

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H



#define IR_POWER_BUTTON	69
#define IR_MODE_BUTTON	70
/* #define IR_REMOTE_MUTE
#define IR_REMOTE_PLAY*/
#define IR_REMOTE_BACK	64
#define IR_REMOTE_FORWARD	67
/*#define IR_REMOTE_EQ
#define IR_REMOTE_VOLUME_UP
#define IR_REMOTE_VOLUME_DOWN
#define IR_REMOTE_RPT
#define IR_REMOTE_U_SD
#define IR_REMOTE_0
#define IR_REMOTE_1
#define IR_REMOTE_2
#define IR_REMOTE_3
#define IR_REMOTE_4
#define IR_REMOTE_5
#define IR_REMOTE_6
#define IR_REMOTE_7
#define IR_REMOTE_8
#define IR_REMOTE_9 */

void IR_voidSetCallBack(void (*ptr) (u8));
void GetFrame(void);

#endif
