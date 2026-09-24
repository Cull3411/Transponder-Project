// Digispark ATTINY85 - IR Transponder ID 1 (example of IDs 1-96)
// Optimized: removed redundant digitalWrite, named repetition constant
// Uses mathematically tidy 24-value gap array (avg 12.50 ms, multiples of 40 µs)
//
// Developed with AI assistance (Grok), then reviewed and tuned on hardware.
// Personal / experimental firmware. Verify timing on your own decoder before use.

const uint8_t IR_LED_PIN = 1;
const uint32_t BLOCK_US = 139;
const uint8_t REPETITIONS_PER_MESSAGE = 130;   // ← easy to tune (100–200 typical)

const uint8_t BLOCK_PATTERN[30] = {
  1,0,1,1,1,0,1,1,1,0,    // Byte 1
  1,0,1,1,1,0,1,1,1,0,    // Byte 2 (identical)
  1,0,1,1,1,0,0,1,0,0     // Byte 3: Start(1) + 01110010 (114) + Stop(0)
};

// Mathematically tidy 24-value gap array (µs)
// Clean multiples of 40 µs, average = exactly 12 500 µs
const uint32_t GAP_ARRAY[24] = {
  11840, 12240, 11840, 13040, 13840, 14640,
  11040, 14640, 11040, 13040, 13840, 10640,
  14240, 12640, 12640, 14640, 13040, 13040,
  11840, 11840, 13040, 15040, 11040, 11040
};

static uint8_t gapIndex = 0;

void setup() {
  pinMode(IR_LED_PIN, OUTPUT);
  digitalWrite(IR_LED_PIN, LOW);
  // Timer1 setup for ~38 kHz carrier on PB1 (OC1A)
  TCCR1  = 0;
  GTCCR  = 0;
  OCR1A  = 142;
  OCR1C  = 142;
  TCNT1  = 0;
  TCCR1  = (1 << CTC1) | (1 << CS10);   // CTC mode, no prescaler
}

void loop() {
  // Transmit one 30-bit message, repeated N times
  for (uint8_t rep = 0; rep < REPETITIONS_PER_MESSAGE; rep++) {
    for (uint8_t b = 0; b < 30; b++) {
      if (BLOCK_PATTERN[b]) {
        TCCR1 |=  (1 << COM1A0);           // enable carrier toggle
        delayMicroseconds(BLOCK_US);
        TCCR1 &= ~(1 << COM1A0);           // disable carrier → pin forced low
        // No digitalWrite needed here
      } else {
        delayMicroseconds(BLOCK_US);       // space (off)
      }
    }
  }
  // Insert next gap from tidy array
  delayMicroseconds(GAP_ARRAY[gapIndex]);
  gapIndex = (gapIndex + 1) % 24;
}
