/*
  ESP32 Button Logic
  Written by Gareth Erwin
  Absolute Nerd Books

  Reads a push button on GPIO 4 and toggles an LED on GPIO 2.
*/

#define BUTTON_PIN 4
#define LED_PIN 2

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

  Serial.println("Button logic ready.");
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    Serial.print("LED is now: ");
    Serial.println(ledState ? "ON" : "OFF");

    delay(250);
  }

  lastButtonState = buttonState;
}
