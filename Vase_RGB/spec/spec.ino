#include <PololuLedStrip.h>
PololuLedStrip<4> LEDS;
#define LED_COUNT 16
rgb_color colors[LED_COUNT];
void on(int r, int g, int b, int led = -1) {
  //off();
  if (led == -1) {
    for (int i = 0; i < LED_COUNT; i++) {
      colors[i] = rgb_color(r, g, b);
    }
  } else {
    colors[led] = rgb_color(r, g, b);
  }
  LEDS.write(colors, LED_COUNT);
}
void setup() {
  Serial.begin(9600);
  maman();
}

void loop() {
}
