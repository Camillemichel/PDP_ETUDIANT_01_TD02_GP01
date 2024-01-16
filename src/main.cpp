#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SENSOR 33
#define LED 26

#define DHTPIN SENSOR
#define DHTTYPE DHT11 // Remplacez par le type de votre capteur (DHT11, DHT21, DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Mettez votre code de configuration ici, à exécuter une fois :
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(5000);

  // Mesurer l'humidité relative et la température
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Afficher l'humidité relative avec un peu de formatage
  Serial.print("Humidite relative : ");
  Serial.print(humidity);
  Serial.println("%");

  // Afficher la température avec un peu de formatage
  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println("°C");
}

