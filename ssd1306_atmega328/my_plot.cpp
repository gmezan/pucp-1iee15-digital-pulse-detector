/*
 * my_plot.cpp
 *
 * Created: 20/05/2019 11:49:06
 *  Author: GUSTAVO
 */ 

#include "my_plot.h"


my_plot::my_plot(){
}

void my_plot::drawNoSignal()
{
	
}

//BPM:
void my_plot::setBPM(uint8_t n){
	
	
	if (n>=100)
	{
		this->buffer[0] |= 0b11111000; // es al reves
		this->buffer[128] |= 0b11111111;
		this->buffer[256] |= 0b00000001;
		this->buffer[1] |= 0b11111000;
		this->buffer[129] |= 0b11111111;
		this->buffer[257] |= 0b00000001;
	}
	
	this->drawNumber(n/60, 70);
	this->drawNumber((n/6)%10, 86);
	this->drawNumber(((n*10)/6)%10, 98); 
	
	n = n%100;
	this->drawNumber(n/10, 0);
	this->drawNumber(n%10, 12);
}

void my_plot::plotg(uint8_t n, uint8_t i)
{
	n = 39 - n%40;
	
	this->buffer[128*(3 + n/8) + i] =  1<<(n%8);
}

void my_plot::clearPlot()
{
	for (uint8_t i = 0; i<128; i++)
	{
		this->buffer[128*3 + i] =  0x00;
		this->buffer[128*4 + i] =  0x00;
		this->buffer[128*5 + i] =  0x00;
		this->buffer[128*6 + i] =  0x00;
		this->buffer[128*7 + i] =  0x00;
	}
	
}

