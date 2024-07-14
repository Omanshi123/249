#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define IR_RECEIVER_PIN 13
#define LED_PIN 12

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();  // Start the IR receiver
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    // If an IR signal is received, toggle the LED
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(500);  // Add a delay to avoid rapid toggling
    irrecv.resume();  // Receive the next value
  }
}
