# Smart Lighting System

## 📋 Project Description

This Arduino project is a **smart people counter with automatic lighting control**. It uses **two IR sensors** to count how many people enter or exit a room, and an **LDR (Light Dependent Resistor)** to measure the ambient light level.

**How it works:**
- When someone enters (IR1 then IR2), the system **increases the count**.
- When someone exits (IR2 then IR1), the system **decreases the count**.
- If people are inside:
  - **Low light:** turn ON **2 LEDs**.
  - **Bright light:** turn ON **all LEDs**.
- If no one is inside: **turn OFF all LEDs**.
- The **Serial Monitor** shows:
  - Who’s entering or exiting.
  - Number of people inside.
  - The current light level.

This saves energy by only using lights when needed and adjusting brightness automatically.

---

## ⚙️ Pins Used

| Component   | Pin(s) | Purpose |
|-------------|--------|---------|
| IR Sensor 1 | 2 (Input) | Detects people crossing |
| IR Sensor 2 | 3 (Input) | Detects people crossing |
| LEDs | 4, 5, 6, 7, 8, 9 (Output) | Room lights (controlled individually) |
| LDR Sensor | A0 (Analog Input) | Reads ambient light level |

---

## 🧰 Hardware Required

- 1 × **Arduino board** (Uno, Mega, etc.)
- 2 × **IR obstacle detection sensors**
- 1 × **LDR** (Light Dependent Resistor)
- 1 × **10kΩ resistor** (for LDR voltage divider)
- 6 × **LEDs** (or connect to relays for real lamps)
- Breadboard and jumper wires

---

## ✅ Key Features

- Accurate people counting based on sensor sequence.
- No negative counts.
- Automatic lights ON/OFF.
- Smart brightness control.
- Serial Monitor status updates.

---

## 📂 Files

- `lighting_system.ino` — Main Arduino code

---
