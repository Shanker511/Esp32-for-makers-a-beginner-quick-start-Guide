/*
  ESP32 for Makers
  Spicy Blink Test
  Written by Gareth Erwin
  Absolute Nerd Books

  This sketch makes the onboard LED blink with a little attitude.
  If your ESP32 board does not blink, try changing LED_PIN.
  Many ESP32 DevKit boards use GPIO 2 for the onboard LED.
*/

#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Three quick pulses
  blinkPulse(120);
  blinkPulse(120);
  blinkPulse(120);

  delay(400);

  // One longer pulse
  blinkPulse(600);

  delay(900);
}

void blinkPulse(int delayTime) {
  digitalWrite(LED_PIN, HIGH);
  delay(delayTime);

  digitalWrite(LED_PIN, LOW);
  delay(delayTime);
}
