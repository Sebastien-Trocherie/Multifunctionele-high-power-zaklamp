/*
 * Morse.c
 *
 *  Created on: 10 mei 2021
 *      Author: troch
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "Morse.h"

uint8_t ucMorseConvert( uint8_t data )
{
	static uint8_t rx_lenght = 0;
	static uint8_t rx_data[128];
	static uint8_t ucStatus = 0;

	if(data != 10)
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

		rx_data[rx_lenght] = data;
		rx_lenght++;
	}
	else
	{
		for(uint8_t i = 0; i < rx_lenght; i++)
		{
			switch (rx_data[i])
			{
				    case 97:			//a
				    	vMorseSend(0b10, 2);
				        break;
				    case 98:			//b
				    	vMorseSend(0b0111, 4);
				    	break;
				    case 99:			//c
				    	vMorseSend(0b0101, 4);
				        break;
				    case 100:			//d
				    	vMorseSend(0b011, 3);
				        break;
				    case 101:			//e
				    	vMorseSend(0b1 , 1);
				        break;
				    case 102:			//f
				    	vMorseSend(0b1101, 4);
				        break;
				    case 103:			//g
				    	vMorseSend(0b001, 3);
				        break;
				    case 104:			//h
				    	vMorseSend(0b1111, 4);
				        break;
				    case 105:			//i
				    	vMorseSend(0b11, 2);
				        break;
				    case 106:			//j
				    	vMorseSend(0b1000, 4);
				        break;
				    case 107:			//k
				    	vMorseSend(0b010, 3);
				        break;
				    case 108:			//l
				    	vMorseSend(0b1011, 4);
				        break;
				    case 109:			//m
				    	vMorseSend(0b00, 2);
				        break;
				    case 110:			//n
				    	vMorseSend(0b01, 2);
				        break;
				    case 111:			//o
				    	vMorseSend(0b000, 3);
				        break;
				    case 112:			//p
				    	vMorseSend(0b1001, 4);
				        break;
				    case 113:			//q
				    	vMorseSend(0b0010, 4);
				        break;
				    case 114:			//r
				    	vMorseSend(0b101, 3);
				        break;
				    case 115:			//s
				    	vMorseSend(0b111, 3);
				        break;
				    case 116:			//t
				    	vMorseSend(0b0, 1);
				        break;
				    case 117:			//u
				    	vMorseSend(0b110, 3);
				        break;
				    case 118:			//v
				    	vMorseSend(0b1110, 4);
				        break;
				    case 119:			//w
				    	vMorseSend(0b100, 3);
				        break;
				    case 120:			//x
				    	vMorseSend(0b0110, 4);
				        break;
				    case 121:			//y
				    	vMorseSend(0b0100, 4);
				        break;
				    case 122:			//z
				    	vMorseSend(0b0011, 4);
				        break;
				    case 48:			//0
				    	vMorseSend(0b00000, 5);
				        break;
				    case 49:			//1
				    	vMorseSend(0b10000, 5);
				        break;
				    case 50:			//2
				    	vMorseSend(0b11000, 5);
				        break;
				    case 51:			//3
				    	vMorseSend(0b11100, 5);
				        break;
				    case 52:			//4
				    	vMorseSend(0b11110, 5);
				        break;
				    case 53:			//5
				    	vMorseSend(0b11111, 5);
				        break;
				    case 54:			//6
				    	vMorseSend(0b01111, 5);
				        break;
				    case 55:			//7
				    	vMorseSend(0b00111, 5);
				        break;
				    case 56:			//8
				    	vMorseSend(0b00011, 5);
				        break;
				    case 57:			//9
				    	vMorseSend(0b00001, 5);
				        break;
				    case 32:			//space
				    	vMorseSend(0b0000, 4);
				    	break;
				    default: vMorseSend(0,0);
				    break;
			}
		}
		rx_lenght = 0;
	}
}

void vMorseSend( uint8_t code, uint8_t lenght )
{
	for(int i = (lenght - 1) ; i >= 0; i--)
	{
		if((code >> i) & 0x01)
		{
			TIM2->CCR1 = 160;
			HAL_Delay(300);			//DOT = 1 time unit
		}
		else
		{
			TIM2->CCR1 = 0;
			HAL_Delay(900);			//DASH = 3 time units
		}
	}
	TIM2->CCR1 = 0;
	HAL_Delay(900);					//Space between letters = 3 time units
}
