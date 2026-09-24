# Transponder Project

Personal Arduino hardware and firmware project by **Todd Davis** ([Cull3411](https://github.com/Cull3411)).

This repository documents an experimental transponder / beacon build: hardware reverse-engineering notes, firmware development, and the way **AI tools** (Grok, ChatGPT, Microsoft Copilot) were used as assistants — then verified on the bench.

## What this is

- Hands-on electronics and firmware work on Arduino-class boards
- Iterative design: observe hardware behavior, form a hypothesis, implement firmware, test, correct
- AI used to accelerate first-pass code, comments, and documentation — **not** as an unattended agent

## What this is not

- Not a commercial product
- Not a drop-in clone of a vendor racing-timing or aviation transponder protocol
- Not "AI built this by itself." Every sketch is reviewed and tested before it is treated as real firmware

## How AI was used

| Step | Human | AI assistant |
| --- | --- | --- |
| Problem definition | Describe the hardware goal and constraints | — |
| First-pass firmware | Review and reject bad assumptions | Draft functions, pin maps, timing loops |
| Debugging | Scope / serial logs / actual behavior | Suggest likely causes from symptoms |
| Documentation | Confirm accuracy | Draft README and comments |
| Validation | Flash, measure, test | Never trusted without a bench check |

Tools used: **Grok**, **ChatGPT**, **Microsoft Copilot**.

## Repository layout

```
firmware/          Arduino sketches
docs/              Design notes and AI-workflow notes
hardware/          Wiring notes (add photos/schematics as you have them)
```

## Getting started

1. Open `firmware/TransponderBeacon/TransponderBeacon.ino` in Arduino IDE or PlatformIO.
2. Select your board and port.
3. Read `docs/ai-workflow.md` for how prompts and verification were handled.
4. Replace placeholder pin assignments with your actual wiring before relying on the sketch.

## Status

Scaffold created September 2026. Firmware and hardware notes will be added as they are tested.

## Author

Todd Davis  
LinkedIn: [linkedin.com/in/todd-davis-4b5b7b37](https://linkedin.com/in/todd-davis-4b5b7b37)
