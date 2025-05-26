int gassensor = 0;
const int gassensorPin = A0;
const int threshold = 400;
int green_led = 7;
int red_led = 6;
int buzzer_pin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  gassensor = analogRead(gassensorPin);
  Serial.print("Gas Sensor Reading: ");
  Serial.println(gassensor);

  if (gassensor > threshold) {
    // Gas leak detected
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, HIGH);
    digitalWrite(buzzer_pin, HIGH);
  } else {
    // Normal condition
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    digitalWrite(buzzer_pin, LOW);
  }
  
  delay(1000);
}