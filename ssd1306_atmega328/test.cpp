/*
 * ssd1306_atmega328.cpp
 *
 * Created: 16/04/2019 13:08:11
 * Author : GUSTAVO
 */ 
/*
#define F_CPU 16000000UL

#include <avr/io.h>

#include <stdint.h>
#include "SSD1306.h"

int main(void) {
	// This is our buffer
	// Each byte = 8 pixels on the screen
	uint8_t buffer[1024];

	int size = sizeof(buffer)/sizeof(buffer[0]);
	
	// uint8_t column = i%128;
	// uint8_t row = 8*(i/128) ;  row = 0bxxxxxxxx ; 
	
	
	for(int i = 0; i < size; i++)
	{
		
		if ((i%128 == 0) || (i%128 == 20) || (i%128 == 30) || (i%128 == 50) || (i%128 == 60)|| (i%128 == 90) || (i%128 == 110) )
		{
			buffer[i] = 255;
		}
		else if (((i%128 <=50) && (i%128 >=30)) && ( (i/128 == 0) || ((i/128) == 7) ))
		{
			if (i/128 == 0) buffer[i] = 0b00000001;
			else buffer[i] = 0b10000000;
		}
		else if ((i%128 <=20) &&  (i/128 == 3) )
		{
			buffer[i] = 0b10000000;
		}
		else if (((i%128 <=80) && (i%128 >=60)) && ((i/128) == 7))
		{
			buffer[i] = 0b10000000;
		}
		else if (((i%128 <=110) && (i%128 >=90)) && ( (i/128 == 0) || ((i/128) == 3) ))
		{
			if (i/128 == 0) buffer[i] = 0b00000001;
			else buffer[i] = 0b10000000;
		}
		else 
		{
			buffer[i] = 0;
		}
		
	}
	// Only two lines of code to initiate the driver
	// and to send our framebuffer
	SSD1306 myDisplay;
	myDisplay.sendFramebuffer(buffer);

	// Hardware function to reverse the pixels
	// (swap black and white pixel)
	myDisplay.invert(1);
	// Revert back to normal display
	myDisplay.invert(0);

	return 0;
}


*/