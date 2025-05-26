#define echo_pin 3
#define trigger_pin 4

long duration;
int distance;

void setup() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a 10us pulse to trigger pin
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  // Read the duration of echo pulse
  duration = pulseIn(echo_pin, HIGH);

  // Calculate distance in cm (speed of sound is 343 m/s)
  distance = duration * 0.034 / 2;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Optional: Wait half a second before next reading
}
