volatile boolean buttonFlag = 0;
int mode = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),push,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  float R = 3000.0;
  float Vsensor = analogRead(A0)*5.0/1023;
  float Rsensor = 0;
  Rsensor = R/(5.0/Vsensor-1);

  switch(mode){
    case 1:
        if(Rsensor <= 3000){
          digitalWrite(4,HIGH);
        }
        else if(Rsensor > 3000 && Rsensor < 7000){
          digitalWrite(4,LOW); 
        }
        else if(Rsensor >= 7000){
          digitalWrite(4,HIGH);
          delay(500);
          digitalWrite(4,LOW);
          delay(500);
        }
      break;
    case 2:
        if(Rsensor <= 3000){
          digitalWrite(4,LOW);
        }
        else if(Rsensor > 3000 && Rsensor < 7000){
          digitalWrite(4,HIGH); 
        }
        else if(Rsensor >= 7000){
          digitalWrite(4,HIGH);
          delay(500);
          digitalWrite(4,LOW);
          delay(500);
        }
      break;
  }

  delay(10); 
}

void push(){
  boolean state = digitalRead(2);
  if(state){
    mode += 1;
    if(mode != 1){
      mode = 2;
    }
    Serial.println("b");
  }
  else{    
  }
}