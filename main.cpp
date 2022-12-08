#include "mbed.h"
#include "NeoStrip.h"
#include "gt.h"
#include "uLCD_4DGL.h"
#include "Motor.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

#define N 30
#define PATTERNS 2
#define STEPS 48 
#define NUM_SLICES 8


using namespace std;

// --------------------------------------
// FUNCTION DECLARATIONS
// --------------------------------------

int hueToRGB(float h);
void pattern0();
void pattern1();
void spin();
void spin_continuously(int final_dest);
void uLCD_print(string text, int new_state);

// Array to LED patterns
void (*patterns[])(void) = {&pattern0, &pattern1};


// --------------------------------------
// HARDWARE DECLARATIONS
// --------------------------------------

// LEDS
NeoStrip strip(p18, N);

// Brightness Up
DigitalIn b1(p20);

// Brightness Down 
DigitalIn b2(p19);

// Next Pattern
DigitalIn b3(p21);

// IR Sensor
DigitalIn big_butt(p14);

// Motor
Motor m(p24, p6, p5); // pwm, fwd, rev

// Motor Button
DigitalIn b4(p16); 

// uLCD Screen
uLCD_4DGL uLCD(p9, p10, p11);

// Debugging Timer
Timer timer;

// Teraterm
Serial pc(USBTX, USBRX);


// --------------------------------------
// GLOBAL VARIABLES
// --------------------------------------

// Current Position of Table
int table_pos = 0;

// Current Spining State of Table
bool spinning = false;

// Table Gift Count
int gift_count[NUM_SLICES];

// ???
bool curr_state = -1;




// --------------------------------------
// MAIN METHOD
// --------------------------------------
int main()
{
	b1.mode(PullUp);
	b2.mode(PullUp);
	b3.mode(PullUp);
    b4.mode(PullUp);
    big_butt.mode(PullUp);
    
	uLCD.text_width(2); 
    uLCD.text_height(2);      
    
    uLCD.locate(0,0);
    uLCD.printf("THE\nGIFTING\nTABLE");
    
	int pattern = 0;
	float bright = 0.5;	// 20% is plenty for indoor use
	bool b3o = b3;		// old copy of button 3 to poll for changes
	// button state
	bool big_butt_old = big_butt;

	strip.setBrightness(bright);	// set default brightness
    srand(time(0));
        
    
    // MAIN ACTION LOOP 
    while(1) {
		timer.reset(); 
		timer.start(); 
		
		// Increase Brightness
		if (b1 && bright < 1)
		{
			bright += 0.01;
			if (bright > 1)
				bright = 1;
			strip.setBrightness(bright);
		}
		
		// Decrease Brightness
		if (b2 && bright > 0)
		{
			bright -= 0.01;
			if (bright < 0)
				bright = 0;
			strip.setBrightness(bright);
		}
		
		// Changes the pattern, only do stuff when its state has changed
		if (b3 != b3o)
		{
			if (b3 && ++pattern == PATTERNS)
				pattern = 0;
			b3o = b3;
		}
		
		
		// State 0
		if (big_butt == big_butt_old) {
			uLCD_print("Welcome!\n1. Place a gift in the opening\n2. Press the button to spin for a new gift", 0);
		}
		
		// button 4 controls motor
        //myled = button;
        pc.printf("Button: %d", big_butt);
        if (big_butt != big_butt_old && !spinning) {
    			// State 3
	        	uLCD_print("Spinning...\nAre you ready for your gift?", 3);
	        	float low = 2;
	        	float high = 6;
	        	float spin_time = low + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(high-low)));
	            spinning = true;
	            pattern = 1;
	    		patterns[pattern]();
				strip.write();
		        m.speed(1.0);
		        wait(spin_time);
		        m.speed(0.0);
		        spinning = false;
		        pattern = 0;
	    		patterns[pattern]();
				strip.write();
        }
        
		// run the pattern update function which sets the strip's pixels
		patterns[pattern]();
		strip.write();

		timer.stop();
		// print loop time if b3 is pressed
		//if (b3)
		//	printf("Loop Time: %dus\n", timer.read_us());
		
		wait_ms(10);
    }
}


// --------------------------------------
// uLCD FUNCTIONS
// --------------------------------------
void uLCD_print(string text, int new_state) {
	if (curr_state != new_state) {
		curr_state = new_state;
		uLCD.text_width(1); 
	    uLCD.text_height(1);
		uLCD.filled_rectangle(0, 50, 127, 127, BLACK);
		uLCD.locate(0,10);
	    uLCD.printf(text.c_str());
	}
}


// --------------------------------------
// LED PATTERN FUNCTIONS
// --------------------------------------

void pattern0()
{
	static float dh = 360.0 / N;
	static float x = 0;

	for (int i = 0; i < N; i++)
		strip.setPixel(i, hueToRGB((dh * i) - x));
	
	x += 2;
	if (x > 360)
		x = 0;
}

// display a shifting gradient between red and blue
void pattern1()
{
	// offset for each pixel to allow the pattern to move
	static float x = 0;

	float r, b, y;

	for (int i = 0; i < N; i++)
	{
		// y is a scaled position between 0 (red) and 1.0 (blue)
		y = 1.0 * i / (N - 1) + x;
		if (y > 1)
			y -= 1;

		// if on the left half, red is decreasing and blue is increasng
		if (y < 0.5)
		{
			b = 2 * y;
			r = 1 - b;
		}

		// else red is increasing and blue is decreasing
		else
		{
			r = 2 * (y - 0.5);
			b = 1 - r;
		}

		// scale to integers and set the pixel
		strip.setPixel(i, (uint8_t)(r * 255), 0, (uint8_t)(b * 200));
	}

	x += 0.006;
	if (x > 1)
		x = 0;
}


// Converts HSV to RGB with the given hue, assuming
// maximum saturation and value
int hueToRGB(float h)
{
	// lots of floating point magic from the internet and scratching my head
	float r, g, b;
	if (h > 360)
		h -= 360;
	if (h < 0)
		h += 360;
	int i = (int)(h / 60.0);
	float f = (h / 60.0) - i;
	float q = 1 - f;
	
	switch (i % 6)
	{
		case 0: r = 1; g = f; b = 0; break;
		case 1: r = q; g = 1; b = 0; break;
		case 2: r = 0; g = 1; b = f; break;
		case 3: r = 0; g = q; b = 1; break;
		case 4: r = f; g = 0; b = 1; break;
		case 5: r = 1; g = 0; b = q; break;
		default: r = 0; g = 0; b = 0; break;
	}
	
	// scale to integers and return the packed value
	uint8_t R = (uint8_t)(r * 255);
	uint8_t G = (uint8_t)(g * 255);
	uint8_t B = (uint8_t)(b * 255);

	return (R << 16) | (G << 8) | B;
}