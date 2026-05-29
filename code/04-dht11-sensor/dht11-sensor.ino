/*
  ESP32 DHT11 Sensor Test
  Written by Gareth Erwin
  Absolute Nerd Books

  Reads temperature and humidity from a DHT11 sensor.
*/

#include <DHT.h>

#define DHT_PIN 18
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("DHT11 sensor starting...");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true);

  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Sensor read failed.");
    delay(2000);
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  ");

  Serial.print("Temp: ");
  Serial.print(temperatureF);
  Serial.println(" F");

  delay(2000);
}
