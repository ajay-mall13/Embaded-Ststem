// C++ code
//
int switchPin = 12;
int ledPin = 8;
int switchState = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop()
{
  switchState = digitalRead(switchPin);
  if(switchState == HIGH){
    Serial.println("Switch is on");
    digitalWrite(ledPin,HIGH);
  }
  else{
    Serial.println("Switch is off");
    digitalWrite(ledPin,LOW);
  }
}