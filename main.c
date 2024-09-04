/*
 * main.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Ahmed Nageeb
 */

#include <avr/io.h>
#include <util/delay.h>
#include "STD_Types.h"
#define F_CPU 8000000UL // F is 8MHz
void RedActive(void);
void YellowActive(void);
void GreenActive(void);
void CountDown(s8 Tens, s8 Ones, s8 LED);

#define ZERO 0b00111111  // 0
#define ONE 0b00000110   // 1
#define TWO 0b01011011   // 2
#define THREE 0b01001111 // 3
#define FOUR 0b01100110  // 4
#define FIVE 0b01101101  // 5
#define SIX 0b01111101   // 6
#define SEVEN 0b00000111 // 7
#define EIGHT 0b01111111 // 8
#define NINE 0b01101111  // 9

#define RED 1
#define YELLOW 2
#define GREEN 4

#define DELAY_MS 1000
u8 SSDArr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

int main(int argc, char **argv)
{

    DDRB = 0xff;
    DDRA = 0xff;
    DDRC = 0xff;

    while (1)
    {
        RedActive();
        YellowActive();
        GreenActive();
    }
}
void RedActive(void)
{
    CountDown(1, 0, RED);
}
void YellowActive(void)
{
	CountDown(0, 3, YELLOW);
}
void GreenActive(void)
{
	CountDown(1, 0, GREEN);
}

void CountDown(s8 Tens, s8 Ones, s8 LED)
{
    switch (LED)
    {
    case RED:
        PORTB = 1;
        break;
    case YELLOW:
        PORTB = 2;
        break;
    case GREEN:
        PORTB = 4;
        break;

    default:
        break;
    }
    while (Tens != -1) // Loop until Tens digit is -1
    {

        PORTA = ~SSDArr[Ones]; // Display Ones digit on first 7-segment
        PORTC = ~SSDArr[Tens]; // Display Ones digit on first 7-segment

        // Decrement Tens digit if Ones digit reaches 0
        if (0 == Ones)
        {
            Ones = 10; // Reset Ones to 10 (which will become 9 after decrement)
            Tens--;    // Decrement Tens digit
        }
        _delay_ms(DELAY_MS);   // Delay
        PORTC = ~SSDArr[Tens]; // Display Tens digit on second 7-segment
        Ones--;                // Decrement Ones digit

        // If countdown reaches 0-0, call flash function
        if ((Ones == 0) && (Tens == 0))
        {
            PORTB = 0;
        }
    }
}
