/*
 * morse.h
 *
 *  Created on: 23 mei 2021
 *      Author: troch
 */

#ifndef INC_MORSE_H_
#define INC_MORSE_H_

void vMorseConvert( uint8_t *ucData, uint16_t usLenght );
void vMorseSend( uint16_t usCode, uint16_t usLenght );
void vMorseClearBuf( uint8_t *ucDataBuf, uint16_t *usDataSize );

#endif /* INC_MORSE_H_ */
