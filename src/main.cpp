#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <esp_sleep.h>

#define SENSOR 33
#define LED 26

#define DHTPIN SENSOR
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Mettez votre code de configuration ici, à exécuter une fois :
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();

  // Effectuer une mesure au début
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Afficher l'humidité 
  Serial.print("Humidite relative : ");
  Serial.print(humidity);
  Serial.println("%");

  // Afficher la température 
  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println("°C");

  // Mettre l'ESP32 en mode Deep sleep pendant 5 secondes
  esp_sleep_enable_timer_wakeup(5 * 1000000); // 5 seconds
  esp_deep_sleep_start();
}

void loop() {
}
