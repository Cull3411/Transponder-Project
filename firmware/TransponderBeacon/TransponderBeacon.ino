/*
 * TransponderBeacon.ino
 * Experimental Arduino beacon / status transmitter.
 *
 * Placeholder sketch for Todd Davis / Cull3411 Transponder-Project.
 * Replace pin numbers after confirming wiring. This is a learning
 * and documentation sketch, not a vendor-protocol clone.
 *
 * AI assistants (Grok, ChatGPT, Copilot) helped draft structure.
 * Timing and pins must be verified on hardware before use.
 */

const uint8_t PIN_LED = 13;
const uint8_t PIN_TX  = 8;

const unsigned long LED_PERIOD_MS = 500;
const unsigned long BURST_PERIOD_MS = 1000;
const unsigned int  BURST_PULSES = 8;
const unsigned int  PULSE_WIDTH_US = 200;

unsigned long lastLedMs = 0;
unsigned long lastBurstMs = 0;
bool ledOn = false;

void sendBurst() {
  for (unsigned int i = 0; i < BURST_PULSES; i++) {
    digitalWrite(PIN_TX, HIGH);
    delayMicroseconds(PULSE_WIDTH_US);
    digitalWrite(PIN_TX, LOW);
    delayMicroseconds(PULSE_WIDTH_US);
  }
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TX, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_TX, LOW);

  Serial.begin(115200);
  delay(200);
  Serial.println(F("TransponderBeacon starting"));
  Serial.println(F("Verify PIN_LED and PIN_TX against your wiring."));
}

void loop() {
  unsigned long now = millis();

  if (now - lastLedMs >= LED_PERIOD_MS) {
    lastLedMs = now;
    ledOn = !ledOn;
    digitalWrite(PIN_LED, ledOn ? HIGH : LOW);
  }

  if (now - lastBurstMs >= BURST_PERIOD_MS) {
    lastBurstMs = now;
    sendBurst();
    Serial.println(F("burst"));
  }
}
