#ifndef _LCD_H_
#define	_LCD_H_

#include "Includes.h"

// This is the PIC to LCD pin mapping
#define LCD_RS LATB2
#define LCD_EN LATB5
#define LCD_D4 LATD4
#define LCD_D5 LATD5
#define LCD_D6 LATD6
#define LCD_D7 LATD7

// Pulse time for the E pin.
#define LCD_PULSE 30

// Predefined set of characters.
#define N_PRED 37
volatile char PREDEFINED[] = " abcdefghijklmnopqrstuvwxyz0123456789";

// A custom character is defined as an array of 8 bytes.
// Each bytes' least significant 5 bits are used to draw
// custom characters to the LCD.
// Example custom character definition.
uint8_t fullHeart[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

// Implementation of below functions are provided in lcd.c

// Pulse the E pin of the LCD.
void Pulse(void);
// Properly initialize the LCD.
void InitLCD(void);
// Create a custom character and store it in the LCD's memory.
// First argument is the address to store the character. It can
// take values between 0 and 7 (for 8 custom characters). Second
// argument is the character data. See the fullHeart array above.
// When you send the address as 'data' to the LCD, the custom
// character stored at that address is displayed.
void CreateChar(uint8_t address, uint8_t* charmap);

// Take a look at the functions below. They might give you
// some ideas on how to design your program. Again, you DON'T
// HAVE TO implement these functions. You can create your own
// functions if you want. You can also comment out or delete these
// functions.
//
void LcdCmd(uint8_t cmd);
void LcdData(uint8_t data);
// void LcdStr(char* buf);
void LcdClear();
// void LcdMove(int row, int col);


#endif	/* _LCD_H_ */
