#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define MODULES_WIDE 1
#define MODULES_HIGH 2
#define WIDTH 8*MODULES_WIDE
#define HEIGHT 8*MODULES_HIGH
#define NUMPIXELS WIDTH*HEIGHT

const int neoPixelPin = 15; // control pin
unsigned int hue[NUMPIXELS] = {0};

// set up matrix:
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(WIDTH, HEIGHT, neoPixelPin,
											   NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
											   NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
											   NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
	matrix.begin(); // initialize pixel strip
	matrix.setBrightness(10);
	matrix.clear(); // clear pixels
	for (int thisPixel = 0; thisPixel < NUMPIXELS; thisPixel++)
		{
      hue[thisPixel] = thisPixel * 100;
			matrix.setPixelColor(thisPixel, matrix.ColorHSV(hue[thisPixel]));
		}

	matrix.show();	// refresh the strip
}

void loop()
{
	for (int thisPixel = 0; thisPixel < NUMPIXELS; thisPixel++)
		{
			matrix.setPixelColor(thisPixel, matrix.ColorHSV(hue[thisPixel]));
      hue[thisPixel] = hue[thisPixel] + 50;
		}
    matrix.show();
    //delay(1);
}