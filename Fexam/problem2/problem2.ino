void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

int change = 0;
float prev = 0.0;

void loop() {
  // put your main code here, to run repeatedly:
  double sensorValue = analogRead(A0);
  float potV = sensorValue*5.0/1023;

  Serial.println(potV);
  if(abs(prev-potV) < 0.1){
    Serial.println("NO CHANGE");
  }

  delay(1000);
  prev = potV;
}
