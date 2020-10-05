/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   14/Sept/2020
 *  Type    :   S2P Interface File
 *  Version :   V1.0
 */

#ifndef S2P_INTERFACE_H
#define S2P_INTERFACE_H

void S2P_voidSendSynchronousOneRegister(u8 Copy_u8DataToSend);
void S2P_voidSendSynchronousTwoRegister(u16 Copy_u16DataToSend);
void S2P_LEDMRX_voidDisplay(u8 *Copy_u8Letter, u8 Copy_u8FrameRate);
void S2P_LEDMRX_voidAnimation(u8* Copy_u8DataArray[], u8 Copy_u8FrameRate, u8 Copy_u8CharacterQty);

#endif
