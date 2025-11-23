# Honey Adulteration Detection using Conductivity Measurement
A low-cost electronic sensing system to detect honey adulteration using a TDS probe, 555 astable oscillator, and Arduino Uno.  
This project implements conductivity-based measurement to estimate adulterant concentration (mineral water / corn syrup) with high accuracy.

---

## Overview
Honey adulteration is a common issue, especially with inexpensive sweeteners like corn syrup and sugar solutions. Conventional detection methods (FTIR, NMR, optical analysis) are accurate but expensive and impractical for field use.

This project provides a simpler alternative: **electrical conductivity measurement**.  
Changes in conductivity correlate strongly with the presence and concentration of adulterants.

---

## Features
- Conductivity measurement using **TDS probe**
- **IC 555 astable oscillator** as frequency generator
- **Arduino Uno** for data acquisition
- Calibration and characterization:
  - Range: *26.83–91.21 μS/cm*
  - Sensitivity: *6.79 %/μS*
  - Linearity: *y = 0.0137x + 0.4029 (R² = 0.9971)*
  - Repeatability: *0.356*
- Adulterant concentration estimation:
  - Error: *±4.92%*
  - Using linear estimation model *y = 0.9871x (R² = 0.9901)*

---

## System Architecture

[Block-Diagram.png](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/167d2acdaa61314b5b05592e94019138ab1242eb/Block-Diagram.png)

---

## Hardware Used
- Arduino Uno  
- TDS Conductivity Probe  
- IC 555 timer Module
- Jumper cables

## Component Specifications (Measured Values)

These component values were measured manually to ensure accurate oscillator behavior and conductivity calculation.
| Component                        | Measured Value        | Notes |
|---------------------------------|------------------------|-------|
| R1 (fixed resistor)             | 1.00 kΩ               | Measured with multimeter |
| Potentiometer (Rpot) – minimum | 1.5 Ω                 | At knob minimum |
| Potentiometer (Rpot) – maximum | 0.96 MΩ               | At knob maximum |
| Timing capacitor (C)           | 62 nF                 | NPO ceramic |
| Cell Constant (K) – TDS Probe  | 0.33 cm              | Derived from calibration |

### Dependencies
- FreqCount Library (Paul Stoffregen)
 
---

## Wiring Diagram

