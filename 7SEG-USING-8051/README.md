# 8051 3-Digit 7-Segment Counter

## 📌 Overview

This project implements a **3-digit 7-segment counter using the 8051 microcontroller**. An external pulse signal is connected to the **T1 pin (P3.5)** of the 8051, and Timer 1 is configured in **counter mode** to count the incoming pulses.

The counted value is displayed on a **3-digit 7-segment display** using multiplexing.

## 🎯 Project Features

* 8051 microcontroller based counter
* External pulse counting using **Timer 1**
* 3-digit 7-segment display
* Multiplexed display technique
* Displays count from **000 to 999**
* Automatic reset after reaching the maximum count
* Programmed using Embedded C

## 🛠️ Hardware Components

* 8051 Microcontroller
* 3 × 7-Segment Display
* Resistors
* Crystal Oscillator
* Capacitors
* External Pulse Source
* Connecting Wires
* 5V Power Supply

## 🔌 Pin Configuration

### 7-Segment Display

| 8051 Pin | Connection     | Purpose             |
| -------- | -------------- | ------------------- |
| P2       | Segment Lines  | Sends digit pattern |
| P1.0     | Hundreds Digit | Digit selection     |
| P1.1     | Tens Digit     | Digit selection     |
| P1.2     | Units Digit    | Digit selection     |

### External Pulse Input

| 8051 Pin  | Function             |
| --------- | -------------------- |
| P3.5 / T1 | External pulse input |

The external pulses applied to **P3.5 (T1)** are counted by Timer 1.

## ⚙️ Working Principle

The project uses **Timer 1 as an external event counter**.

The important configuration is:

```c
TMOD = 0X50;
TH1 = 0X00;
TL1 = 0X00;
TR1 = 1;
```

### Timer Configuration

`TMOD = 0x50` configures Timer 1 as:

* **Timer 1**
* **Mode 1**
* **16-bit counter mode**
* External pulses are received through **P3.5/T1**

The current count is obtained using:

```c
count = (TH1 << 8) | TL1;
```

The 16-bit Timer 1 value is therefore combined from `TH1` and `TL1`.

## 🔢 3-Digit Display

The count is separated into hundreds, tens, and units:

```c
dH = num / 100;
dT = (num / 10) % 10;
dU = num % 10;
```

For example:

| Count | Hundreds | Tens | Units |
| ----: | -------: | ---: | ----: |
|   125 |        1 |    2 |     5 |
|   347 |        3 |    4 |     7 |
|   908 |        9 |    0 |     8 |

The three digits are displayed one after another using **multiplexing**.

```c
digH = 0; digT = 1; digU = 1;
P2 = setCode[dH];

digH = 1; digT = 0; digU = 1;
P2 = setCode[dT];

digH = 1; digT = 1; digU = 0;
P2 = setCode[dU];
```

Because the digits are switched rapidly, they appear to be continuously illuminated.

## 🔢 7-Segment Codes

The following segment codes are used:

```c
unsigned int setCode[10] =
{
    0xC0, 0xF9, 0xA4, 0xB0, 0x99,
    0x92, 0x82, 0xF8, 0x80, 0x90
};
```

These codes correspond to digits **0–9** for the configured **common-anode 7-segment display**.

| Digit | Hex Code |
| ----: | -------: |
|     0 |     0xC0 |
|     1 |     0xF9 |
|     2 |     0xA4 |
|     3 |     0xB0 |
|     4 |     0x99 |
|     5 |     0x92 |
|     6 |     0x82 |
|     7 |     0xF8 |
|     8 |     0x80 |
|     9 |     0x90 |

## 🔄 Counter Reset

The program is intended to reset the counter after the display reaches **999**:

```c
if(count > 999)
{
    TH1 = 0x00;
    TL1 = 0x00;
    count = 0;
}
```

The display therefore operates in the range:

```text
000 → 001 → 002 → ... → 998 → 999 → 000
```

> **Note:** In the submitted code, `if(count>>999)` is not the correct C expression for checking whether `count` exceeds 999. It should be `if(count > 999)`.

## 💻 Software Used

* **Keil µVision**
* **Embedded C**
* **8051 Microcontroller**
* **Proteus** *(optional for simulation)*

## 📂 Project Structure

```text
8051-3-Digit-Counter/
│
├── README.md
├── counter.c
├── counter.hex
│
├── circuit/
│   └── counter_8051.pdsprj
│
└── images/
    └── circuit.png
```

## 🧠 Concepts Demonstrated

* 8051 Microcontroller
* Embedded C Programming
* Timer/Counter Configuration
* External Pulse Counting
* Timer 1 – Mode 1
* 16-bit Counter
* 7-Segment Display Interfacing
* Multiplexing
* GPIO Programming
* Digital Electronics
* Hardware Interfacing
* Keil µVision
* Proteus Simulation

## 🚀 Possible Extensions

* Add push-button control
* Add Start/Stop functionality
* Interface a sensor as the external pulse source
* Implement an RPM counter
* Add an LCD to display additional information
* Add an alarm when a specified count is reached

## 👨‍💻 Author

**Satyam Patil**

Electronics & Telecommunication Engineering

**Technical Interests:**
Embedded Systems | Digital Electronics | Verilog HDL | VLSI Design | Microcontrollers
