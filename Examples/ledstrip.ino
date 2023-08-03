#include <ledstrip.h>

int pins[5] = {10, 9, 3, 5, 6};

ledstrip leds(pins, 5, false, true);

void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int i = 0; i <= 255; i++) {
    int clr[2] = {255, i};
    leds.setLedState(clr, 0);
    delay(5);
  }
  leds.resetLeds();
  for(int i = 0; i <= 255; i++) {
    int clr[2] = {255, i};
    leds.setLedState(clr, 1);
    delay(5);
  }
  leds.resetLeds();
  
  for(int i = 0; i <= 255; i++) {
    int clr[2] = {255, i};
    leds.setLedState(clr, 2);
    delay(5);
  }
  leds.resetLeds();
  for(int i = 0; i <= 255; i++) {
    int clr[2] = {255, i};
    leds.setLedState(clr, 3);
    delay(5);
  }
  leds.resetLeds();
  for(int i = 0; i <= 255; i++) {
    int clr[2] = {255, i};
    leds.setLedState(clr, 4);
    delay(5);
  }
  leds.resetLeds();
}

