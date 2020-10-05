/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   10/Sept/2020
 *  Type    :   LED MATRIX Interface File
 *  Version :   V2.0
 */

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data, u8 Copy_u8FrameRate);
void HLEDMRX_voidAnimation(u8 **Copy_u8DataArray, u8 Copy_u8FrameRate, u8 Copy_u8CharacterQty);

extern u8 u8LetterA[];
extern u8 u8LetterB[];
extern u8 u8LetterC[];
extern u8 u8LetterD[];
extern u8 u8LetterE[];
extern u8 u8LetterF[];
extern u8 u8LetterG[];
extern u8 u8LetterH[];
extern u8 u8LetterI[];
extern u8 u8LetterJ[];
extern u8 u8LetterK[];
extern u8 u8LetterL[];
extern u8 u8LetterM[];
extern u8 u8LetterN[];
extern u8 u8LetterO[];
extern u8 u8LetterP[];
extern u8 u8LetterQ[];
extern u8 u8LetterR[];
extern u8 u8LetterS[];
extern u8 u8LetterT[];
extern u8 u8LetterU[];
extern u8 u8LetterV[];
extern u8 u8LetterW[];
extern u8 u8LetterX[];
extern u8 u8LetterY[];
extern u8 u8LetterZ[];
#endif
