/*
 * main.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Ahmed Nageeb
 *
 *  Description:
 *  This program simulates a traffic light system using an AVR microcontroller.
 *  The system controls three lights (Red, Yellow, Green) and displays a countdown
 *  on two seven-segment displays for each light.
 */

#include <avr/io.h>
#include <util/delay.h>
#include "STD_Types.h"

#define F_CPU 8000000UL // Define CPU clock frequency as 8 MHz

// Define the binary representations of digits 0-9 for a seven-segment display
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

// Define constants to represent the traffic light colors
#define RED 1
#define YELLOW 2
#define GREEN 4

#define DELAY_MS 1000 // Define the delay in milliseconds for the countdown

// Array holding the binary representations for digits 0-9
u8 SSDArr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

// Function prototypes
void RedActive(void);
void YellowActive(void);
void GreenActive(void);
void CountDown(s8 Tens, s8 Ones, s8 LED);

int main(int argc, char **argv)
{
    // Set ports B, A, and C as output
    DDRB = 0xff; // Set all pins on PORTB to output (controls LEDs)
    DDRA = 0xff; // Set all pins on PORTA to output (controls first 7-segment)
    DDRC = 0xff; // Set all pins on PORTC to output (controls second 7-segment)

    // Infinite loop to continuously cycle through traffic light states
    while (1)
    {
        RedActive();    // Activate red light and start countdown
        YellowActive(); // Activate yellow light and start countdown
        GreenActive();  // Activate green light and start countdown
    }
}

// Function to activate the red light and start a 10-second countdown
void RedActive(void)
{
    CountDown(1, 0, RED); // Call CountDown with 10 seconds and RED light
}

// Function to activate the yellow light and start a 3-second countdown
void YellowActive(void)
{
	CountDown(0, 3, YELLOW); // Call CountDown with 3 seconds and YELLOW light
}

// Function to activate the green light and start a 10-second countdown
void GreenActive(void)
{
	CountDown(1, 0, GREEN); // Call CountDown with 10 seconds and GREEN light
}

// Function to handle the countdown logic
void CountDown(s8 Tens, s8 Ones, s8 LED)
{
    // Set the appropriate LED light based on the input parameter
    switch (LED)
    {
    case RED:
        PORTB = 1; // Turn on RED light
        break;
    case YELLOW:
        PORTB = 2; // Turn on YELLOW light
        break;
    case GREEN:
        PORTB = 4; // Turn on GREEN light
        break;
    default:
        break;
    }

    // Loop until the countdown reaches -1 on the Tens digit
    while (Tens != -1)
    {
        PORTA = ~SSDArr[Ones]; // Display Ones digit on first 7-segment
        PORTC = ~SSDArr[Tens]; // Display Tens digit on second 7-segment

        // Check if the Ones digit is 0
        if (Ones == 0)
        {
            Ones = 10; // Reset Ones to 10 (which becomes 9 after decrement)
            Tens--;    // Decrement the Tens digit
        }

        _delay_ms(DELAY_MS); // Delay for 1 second

        PORTC = ~SSDArr[Tens]; // Refresh the Tens digit display
        Ones--;                // Decrement the Ones digit

        // Turn off the LED when countdown reaches 00
        if ((Ones == 0) && (Tens == 0))
        {
            PORTB = 0; // Turn off the LED light
        }
    }
}
