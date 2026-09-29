# 8051 LCD Interfacing

## 📌 Overview

This project demonstrates **16×2 LCD interfacing with the 8051 microcontroller**. The LCD is used to display characters and messages received from the 8051.

The project covers the basic concepts of **microcontroller programming, LCD interfacing, GPIO control, and embedded C programming**.

## 🛠️ Components Required

* 8051 Microcontroller
* 16×2 LCD Display
* Crystal Oscillator
* Capacitors
* Resistors
* Potentiometer
* Connecting Wires
* Breadboard / Development Board
* 5V Power Supply

## 🔌 LCD Connections

| LCD Pin | Function         | 8051 Connection |
| ------- | ---------------- | --------------- |
| VSS     | Ground           | GND             |
| VDD     | +5V              | +5V             |
| V0      | Contrast         | Potentiometer   |
| RS      | Register Select  | GPIO Pin        |
| RW      | Read/Write       | GND             |
| EN      | Enable           | GPIO Pin        |
| D0–D7   | Data Pins        | 8051 Port       |
| LED+    | Backlight        | +5V             |
| LED−    | Backlight Ground | GND             |

> The exact 8051 port and pin connections can be modified according to the circuit design and program.

## 💻 Software

* **Keil µVision**
* **Embedded C**
* **8051 Microcontroller**
* **Proteus** *(optional, for simulation)*

## ⚙️ Working Principle

The 8051 communicates with the 16×2 LCD using control and data signals.

The basic sequence is:

1. Initialize the LCD.
2. Send the required LCD commands.
3. Position the cursor.
4. Send character or string data.
5. Display the message on the LCD.

The `RS`, `RW`, and `EN` pins are used to control communication between the microcontroller and LCD.

## 📂 Project Structure

```text
8051-LCD-Interfacing/
│
├── README.md
├── lcd.c
├── lcd.hex
├── circuit/
│   └── lcd_8051.pdsprj
└── images/
    └── circuit.png
```

## 🎯 Skills Demonstrated

* 8051 Microcontroller Programming
* Embedded C
* LCD Interfacing
* GPIO Programming
* Digital Electronics
* Hardware Interfacing
* Proteus Simulation
* Keil µVision

## 🚀 Future Improvements

* Display sensor readings on LCD
* Interface keypad with LCD
* Add UART communication
* Interface ADC with 8051
* Develop menu-based LCD applications

## 👨‍💻 Author

**Satyam Patil**

Electronics & Telecommunication Engineering
Embedded Systems | Digital Electronics | Verilog | VLSI
