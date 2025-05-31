int read;
int pmeter = A0;
int led = 6;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pmeter, INPUT);
}

void loop()
{
  read = analogRead(pmeter);
  read = map(read,0,1023,0,255);
  analogWrite(led,read/4);
}