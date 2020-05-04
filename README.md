# Pulse Detector for heart rate measurement
Oscilloscope with a pulse detector menu (max 120 Hz). Project was developed using the ATmega328p microcontroller (the same that is used in Arduino) and the C++ language.  It is configured to be displayed in a SSD1306 LED display.

### Analog electronic design
Circuits, filters and amplifiers. Proteus implementation.
1. Buffer
2. Highpass filter 1
3. Highpass filter 2
4. Buffer
5. Lowpass filter

![schematic](https://github.com/gmn14/PulseDetector/blob/master/schematic.png?raw=true)


### Breadboard implementation
Circuit implementation on breadboard

<img src="/breadbord.png" width="300">


### Testing on oscilloscope
Now the heart signal is visible

<img src="/oscilloscope.png" width="300" height="300">

### Board design
The PCB was designed using Eagle 

<img src="/board.png" width="500" height="350">


### PCB implementation
Final implementation, using a LED display.
C++ code for the atmega328p can be found on the Atmel Studio Project `ssd1306_atmega328`.
Video with the results: https://github.com/gmn14/PulseDetector/blob/master/video.MP4

<img src="/Screen Shot 2020-05-04 at 12.28.10.png" width="500" height="350">

