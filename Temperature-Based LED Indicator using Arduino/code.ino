const int tempPin = A0;


const int ledYellow = 4;
const int ledGreen = 5;
const int ledBlue = 6;
const int ledRed = 7;

void setup() {
  Serial.begin(9600);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  int reading = analogRead(tempPin);
  float voltage = reading * 4.68 / 1024.0;  
  float temperatureC = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Reset all LEDs
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, LOW);

  // Temperature-based LED logic
  if (temperatureC >= -40 && temperatureC < 1) {
    digitalWrite(ledYellow, HIGH);  // Cold
  } else if (temperatureC >= 1 && temperatureC <= 50) {
    digitalWrite(ledGreen, HIGH);   // Normal
  } else if (temperatureC >= 51 && temperatureC <= 75) {
    digitalWrite(ledBlue, HIGH);    // Warm
  } else if (temperatureC > 75) {
    digitalWrite(ledRed, HIGH);     // Hot
  }

  delay(1000); // 1-second delay
}
