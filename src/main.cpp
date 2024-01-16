#include <Adafruit_Sensor.h>
#include <DHT.h>

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
}

void loop() {
  // Effectuer une mesure toutes les 5s
  delay(5000);

  // Mesurer l'humidité et la température
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Afficher l'humidité 
  Serial.print("Humidite : ");
  Serial.print(humidity);
  Serial.println("%");

  // Afficher la température 
  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println("°C");
}

