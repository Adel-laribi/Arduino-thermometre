#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Définir le type de capteur DHT
#define DHTPIN 2     
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

// Initialisation de l'écran LCD I2C (adresse 0x27, écran 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 9; // Pin de la LED
float temperatureSeuil = 30.0; // Seuil pour l'alerte LED

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(ledPin, OUTPUT);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("SmartThermometer");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  
  // Vérification des erreurs de lecture
  if (isnan(temp)) {
    Serial.println("Erreur de lecture du capteur DHT !");
    lcd.setCursor(0, 0);
    lcd.print("Erreur capteur!");
    delay(2000);
    lcd.clear();
    return;
  }

  // Affichage sur le LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");

  // Affichage sur le moniteur série
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" C");

  // Contrôle de la LED
  if (temp > temperatureSeuil) {
    digitalWrite(ledPin, HIGH); // Allume la LED
    lcd.setCursor(0, 1);
    lcd.print("Alerte !");
  } else {
    digitalWrite(ledPin, LOW); // Éteint la LED
    lcd.setCursor(0, 1);
    lcd.print("            "); // Efface la ligne
  }

  delay(2000); // Attendre 2 secondes avant la prochaine lecture
}
