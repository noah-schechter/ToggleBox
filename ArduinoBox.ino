#include <Keyboard.h>


char commandKey = KEY_LEFT_GUI;

// Initialize variables
// These refer to the respective pins
const int buttonPin2 = 2;     
const int buttonPin3 =  3;      
const int buttonPin4 = 4;

// These record the state of the pins
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;
int buttonState4 = 0;


// These record whether the switch is on or off (0 is down, 1 is up) This solves for the fact that we use toggle switches instead of momentary switches
int copyState = 0;
int pasteState = 0;
int grayState = 0;


void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // check if the pushbutton is newly pressed. If it is, the buttonState is LOW and the other state is 0
  if (buttonState2 == LOW && copyState == 0) {
    // Copy
    Keyboard.begin();
    Keyboard.press(commandKey);
    Keyboard.press('c');
    Keyboard.releaseAll();
    Keyboard.end();
    copyState = 1;
  } 
  if (buttonState3 == LOW && pasteState == 0) {
    //Paste
    Keyboard.begin();
    Keyboard.press(commandKey); 
    Keyboard.press('v');
    Keyboard.releaseAll();
    Keyboard.end();
    pasteState = 1;
  }
  if (buttonState4 == LOW && grayState == 0) {
    // grayscale 
    Keyboard.begin();
    Keyboard.press(commandKey);
    Keyboard.press('g');
    Keyboard.releaseAll();
    Keyboard.end();
    grayState = 1;
  }
  delay(100); // Not sure why this is necessary but they seem to freak out if this isn't here

  // Update toggle switch states (If the switches are back off but the state reflects that they're on)
  if (buttonState2 == HIGH && copyState == 1) {
    copyState = 0;
  }
  if (buttonState3 == HIGH && pasteState == 1) {
    pasteState = 0;
  }
  if (buttonState4 == HIGH && grayState == 1) {
    grayState = 0;
  }
}