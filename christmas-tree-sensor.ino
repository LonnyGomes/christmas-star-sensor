#include <Adafruit_NeoPixel.h>

#define LED_PIN   10
#define LED_COUNT 7

// Declare our NeoPixel strip object:
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

int analogPin = A0;

int val = 0;

uint32_t hydratedClr = pixels.Color(127, 0, 0, 255);
uint32_t dryClr = pixels.Color(255, 0, 0, 0);
uint32_t curClr;

void setup() {
  Serial.begin(9600);           //  setup serial
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(200);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value

  if (val <= 200) {
    curClr = dryClr;
  } else {
    curClr = hydratedClr;
  }

  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  // Here we're using a moderately bright green color:
  for(int i=0; i< LED_COUNT; i++) {
    pixels.setPixelColor(i, curClr);
  }

  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1000); 
}
