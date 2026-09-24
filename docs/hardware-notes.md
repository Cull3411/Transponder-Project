# Hardware notes

Confirmed on a tested-good unit (Digispark rev3 photos, 24 Sep 2026).

## Board

- Board: Digispark **rev3** (ATtiny85)
- Power: RC car 5 V into Digispark **5V** pad (not VIN unless you intend the onboard regulator path)
- Output: IR LED (5 mm red-lens module on JST-style lead)

## Confirmed wiring

| Color | From | To on Digispark | Port / Arduino pin |
| --- | --- | --- | --- |
| Red | RC car +5 V (servo-style plug) | **5V** pad | VCC |
| Black | RC car ground **and** IR LED cathode (common ground) | **GND** pad | GND |
| Yellow | IR LED anode / drive | **P1** | **PB1 / D1** (Timer1 OC1A, PWM) |

Sketch constant: `IR_LED_PIN = 1` — this is Digispark **P1**, which is Arduino **D1**, not D0.

P0 / D0 / PB0 is the next pin over. Timer1 `COM1A0` toggles **OC1A on PB1**, so the LED must stay on P1.

## Connectors (from the tested harness)

- RC car power: 3-pin servo-style housing (red + black used)
- IR LED: 2-pin JST-style plug (yellow + black)

## Naming trap

People often write “P1/D0/PWM.” On Digispark:

- **P0 = D0 = PB0** (PWM on some cores)
- **P1 = D1 = PB1** (PWM / Timer1 OC1A) ← this build

## Photos

Keep build photos local or add them under `hardware/` if you want them public. Do not commit anything that shows private locations or unpublished decoder captures.
