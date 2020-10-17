#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    90
#define DELAY       35
#define MAXINTENSITY   1.0

//This program snakes a random color through the leds. it will sequentially
// light up the leds with a random color and then turn them off in the same order

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {

  int maxi = round(255  *  MAXINTENSITY);
  int r = random(maxi);
  int g = random(maxi);
  int b = random(maxi);
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(DELAY);
  }
//  for(int i = 0; i < NUM_LEDS; i++)
//  {
//    leds[i] = CRGB(0, 0, 0);
//    FastLED.show();
//    delay(DELAY);
//  }
}
