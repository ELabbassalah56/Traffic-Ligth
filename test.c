/*
 * test.c
 *
 *  Created on: 12/08/2020
 *      Author:elabbas salah hatata
 */


#include<avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>

void Count_27();
void Count_10();
void Count_3();
typedef enum SevenSegment{ZERO=0b00111111,ONE=0b00000110,TWO=0b01011011,THREE=0b01001111,FOUR=0b01100110,FIVE=0b01101101,SIX=0b01111101,SEVEN=0b00000111,EIGHT=0b01111111,NINE=0b01101111,DOT=0b10000000}Ssegment;

Ssegment Arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};


int  main(void)
{


DDRA=0xff;
DDRC=0xff;
DDRD=0xff;

while(1){

Count_27();
_delay_ms(500);
PORTD =0x01; //GreenLed
Count_10();
PORTD =0x00;
_delay_ms(500);
PORTD=0x02; //YellowLed
Count_3();
PORTD =0x00;
_delay_ms(500);
PORTD=0x04;//RedLed
Count_10();
PORTD =0x00;
_delay_ms(500);



}
return 0 ;
}

void Count_27(){

	int i = 0;
	int j = 0;

for( i = 0 ; i < 3 ;++i){

	PORTC = Arr[i];

for( j= 0 ; j<10;++j){

	PORTA = Arr[j];

	if ((PORTA == Arr[8]) && (PORTC == Arr[2])) break;
	_delay_ms(1000);
	}
PORTC=0x00;
PORTA=0x00;
	}
}

void Count_10(){

	int i = 0;
	int j = 0;

for( i = 0 ; i < 2 ;++i){

	PORTC = Arr[i];

for( j= 0 ; j<10;++j){

	PORTA = Arr[j];
	if ((PORTA == Arr[1]) && (PORTC == Arr[1])) break;
	_delay_ms(1000);
	}
PORTC=0x00;
PORTA=0x00;
	}
}

void Count_3(){

	int i = 0;
	int j = 0;

for( i = 0 ; i < 1 ;++i){

	PORTC = Arr[i];

for( j= 0 ; j<4;++j){

	PORTA = Arr[j];
	if ((PORTA == Arr[4]) && (PORTC == Arr[1])) break;
	_delay_ms(1000);
	}
PORTC=0x00;
PORTA=0x00;
	}
}
