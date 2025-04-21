# ESP32-S3 5-Motor PWM Control with DRV8871

This project demonstrates how to control **five DC motors** using an **ESP32-S3**, the **LEDC PWM hardware**, and **DRV8871** motor drivers.

Each motor is individually controlled for direction and speed using PWM and GPIO pins.

---

## 🧰 Hardware Required

- ESP32-S3 development board
- 5x DRV8871 motor drivers
- 5x DC motors
- External power supply (for motors)
- Jumper wires
- Breadboard (optional)

---

## ⚙️ Pin Configuration

| Motor | PWM Pin | DIR Pin |
|-------|---------|---------|
| M1    | GPIO 1  | GPIO 2  |
| M2    | GPIO 6  | GPIO 7  |
| M3    | GPIO 20 | GPIO 21 |
| M4    | GPIO 17 | GPIO 18 |
| M5    | GPIO 9  | GPIO 10 |

Each PWM pin is tied to a separate **LEDC channel** with an 8-bit resolution (0–255) and a frequency of 20kHz (ideal for DRV8871).

---

## 🔧 How It Works

- Direction pins (`IN2`) are set HIGH or LOW to choose forward or reverse.
- Speed is controlled by varying the duty cycle on the corresponding LEDC PWM channel.
- The `setMotor()` function takes care of setting direction and speed.

```cpp
void setMotor(int dirPin, int pwmChannel, bool direction, int speed) {
  digitalWrite(dirPin, direction);
  ledcWrite(pwmChannel, speed); // Speed: 0–255
}
