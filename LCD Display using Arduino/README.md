# 📟 LCD Display Project with Arduino

This project demonstrates how to interface a **16x2 LCD** with an **Arduino Uno** using the built-in `LiquidCrystal` library. It displays dynamic messages and showcases features like blinking cursors, hiding text, and clearing the screen.

---

## 🔌 Circuit Diagram

The circuit was designed and simulated using **Tinkercad**.

![LCD Arduino Tinkercad Circuit](https://github.com/user-attachments/assets/c2770dc1-c54e-4e82-a084-8f1fbeea1ede)

---

## 🧰 Components Required

| Component                    | Quantity |
|------------------------------|----------|
| Arduino UNO                  | 1        |
| 16x2 LCD Display             | 1        |
| 10k Potentiometer (for contrast) | 1    |
| Breadboard                   | 1        |
| Jumper Wires                 | 10+      |
| USB Cable                    | 1        |

---

## 💻 Arduino Code

```cpp
#include <LiquidCrystal.h>


LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

void setup() {
  LCD.begin(16, 2);   
  LCD.home();         
}

void loop() {
  LCD.blink();                        
  LCD.cursor();                      
  LCD.setCursor(2, 0);                
  LCD.print("Welcome Sure");        
  delay(1000);

  LCD.setCursor(0, 1);                
  LCD.print("Trust ProEd");          
  delay(1000);

  LCD.noBlink();                      
  LCD.noCursor();                    
  LCD.noDisplay();                    
  delay(1000);

  LCD.display();                     
  LCD.clear();                        
}
```

---

## 🚀 How to Run

### 🔧 Hardware Setup

- Connect the LCD to Arduino as per the pin mapping below.
- Use a **10k potentiometer** to adjust the contrast by connecting:
  - **Middle pin** → LCD **VO pin**
  - **One side pin** → **GND**
  - **Other side pin** → **5V**

---

### 🖧 Wiring Table

| LCD Pin | Arduino Pin                      |
|---------|----------------------------------|
| RS      | 12                               |
| E       | 11                               |
| D4      | 5                                |
| D5      | 4                                |
| D6      | 3                                |
| D7      | 2                                |
| VSS     | GND                              |
| VDD     | 5V                               |
| VO      | Middle pin of 10k potentiometer  |
| RW      | GND                              |
| LED+    | 220Ω → 5V                         |
| LED-    | GND                              |

---

## 💾 Library Required

- `LiquidCrystal` library — *pre-installed* in the Arduino IDE.
- No external installation is needed.

---

## ✅ Expected Output

- A **blinking cursor** appears on the display.
- The LCD displays:
  - `"Welcome Sure"` (first line)
  - `"Trust ProEd"` (second line)
- Then:
  - The display turns **off briefly**.
  - Comes back **on**, then **clears** the screen.

---

## 🧠 Conclusion

This project introduces basic control over a 16x2 LCD using the Arduino Uno. It’s ideal for beginners to learn:
- Display control
- Cursor behavior
- Text positioning

You can extend it further with sensors or inputs for interactive displays. Using **Tinkercad** simulation helps test the circuit before implementing it physically.
