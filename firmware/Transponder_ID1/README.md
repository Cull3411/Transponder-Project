# Transponder ID 1 (Digispark ATtiny85)

Example sketch developed with **Grok**, then tuned on hardware.

## Hardware

- Board: Digispark (ATtiny85)
- IR LED on **PB1 / pin 1** (Timer1 OC1A for ~38 kHz carrier)
- Target: LapMonitor-style IR lap transponder, ID 1

## What the sketch does

- Builds a 30-bit on/off block pattern (two identical bytes + start/data/stop third byte)
- Repeats each message `REPETITIONS_PER_MESSAGE` times (default 130)
- Inserts a rotating 24-value gap array (multiples of 40 µs, average 12.50 ms)
- Uses Timer1 CTC toggle for the IR carrier instead of bit-banging `digitalWrite` on every pulse

## How AI was used

- First-pass structure and timing cleanup (named constants, gap array math)
- Removal of redundant pin writes after carrier enable/disable
- Human owned: pin choice, decoder testing, repetition count, and whether the pattern matches the intended ID

## Build notes

1. Use Digispark / ATtiny85 core in Arduino IDE.
2. Confirm the IR LED is on PB1 (Digispark physical pin 1).
3. Tune `REPETITIONS_PER_MESSAGE` (100–200 typical) against your decoder.
4. `BLOCK_US` and `OCR1A`/`OCR1C` set pulse width and carrier; change only if you have a scope or a failing decode.

Personal / experimental. Test on your own equipment.
