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
- Adulterant concentration estimation:

---

## System Architecture

**[Block-Diagram.png](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/167d2acdaa61314b5b05592e94019138ab1242eb/Block-Diagram.png)**

---

## Hardware Used
- Arduino Uno  
- TDS Conductivity Probe  
- IC 555 timer Module
- Jumper cables
- Oscilloscope (for Frequency read testing)

## Component Specifications (Measured Values)

These component values were measured manually to ensure accurate oscillator behavior and conductivity calculation.
| Component                        | Measured Value        | Notes |
|---------------------------------|------------------------|-------|
| R1 (fixed resistor)             | 1.00 kΩ               | Measured with multimeter |
| Potentiometer (Rpot) – minimum | 1.5 Ω                 | At knob minimum |
| Potentiometer (Rpot) – maximum | 0.96 MΩ               | At knob maximum |
| Timing capacitor (C)           | 62 nF                 | NPO ceramic |
| Cell Constant (K) – TDS Probe  | 0.33 cm⁻¹             | Derived from calibration |

### Dependencies
**- [FreqCount Library (Paul Stoffregen)](https://github.com/PaulStoffregen/FreqCount)**
 
---

## Wiring Diagram

**- [Oscillator Circuit Schematics](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/4511555f196749cddf6b35969cb78f86e08c5357/Oscillator_Circuit.png)
- [Full Circuit Diagram](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/642a996e98ff54e2583b0cd923f662e7443d4f42/Full_Circuit.png)
**
---

## Pre-Experiment Testing & Validation

Before testing honey samples, two validation steps were performed to ensure the oscillator and measurement system operated correctly.

### Fundamental Basis - Conductivity Formula (Extended)

The conductivity (σ) is computed from the conductance (G) and the cell constant (k):

$$
\sigma = G \cdot k
$$

Using the frequency output of the 555 astable oscillator, the conductance can be expressed as:

$$
G = \frac{2 f C}{1.44 - f C R_1}
$$

Thus the full expression for conductivity becomes:

$$
\sigma = G \cdot k 
       = \frac{2 f C}{1.44 - f C R_1} \cdot k
$$

Where:  
- **f** = oscillator output frequency (Hz)  
- **C** = timing capacitor (F)  
- **R₁** = fixed resistor in 555 timing network (Ω)  
- **k** = cell constant (cm⁻¹)  

### 1. Oscillator Frequency Test (Without Sample)
The 555 astable oscillator was tested using a set of known resistor values to verify the inverse relationship between resistance and frequency.

Results show:
- Frequency decreases consistently as resistance increases  
- Measured frequency closely matches theoretical values  
- Confirms that `f ∝ 1/R`, validating the oscillator for conductivity measurement  

This ensures that frequency readings accurately reflect the probe’s resistive load.

**[Graph Results](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/e10eb8f4345ea0649ddaa816283880e8d838e6a0/Graphs/Graph1%20-%20Oscillator%20Circuit.jpg)**

---

### 2. Hysteresis Test (Input Rising vs Falling)
To evaluate sensor stability, resistance values were increased and decreased gradually while monitoring frequency output.

Findings:

- Minimal hysteresis observed  
- Output remains consistent for both rising and falling input sequences  
- Confirms stable and repeatable measurement characteristics  

This validation confirms the system is suitable for accurate conductivity measurement and adulterant estimation.

**[Graph Results](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/e10eb8f4345ea0649ddaa816283880e8d838e6a0/Graphs/Graph2%20-%20Varying%20Output%20Test.jpg)
**
---

## Results & Summary

This section summarizes the key outcomes of the conductivity-based honey adulteration detection system.  
All experimental results were obtained using the prototype consisting of a TDS probe, 555 astable oscillator, and Arduino-based frequency acquisition.

---

### 1. Static Characteristics

| Parameter              | Result                         | Notes |
|-----------------------|--------------------------------|-------|
| Conductivity Range    | **26.83 – 91.21 μS/cm**        | Based on calibration standards |
| Sensitivity           | **6.79 %/μS**                   | Indicates sensor responsiveness |
| Span                  | **64.38 μS/cm**                 | Full-scale measurable range |
| Linearity (Calibration Curve) | **y = 0.0137x + 0.4029** | R² = **0.9971** |
| Repeatability         | **0.356**                       | Across repeated measurements |

The high linearity (R² = 0.9971) confirms that conductivity correlates strongly with frequency values generated by the 555 oscillator.

---

### 2. Conductivity vs Adulterant Concentration

The system was tested on:
- Pure honey (Madu Samsi, Jombang, East Java, Indonesia)
- Honey adulterated with **mineral water** (various %)
- Honey adulterated with **corn syrup** (various %)

Key findings:
- Increasing adulterant concentration caused a **consistent rise** in electrical conductivity.
- Corn syrup adulteration produced a stronger conductivity shift compared to mineral water.
- The system shows good sensitivity to small adulteration levels.

---

### 3. Adulterant Concentration Estimation

A linear model was developed to estimate adulterant concentration from measured conductivity.

**Estimation Model**

- y = 0.9871x
- R² = 0.9901
- Error = ±4.92%

This demonstrates that the system can not only detect adulteration, but also **estimate the adulterant concentration** with high accuracy.

---

### 4. Frequency-to-Conductivity Conversion

The system converts oscillator frequency → equivalent resistance → conductivity:

- R2 = (11612903.226 / frequency) - 500
- EC = ((1 / R2) - (1 / RPOT)) / CellConstant
- EC(μS/cm) = EC × 10⁶

  Where:
  - RPOT = measured potentiometer max value  
  - Cell Constant (K) = 0.33 cm (from probe calibration)  

These values were derived from real measured hardware data to ensure accuracy.

---

### 5. Final Conclusion

- The prototype successfully detects honey adulteration using electrical conductivity.  
- The system demonstrates **high linearity**, **good repeatability**, and **low estimation error**.  
- This approach provides a **low-cost, portable, and practical** alternative to expensive laboratory tools such as FTIR or NMR.  
- Suitable for **UMKM honey producers**, **field testing**, and **research applications**.

### 6. Experiment Results & Documentations
**- [Project Documentations](https://github.com/danielrnovendra/honey-adulteration-detection-system/tree/9dd8c7108ff05b00243113caa028eaa6f129721e/Documentations)**
**- [Honey with Mineral Water Adulterant Experiment Graph](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/e10eb8f4345ea0649ddaa816283880e8d838e6a0/Graphs/Graph3%20-%20Honey%20%26%20Mineral%20Water.jpg)**
**- [Honey with Corn Syrup Adulterant Experiment Graph](https://github.com/danielrnovendra/honey-adulteration-detection-system/blob/e10eb8f4345ea0649ddaa816283880e8d838e6a0/Graphs/Graph4%20-%20Honey%20%26%20Corn%20Syrup.jpg)
**
---
