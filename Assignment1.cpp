#include <Arduino.h>

/* LED PINs */
#define LED_BLAUW 23
#define LED_GROEN 22
#define LED_ROOD 21

/* Potentiometer PIN */
#define POTENTIOMETER 34

/* Maximale readings voor elke LED */
/* Maximum readings for each LED */
const int MINIMUM = 0;
const int BLAUW_MAX = 1000;
const int GROEN_MAX = 2500;
const int ROOD_MAX = 4096;

/* Variable voor de reading van de potentiometer */
/* Variable for the reading from the potentiometer */
int reading;

void setup() {
  /* Evt. voor Debugging */
  /* Optional: for debugging */
  Serial.begin(9600);
  pinMode(LED_BLAUW, OUTPUT);
  pinMode(LED_GROEN, OUTPUT);
  pinMode(LED_ROOD, OUTPUT);
}

void enable_correct_led() {
  /* Als de meting voor wat voor reden dan ook minder dan 0 of meer dan ROOD_MAX is, doen we niks. */
  /* If the measurement for any reason is less than 0 or greater than ROOD_MAX, do nothing. */
  if (reading < MINIMUM || reading > ROOD_MAX) return;

  /* Debug */
  Serial.print("Reading: ");
  Serial.println(reading);

  if (reading <= BLAUW_MAX) {
    /* Blauw aan */
    /* Blue on */
    digitalWrite(LED_BLAUW, HIGH);

    /* De rest uit */
    /* Turn the rest off */
    digitalWrite(LED_GROEN, LOW);
    digitalWrite(LED_ROOD, LOW);
  } else if (reading <= GROEN_MAX) {
    /* Groen aan */
    /* Green on */
    digitalWrite(LED_GROEN, HIGH);

    /* De rest uit */
    /* Turn the rest off */
    digitalWrite(LED_BLAUW, LOW);
    digitalWrite(LED_ROOD, LOW);
  } else if (reading <= ROOD_MAX) {
    /* Rood aan */
    /* Red on */
    digitalWrite(LED_ROOD, HIGH);

    /* De rest uit */
    /* Turn the rest off */
    digitalWrite(LED_BLAUW, LOW);
    digitalWrite(LED_GROEN, LOW);
  }
}

void loop() {
  /* Lees de potentiometer uit */
  /* Read the potentiometer */
  reading = analogRead(POTENTIOMETER);

  /* Call de functie die de juiste LED aanzet */
  /* Call the function that enables the correct LED */
  enable_correct_led();

  /* Korte delay zodat er niemand een epilepsie aanval krijgt */
  /* Short delay so nobody gets an epileptic seizure */
  delay(500);
}