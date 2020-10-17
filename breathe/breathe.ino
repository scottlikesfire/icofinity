 

#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    95
#define DELAY       50
#define PERIOD      0.5 //seconds
#define MAXINTENSITY   0.750

// Arduino script is for lighting a strip (or series of strips)
// in a way that makes the colors look like they are breathing
CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {

  float time = millis()/(PERIOD*1000); 
  float sint = (sin(time)+1.0)/2.0;

  int intense = round(255  * sint * MAXINTENSITY);
  int r = intense;
  int g = intense;
  int b = intense;

  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    // FastLED.show();
  }
  FastLED.show();
//  for(int i = 0; i < NUM_LEDS; i++)
//  {
//    leds[i] = CRGB(0, 0, 0);
//    FastLED.show();
//    delay(DELAY);
//  }
}
