#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    5
#define DELAY       50


//This program snakes a random color through the leds. it will sequentially
// light up the leds with a random color and then turn them off in the same order

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {

  int r = random(255);
  int g = random(255);
  int b = random(255);
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(DELAY);
  }
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
    delay(DELAY);
  }
}
