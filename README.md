# 🔥 Gas Leakage Detection & Automatic Shutoff

An Arduino-based safety system that detects gas leakage using an **MQ-2 gas sensor** and automatically activates a **buzzer** while moving a **servo motor** to shut off the gas regulator.

## 📌 Project Overview

Gas leakage can be dangerous if it is not detected quickly. This project provides an automatic warning and shutoff mechanism.

When the MQ-2 sensor detects gas:

* 🚨 The buzzer turns ON.
* ⚙️ The servo motor rotates to **90°**.
* 🔒 The servo can be mechanically connected to a gas regulator/shutoff mechanism.
* 🖥️ The gas sensor status is displayed on the Serial Monitor.

## 🧰 Components Used

| Component              |    Quantity |
| ---------------------- | ----------: |
| Arduino Uno            |           1 |
| MQ-2 Gas Sensor Module |           1 |
| Servo Motor            |           1 |
| Buzzer                 |           1 |
| Breadboard             |           1 |
| Jumper Wires           | As required |

## 🔌 Pin Connections

| Component    | Arduino Pin                   |
| ------------ | ----------------------------- |
| MQ-2 D0      | D2                            |
| Buzzer       | D3                            |
| Servo Signal | D9                            |
| MQ-2 VCC     | 5V                            |
| MQ-2 GND     | GND                           |
| Servo VCC    | 5V / suitable external supply |
| Servo GND    | GND                           |

> **Note:** If an external supply is used for the servo, connect its GND to the Arduino GND.

## ⚙️ Working Principle

```text
        ┌──────────────┐
        │    MQ-2      │
        │ Gas Sensor   │
        └──────┬───────┘
               │
               │ Gas detected
               ▼
        ┌──────────────┐
        │  Arduino Uno │
        └──────┬───────┘
               │
        ┌──────┴───────┐
        ▼              ▼
   ┌─────────┐    ┌──────────┐
   │ Buzzer  │    │  Servo   │
   │   ON    │    │   90°    │
   └─────────┘    └────┬─────┘
                       │
                       ▼
                 Gas Shutoff
```

### Normal Condition

```text
MQ-2 D0 = HIGH
     ↓
No gas detected
     ↓
Buzzer OFF
     ↓
Servo = 0°
```

### Gas Leakage Condition

```text
MQ-2 D0 = LOW
     ↓
Gas detected
     ↓
Buzzer ON
     ↓
Servo = 90°
     ↓
Gas regulator shutoff mechanism activated
```

## 💻 Software

* Arduino IDE
* Embedded C / Arduino C++
* `Servo.h` library

## 🧠 Key Concepts Demonstrated

* Digital sensor interfacing
* Gas detection
* GPIO programming
* Servo motor control
* Buzzer control
* `millis()` timing
* Serial communication
* Embedded safety automation

## 🚀 Future Improvements

* Add an **LCD/OLED display** for gas status.
* Add an **ESP32/Wi-Fi module** for mobile notifications.
* Add an **MQ-2 analog output** for monitoring gas concentration.
* Add a **manual reset button** after the regulator is shut off.
* Add a **temperature sensor** for additional safety monitoring.
* Add data logging for gas-leakage events.

## ⚠️ Safety Note

This project is intended as an **educational prototype**. A hobby servo and Arduino should not be treated as a certified gas-safety device. Any real gas shutoff mechanism should use properly rated hardware and be installed/tested by a qualified professional.

## 📄 License

This project is available for educational and personal use.
