#include <Arduino.h>

/* De LED die het SOS teken gaat uitvoeren */
/* The LED that will perform the SOS pattern */
#define LED_PIN 23

/* Hoeveel pauze tussen elk teken */
/* How long to pause between each signal */
const int PAUSE_TIME = 500;

/* De SOS sequentie */
/* The SOS sequence */
const int SEQUENCE[3] = {500, 1000, 500};

void setup() {
    /* EVT. voor debugging */
    /* Optional: for debugging */
    Serial.begin(9600);

    /* LED instellen als output. */
    /* Set LED pin as output */
    pinMode(LED_PIN, OUTPUT);
}

void burst(int speed = 500) { 
    /* De snelheid van het teken. */
    /* The speed/duration of each signal */
    for (int i = 0; i < 3; i++) {
        /* LED aan */
        /* Turn LED on */
        digitalWrite(LED_PIN, HIGH);

        /* Wacht de snelheid */
        /* Wait for the duration */
        delay(speed);

        /* LED uit */
        /* Turn LED off */
        digitalWrite(LED_PIN, LOW);

        /* De pauze */
        /* Pause between signals */
        delay(PAUSE_TIME);
    }
}

void loop() {
    for (int i = 0; i < 3; i++)
        /* For loop voor de SOS sequentie */
        /* Loop through the SOS sequence */
        burst(SEQUENCE[i]);

    /* 1 Seconde pauze na elke loop. */
    /* 1 second pause after each loop */
    delay(1000);
}