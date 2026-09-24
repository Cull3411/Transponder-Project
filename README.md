# Transponder Project

Personal Arduino hardware and firmware project by **Todd Davis** ([Cull3411](https://github.com/Cull3411)).

Experimental IR transponder work on a **Digispark ATtiny85**. A Grok-assisted sketch for **ID 1** is in the repo as an example. IDs run from **1 to 96**; nearly all of those IDs have been worked through. AI tools drafted and cleaned timing code; hardware testing and decoder checks stayed human-owned.

Companion decoder repo: [Decoder-Project](https://github.com/Cull3411/Decoder-Project)

## Featured sketch (example ID)

[`firmware/Transponder_ID1/Transponder_ID1.ino`](firmware/Transponder_ID1/Transponder_ID1.ino)

- Board: Digispark (ATtiny85)
- IR LED on PB1 / pin 1
- Timer1 CTC ~38 kHz carrier on OC1A
- 30-bit block pattern, 130 repeats per message (tunable)
- 24-slot gap array, 40 µs multiples, 12.50 ms average
- **ID 1 is an example** of the ID set **1–96**

Details: [`firmware/Transponder_ID1/README.md`](firmware/Transponder_ID1/README.md)

A generic non-blocking beacon sketch remains at [`firmware/TransponderBeacon/`](firmware/TransponderBeacon/) as a simpler starting point.

## What this is

- Hands-on electronics and firmware on Arduino-class / ATtiny boards
- Iterative design: observe behavior, implement, test, correct
- AI used to accelerate first-pass code and documentation — **not** as an unattended agent

## What this is not

- Not a commercial product
- Not "AI built this by itself." The sketch was reviewed and tuned before use

## How AI was used

| Step | Human | AI assistant |
| --- | --- | --- |
| Problem definition | Board, pin, target ID, decoder constraints | — |
| First-pass firmware | Reject bad assumptions | Draft timing loops, constants, comments |
| Optimization | Confirm on hardware | Remove redundant writes, tidy gap math |
| Documentation | Confirm accuracy | Draft README and comments |
| Validation | Flash and test against decoder | Never trusted without a bench check |

Tools used: **Grok**, **ChatGPT**, **Microsoft Copilot**.

## Repository layout

```
firmware/Transponder_ID1/     Digispark ATtiny85 IR sketch — example ID 1 of 1–96
firmware/TransponderBeacon/   Generic placeholder beacon
docs/                         AI workflow and hardware notes
```

## Getting started

1. Open `firmware/Transponder_ID1/Transponder_ID1.ino` in Arduino IDE with the Digispark / ATtiny85 core.
2. Confirm the IR LED is on pin 1 (PB1).
3. Read `docs/ai-workflow.md` and `firmware/Transponder_ID1/README.md`.
4. Tune `REPETITIONS_PER_MESSAGE` against your decoder.

## Author

Todd Davis  
LinkedIn: [linkedin.com/in/todd-davis-4b5b7b37](https://linkedin.com/in/todd-davis-4b5b7b37)
