# 📟  Automated Toll Gate Using Arduino (Vehicle Detection Gate)
Automated Toll Gate Using Arduino is a smart system designed to control toll gates without human 
intervention. It uses an ultrasonic sensor to detect vehicles and a servo motor to automatically open 
and close the gate, enhancing traffic flow and reducing manual effort.

---

## 🔌 Circuit Diagram

The circuit was designed and simulated using **Tinkercad**.

![Screenshot 2025-05-31 183957](https://github.com/user-attachments/assets/230b764a-2a07-43de-80e3-f46c21679240)

---

## 🧰 Components Required

| Component                    | Quantity |
|------------------------------|----------|
| Arduino UNO                  | 1        |
| Servo Motor SG90          | 1        |
|  Ultrasonic Sensor HC-SR04  | 1    |
| Breadboard                   | 1        |
| Jumper Wires                 | 10+      |
|  Buzzer                   | 1        |
|Resistance               |1           |
|LED                 |1            |
---

## 💻 Arduino Code

```cpp
#include <Servo.h>
#define echoPin 11
#define trigPin 12

Servo myServo;

int green_led = 6;
int red_led = 7;

long duration;
int distance;

int count = 0;
bool vehicleDetected = false;
bool gateOpened = false;

void setup() {
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  myServo.attach(13);
  myServo.write(90);  // Gate initially closed
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 20) {
    if (!vehicleDetected) {
      vehicleDetected = true;
      gateOpened = true;
      count++;
      Serial.print("Vehicles Passed: ");
      Serial.println(count);

      myServo.write(0);  // Open gate
      digitalWrite(red_led, LOW);
      digitalWrite(green_led, HIGH);
    }
  } else {
    if (vehicleDetected) {
      vehicleDetected = false;
      gateOpened = false;
      
      Serial.println("Vehicle Left, Gate Closing");

      myServo.write(90);  // Close gate
      digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
    }
  }

  delay(200);
}
```

---

### 🔧 Hardware Setup

Working Principle
### 🔧 Working Principle

1. The **Ultrasonic Sensor (HC-SR04)** continuously monitors the distance in front of the toll gate using sound waves. It sends pulses via the `trigPin` and listens for their echo through the `echoPin` to detect incoming vehicles.

2. **When a vehicle is detected within 20 cm**:
   - The **servo motor rotates to 0°**, simulating the gate opening.
   - The **green LED** turns on to indicate that the gate is open.
   - The **vehicle counter** increments to track the passing vehicle.

3. **When no vehicle is detected**:
   - The **servo motor returns to 90°**, simulating the gate closing.
   - The **red LED** turns on to indicate that the gate is closed.
   - The **green LED** turns off, and the system resets to detect the next vehicle.

4. This process repeats continuously, enabling **automatic, real-time gate operation** based on vehicle detection.


---

### 🖧 Wiring Table

| Component                       | Pin Name        | Arduino Pin            | Notes                 |
| ------------------------------- | --------------- | ---------------------- | --------------------- |
| **Ultrasonic Sensor (HC-SR04)** | VCC             | 5V                     | Power supply          |
|                                 | GND             | GND                    | Common ground         |
|                                 | Trig            | D12                    | Trigger pin           |
|                                 | Echo            | D11                    | Echo pin              |
| **Servo Motor (SG90)**          | VCC (Red)       | 5V (Breadboard Rail)   | Power supply          |
|                                 | GND (Brown)     | GND (Breadboard Rail)  | Common ground         |
|                                 | Signal (Orange) | D13                    | Signal control pin    |
| **Red LED**                     | Anode (+, Long) | D7 (via 220Ω resistor) | Gate closed indicator |
|                                 | Cathode (–)     | GND                    |                       |
| **Green LED**                   | Anode (+, Long) | D6 (via 220Ω resistor) | Gate open indicator   |
|                                 | Cathode (–)     | GND                    |                       |
| **Arduino UNO**                 | 5V              | Breadboard power rail  | Power source          |
|                                 | GND             | Breadboard ground rail | Common ground         |
| **Resistors**         | (For LEDs)      | 220Ω – 330Ω           |

---

## 💾 Library Required

- `LiquidCrystal` library — *pre-installed* in the Arduino IDE.
- No external installation is needed.

---

## ✅ Expected Output

When an object (vehicle) is detected within 30 cm:
 • The servo motor rotates to 0°, simulating the gate opening.
 • The green LED turns on, indicating that the vehicle is allowed to pass.
 • The buzzer sounds, providing an audible alert of vehicle presence. 
• The vehicle counter increments, tracking each new vehicle detected .

---

## 🧠 Conclusion

This project involved creating and simulating an automated toll gate system using Arduino on Tinkercad. It 
provided practical experience with sensors, servo motors, and basic automation logic. The system showed 
how microcontrollers can effectively manage vehicle access. It also sets the stage for future improvements 
like adding RFID authentication, LCD displays, and IoT features for live monitoring and data handling.
