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