void my_plot::drawNumber(uint8_t temp, uint8_t x)
{
	switch(temp)
	{
		case 1: //done case 1
		this->buffer[12+x] |= 0b11111000;
		this->buffer[140+x] |= 0b11111111;
		this->buffer[268+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000; // done
		this->buffer[141+x] |= 0b11111111; //done
		this->buffer[269+x] |= 0b00000001;
		break;
		
		case 2: // done case 2
		this->buffer[5+x] |= 0b00010000; // done
		this->buffer[128*1+5+x] |= 0b11111100; //done

		this->buffer[6+x] |= 0b00011000;
		this->buffer[134+x] |= 0b11111110;
		this->buffer[262+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[135+x] |= 0b10000110;
		this->buffer[263+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[136+x] |= 0b10000110;
		this->buffer[264+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[137+x] |= 0b10000110;
		this->buffer[265+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[138+x] |= 0b10000110;
		this->buffer[266+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[139+x] |= 0b10000110;
		this->buffer[267+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[140+x] |= 0b10000110;
		this->buffer[268+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[141+x] |= 0b10000111;
		this->buffer[269+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11110000; // done
		this->buffer[270+x] |= 0b10000111; //done
		break;
		
		case 3: // done case 3
		this->buffer[5+x] |= 0b00010000; // done
		this->buffer[133+x] |= 0b10000000; //done
		
		this->buffer[6+x] |= 0b00011000;
		this->buffer[134+x] |= 0b10000110;
		this->buffer[262+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[135+x] |= 0b10000110;
		this->buffer[263+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[136+x] |= 0b10000110;
		this->buffer[264+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[137+x] |= 0b10000110;
		this->buffer[265+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[138+x] |= 0b10000110;
		this->buffer[266+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[139+x] |= 0b10000110;
		this->buffer[128*2 +11+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[128*1 +12+x] |= 0b10000110;
		this->buffer[128*2 +12+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[128*1 +13+x] |= 0b11111111;
		this->buffer[128*2 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11110000; // done
		this->buffer[128*1 +14+x] |= 0b11111111; //done
		break;
		
		case 4:
		this->buffer[5+x] |= 0b11111000; // done
		this->buffer[128*1+5+x] |= 0b00000111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[128*1 +6+x] |= 0b00000111;
		
		this->buffer[135+x] |= 0b00000110;

		this->buffer[136+x] |= 0b00000110;
		
		this->buffer[137+x] |= 0b00000110;
		
		this->buffer[138+x] |= 0b00000110;
		
		this->buffer[139+x] |= 0b00000110;
		
		this->buffer[140+x] |= 0b00000110;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[141+x] |= 0b11111111;
		this->buffer[269+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11111000; // done
		this->buffer[142+x] |= 0b11111111; //done
		this->buffer[270+x] |= 0b00000001;
		break;
		
		case 5: // case 5 done
		this->buffer[5+x] |= 0b11110000; // done
		this->buffer[133+x] |= 0b10000111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[134+x] |= 0b10000111;
		this->buffer[128*2 +6+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[128*1 +7+x] |= 0b10000110;
		this->buffer[128*2 +7+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[128*1 +8+x] |= 0b10000110;
		this->buffer[128*2 +8+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[128*1 +9+x] |= 0b10000110;
		this->buffer[128*2 +9+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[128*1 +10+x] |= 0b10000110;
		this->buffer[128*2 +10+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[128*1 +11+x] |= 0b10000110;
		this->buffer[128*2 +11+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[128*1 +12+x] |= 0b10000110;
		this->buffer[128*2 +12+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b00011000;
		this->buffer[128*1 +13+x] |= 0b11111110;
		this->buffer[128*2 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b00010000; // done
		this->buffer[128*1 +14+x] |= 0b11111100; //done
		
		break;
		
		case 6: //case 6 done
		this->buffer[5+x] |= 0b11110000; // done
		this->buffer[128*1+5+x] |= 0b11111111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[128*1 +6+x] |= 0b11111111;
		this->buffer[128*2 +6+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[128*1 +7+x] |= 0b10000110;
		this->buffer[128*2 +7+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[128*1 +8+x] |= 0b10000110;
		this->buffer[128*2 +8+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[128*1 +9+x] |= 0b10000110;
		this->buffer[128*2 +9+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[138+x] |= 0b10000110;
		this->buffer[266+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[139+x] |= 0b10000110;
		this->buffer[267+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[140+x] |= 0b10000110;
		this->buffer[256 +12+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b00011000;
		this->buffer[141+x] |= 0b11111110;
		this->buffer[256 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b00010000; // done
		this->buffer[128 +14+x] |= 0b11111100; //done
		
		break;
		
		case 7: // done case 7
		this->buffer[5+x] |= 0b00011000; // done

		this->buffer[6+x] |= 0b00011000;
		
		this->buffer[7+x] |= 0b00011000;
		
		this->buffer[8+x] |= 0b00011000;
		
		this->buffer[9+x] |= 0b00011000;
		
		this->buffer[10+x] |= 0b00011000;
		
		this->buffer[11+x] |= 0b00011000;
		
		this->buffer[12+x] |= 0b00011000;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[141+x] |= 0b11111111;
		this->buffer[128*2 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11111000; // done
		this->buffer[142+x] |= 0b11111111; //done
		this->buffer[128*2 +14+x] |= 0b00000001;
		break;
		
		case 8:// done case 8
		this->buffer[5+x] |= 0b11110000; // done
		this->buffer[133+x] |= 0b11111111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[134+x] |= 0b11111111;
		this->buffer[128*2 +6+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[135+x] |= 0b10000110;
		this->buffer[128*2 +7+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[136+x] |= 0b10000110;
		this->buffer[128*2 +8+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[137+x] |= 0b10000110;
		this->buffer[128*2 +9+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[128 +10+x] |= 0b10000110;
		this->buffer[128*2 +10+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[128 +11+x] |= 0b10000110;
		this->buffer[128*2 +11+x] |= 0b00000001;
	
		this->buffer[12+x] |= 0b00011000;
		this->buffer[128 +12+x] |= 0b10000110;
		this->buffer[128*2 +12+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[128 +13+x] |= 0b11111111;
		this->buffer[128*2 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11110000; // done
		this->buffer[128 +14+x] |= 0b11111111; //done
		break;
		
		case 9: //done case 9
		this->buffer[5+x] |= 0b11110000; // done
		this->buffer[128*1+5+x] |= 0b10000111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[128*1 +6+x] |= 0b10000111;
		this->buffer[128*2 +6+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[128 +7+x] |= 0b10000110;
		this->buffer[128*2 +7+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[128 +8+x] |= 0b10000110;
		this->buffer[264+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[137+x] |= 0b10000110;
		this->buffer[265+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[138+x] |= 0b10000110;
		this->buffer[266+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[139+x] |= 0b10000110;
		this->buffer[267+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[140+x] |= 0b10000110;
		this->buffer[268+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[141+x] |= 0b11111111;
		this->buffer[269+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11110000; // done
		this->buffer[142+x] |= 0b11111111; //done
		break;
		
		case 0:// case 0 done
		this->buffer[5+x] |= 0b11110000; // done
		this->buffer[133+x] |= 0b11111111; //done
		
		this->buffer[6+x] |= 0b11111000;
		this->buffer[134+x] |= 0b11111111;
		this->buffer[262+x] |= 0b00000001;
		
		this->buffer[7+x] |= 0b00011000;
		this->buffer[135+x] |= 0b10000000;
		this->buffer[263+x] |= 0b00000001;
		
		this->buffer[8+x] |= 0b00011000;
		this->buffer[136+x] |= 0b10000000;
		this->buffer[264+x] |= 0b00000001;
		
		this->buffer[9+x] |= 0b00011000;
		this->buffer[137+x] |= 0b10000000;
		this->buffer[265+x] |= 0b00000001;
		
		this->buffer[10+x] |= 0b00011000;
		this->buffer[138+x] |= 0b10000000;
		this->buffer[266+x] |= 0b00000001;
		
		this->buffer[11+x] |= 0b00011000;
		this->buffer[139+x] |= 0b10000000;
		this->buffer[256 +11+x] |= 0b00000001;
		
		this->buffer[12+x] |= 0b00011000;
		this->buffer[140+x] |= 0b10000000;
		this->buffer[256 +12+x] |= 0b00000001;
		
		this->buffer[13+x] |= 0b11111000;
		this->buffer[141+x] |= 0b11111111;
		this->buffer[128*2 +13+x] |= 0b00000001;
		
		this->buffer[14+x] |= 0b11110000; // done
		this->buffer[142+x] |= 0b11111111; //done
		
		break;
	}
	
}