// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
const int buttonrechts = 2;     // the number of the pushbutton pin
const int buttonlinks = 3;     // the number of the pushbutton pin

int buttonStateRe = 0;  
int buttonStateLi = 0;  


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    // initialize the pushbutton pin as an input:
  pinMode(buttonrechts, INPUT);
  pinMode(buttonlinks, INPUT);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // read the state of the pushbutton value:
  buttonStateRe = digitalRead(buttonrechts);
  buttonStateLi = digitalRead(buttonlinks);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateRe == HIGH) {
    // turn LED on:
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 80, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  }  
  if (buttonStateRe == LOW) {
    // turn LED off:
  pixels.clear(); // Set all pixel colors to 'off'
  }
  
 
 if (buttonStateLi == HIGH) {
    // turn LED on:
  for(int i=8; i>=0; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 80, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  } 
 }
  if (buttonStateLi == LOW) {
    // turn LED off:
  pixels.clear(); // Set all pixel colors to 'off'
  }
 }



  
