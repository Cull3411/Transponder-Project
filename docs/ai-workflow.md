# AI workflow for this project

This note is the portfolio piece: it shows how AI was used as a tool with human verification.

## Pattern used

1. **State the constraint first.** Board type, available pins, timing needs, what must not happen (example: do not block forever in `loop()`).
2. **Ask for a small piece, not the whole system.** One function or one timing loop at a time.
3. **Treat the reply as a draft.** Read every pin number and delay. Compare to the schematic or measured wiring.
4. **Test on hardware.** Serial output, LED, or scope beat a clean-looking sketch.
5. **Feed failures back.** Paste the actual symptom ("LED stays on, serial prints ID once then stops") rather than "it doesn't work."

## Example prompt style

> Arduino Nano. I need a non-blocking loop that blinks a status LED on D13 every 500 ms and sends a short ID burst on D8. Do not use `delay()` in `loop()`. Explain the timing approach in comments. I will verify pin numbers against my board.

## What I check before flashing

- Pin numbers match the physical board
- No secrets or private keys in the sketch
- Timing is plausible for the crystal / board clock
- Serial baud rate matches the monitor setting
- Power and ground are correct before connecting an RF or IR stage

## Why this matters on a resume / LinkedIn

Employers asking for "AI experience" usually want this loop: use the tool, validate the output, own the result. That is the process used here.
