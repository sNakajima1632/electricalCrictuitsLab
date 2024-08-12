void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float R = 3000.0;
  float Vsensor = analogRead(A0)*5.0/1023;//=5*Rsensor/(R+Rsensor); R+Rsensor=5*Rsensor/Vsensor; Rsensor(5/Vsensor-1)=R
  float Rsensor = 0;
  Rsensor = R/(5.0/Vsensor-1);

  Serial.println(Rsensor);
  delay(1000); 
}
