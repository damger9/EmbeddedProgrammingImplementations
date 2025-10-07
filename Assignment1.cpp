#include <Arduino.h>

// LED PINs
#define LED_BLAUW 23
#define LED_GROEN 22
#define LED_ROOD 21

// Potentiometer PIN
#define POTENTIOMETER 34

// Maximale readings voor elke LED
const int MINIMUM = 0;
const int BLAUW_MAX = 1000;
const int GROEN_MAX = 2500;
const int ROOD_MAX = 4096;

// Variable voor de reading van de potentiometer
int reading;

void setup() {
  Serial.begin(9600); // Evt. voor Debugging
  pinMode(LED_BLAUW, OUTPUT);
  pinMode(LED_GROEN, OUTPUT);
  pinMode(LED_ROOD, OUTPUT);
}

void enable_correct_led() {
  // Als de meting voor wat voor reden dan ook minder dan 0 of meer dan ROOD_MAX is, doen we niks.
  if (reading < MINIMUM || reading > ROOD_MAX) return;

  // Debug
  Serial.print("Reading: ");
  Serial.println(reading);

  if (reading <= BLAUW_MAX) {
    // Blauw aan
    digitalWrite(LED_BLAUW, HIGH);

    // De rest uit
    digitalWrite(LED_GROEN, LOW);
    digitalWrite(LED_ROOD, LOW);
  } else if (reading <= GROEN_MAX) {
    // Groen aan
    digitalWrite(LED_GROEN, HIGH);

    // De rest uit
    digitalWrite(LED_BLAUW, LOW);
    digitalWrite(LED_ROOD, LOW);
  } else if (reading <= ROOD_MAX) {
    // Rood aan
    digitalWrite(LED_ROOD, HIGH);

    // De rest uit
    digitalWrite(LED_BLAUW, LOW);
    digitalWrite(LED_GROEN, LOW);
  }
}

void loop() {
  // Lees de potentiometer uit
  reading = analogRead(POTENTIOMETER);
  // Call de functie die de juiste LED aanzet
  enable_correct_led();
  // Korte delay zodat er niemand een epilepsie aanval krijgt
  delay(500);
}