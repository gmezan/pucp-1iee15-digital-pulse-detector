/*
 * my_plot.h
 *
 * Created: 20/05/2019 11:49:28
 *  Author: GUSTAVO
 */ 


//#ifndef MY_PLOT_H_
//#define MY_PLOT_H_

#include<stdint.h>
#include "Framebuffer.h"

class my_plot: public Framebuffer{
	
	public:
		my_plot();
		void drawNoSignal();
		void setBPM(uint8_t);

		uint8_t graph[5]; // ={ 0b0000.0000, 0b0000.0000, 0b0000.0000, 0b0000.0000, 0b0000.0000}  
		void plotg(uint8_t n, uint8_t i);
		void clearPlot();
		
	private:
		void drawNumber(uint8_t, uint8_t);
		
		
	};

//#endif /* MY_PLOT_H_ */