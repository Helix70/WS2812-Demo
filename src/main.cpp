#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

const int neoPixelPin = 15; // control pin
const int numPixels = 64;	// number of pixels
unsigned int hue[64] = {0};

// set up matrix:
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, neoPixelPin,
											   NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
											   NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
											   NEO_GRB + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
	matrix.begin(); // initialize pixel strip
	matrix.setBrightness(10);
	matrix.clear(); // clear pixels
	for (int thisPixel = 0; thisPixel < numPixels; thisPixel++)
		{
      hue[thisPixel] = thisPixel * 100;
			matrix.setPixelColor(thisPixel, matrix.ColorHSV(hue[thisPixel]));
		}

	matrix.show();	// refresh the strip
}

void loop()
{
	for (int thisPixel = 0; thisPixel < numPixels; thisPixel++)
		{
			matrix.setPixelColor(thisPixel, matrix.ColorHSV(hue[thisPixel]));
      hue[thisPixel] = hue[thisPixel] + 50;
		}
    matrix.show();
    delay(1);
}