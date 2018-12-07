int analogValue=0;
//GSR is on pin 3

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
}

void loop() {
  analogValue=analogRead(3);
  Serial.println(analogValue);
  delay(10);
}
