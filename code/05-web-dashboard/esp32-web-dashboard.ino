/*
  ESP32 Maker Dashboard
  Written by Gareth Erwin
  Absolute Nerd Books

  Features:
  - DHT11 temperature and humidity
  - Button input
  - LED control
  - Local web dashboard
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"

#define LED_PIN 2
#define BUTTON_PIN 4
#define DHT_PIN 18
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
WebServer server(80);

bool ledState = false;

String htmlPage() {
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  bool buttonPressed = digitalRead(BUTTON_PIN) == LOW;

  if (isnan(h) || isnan(f)) {
    h = 0;
    f = 0;
  }

  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Maker Dashboard</title>
<style>
body {
  margin: 0;
  font-family: Arial, sans-serif;
  background: radial-gradient(circle at top, #143d2a, #050807 70%);
  color: #d8ffe5;
}
.wrap {
  max-width: 760px;
  margin: auto;
  padding: 28px;
}
.card {
  background: rgba(0,0,0,.62);
  border: 1px solid #39ff88;
  box-shadow: 0 0 22px rgba(57,255,136,.25);
  border-radius: 18px;
  padding: 22px;
  margin-bottom: 18px;
}
h1 {
  color: #39ff88;
  text-transform: uppercase;
  letter-spacing: 2px;
}
.grid {
  display: grid;
  grid-template-columns: repeat(2, 1fr);
  gap: 14px;
}
.stat {
  background: #07110c;
  border: 1px solid #1f8f54;
  border-radius: 14px;
  padding: 18px;
}
.label {
  font-size: 12px;
  color: #87d9a6;
  text-transform: uppercase;
}
.value {
  font-size: 32px;
  font-weight: bold;
}
button {
  background: #39ff88;
  color: #041007;
  border: none;
  padding: 14px 20px;
  margin: 6px;
  border-radius: 10px;
  font-weight: bold;
  cursor: pointer;
}
button.off {
  background: #ff3864;
}
.footer {
  color: #82b895;
  font-size: 12px;
}
</style>
</head>
<body>
<div class="wrap">
  <div class="card">
    <h1>ESP32 Maker Dashboard</h1>
    <p>Local control node online. Tiny silicon gremlin reporting for duty.</p>
  </div>

  <div class="grid">
    <div class="stat">
      <div class="label">Temperature</div>
      <div class="value">)rawliteral";

  page += String(f, 1);
  page += R"rawliteral( F</div>
    </div>

    <div class="stat">
      <div class="label">Humidity</div>
      <div class="value">)rawliteral";

  page += String(h, 1);
  page += R"rawliteral( %</div>
    </div>

    <div class="stat">
      <div class="label">LED State</div>
      <div class="value">)rawliteral";

  page += ledState ? "ON" : "OFF";
  page += R"rawliteral(</div>
    </div>

    <div class="stat">
      <div class="label">Button</div>
      <div class="value">)rawliteral";

  page += buttonPressed ? "PRESSED" : "READY";
  page += R"rawliteral(</div>
    </div>
  </div>

  <div class="card">
    <a href="/on"><button>LED ON</button></a>
    <a href="/off"><button class="off">LED OFF</button></a>
    <a href="/"><button>REFRESH</button></a>
  </div>

  <div class="footer">
    Written by Gareth Erwin | Absolute Nerd Books
  </div>
</div>
</body>
</html>
)rawliteral";

  return page;
}

void handleRoot() {
  server.send(200, "text/html", htmlPage());
}

void handleLedOn() {
  ledState = true;
  digitalWrite(LED_PIN, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  ledState = false;
  digitalWrite(LED_PIN, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Dashboard IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleLedOn);
  server.on("/off", handleLedOff);

  server.begin();
}

void loop() {
  server.handleClient();

  if (digitalRead(BUTTON_PIN) == LOW) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(300);
  }
}
