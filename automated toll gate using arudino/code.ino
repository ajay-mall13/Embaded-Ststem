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