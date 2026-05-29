/*
  ESP32 Button Test
  Written by Gareth Erwin
  Absolute Nerd Books

  Press the button to print a message in the Serial Monitor.
*/

#define BUTTON_PIN 4

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    Serial.println("Button pressed!");
    delay(250);
  }
}
