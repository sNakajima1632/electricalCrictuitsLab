void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3,3.0/5.0*255);
  float V = analogRead(A0)*5.0/1023;
  Serial.println(String(V));

  delay(1000);
}
