#include <Adafruit_NeoPixel.h>

#define PIN 6            // Define the pin connected to the data pin of the Neopixel strip
#define NUMPIXELS 30     // Define the number of LEDs in the strip

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    colorWipe(strip.Color(255, 0, 0), 15); // Red light moving forward
    colorWipe(strip.Color(0, 0, 0), 15);  // Red light turning off
    colorWipe(strip.Color(0, 255, 0), 15); // Green light moving forward
    colorWipe(strip.Color(0, 0, 0), 15);  // Green light turning off
    colorWipe(strip.Color(0, 0, 255), 15); // Blue light moving forward
    colorWipe(strip.Color(0, 0, 0), 15);  // Blue light turning off
}

void colorWipe(uint32_t color, int wait) {
    for(int i = 0; i < NUMPIXELS; i++) {
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
    }
}
