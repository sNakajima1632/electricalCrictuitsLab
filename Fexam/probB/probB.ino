volatile boolean buttonFlag = 0;
int digit = 1;
int input = 0;
int d1 = 0;
int d2 = 0;
int d3 = 0;
int bin = "000";

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  Serial.begin(9600);
  attachInterrupt(0,push,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
}


double start = 0.0;
double end = 0.0;

void push(){
  boolean state = digitalRead(2);

  if(state){
    start = millis();
  }
  else if(!state){
    end = millis();
    double diff = end-start;

    if(diff > 100 && diff < 1000){
      Serial.println("Binary Input: 0");
      input = 0;

    }
    else if(diff > 1000){
      Serial.println("Binary Input: 1");
      input = 1;
    }

    switch(digit){
      case 1:
        d1 = input;
        digit += 1;
        break;
      case 2:
        d2 = input;
        digit += 1;
        break;
      case 3:
        d3 = input;
        break;
    }
    
    if(digit > 2){
      bin = 100*d1+10*d2+d3;
      switch(bin){
        case 000:
          Serial.println("Decimal Input: 0");
          break;
        case 001:
          Serial.println("Decimal Input: 1");
          break;
        case 010:
          Serial.println("Decimal Input: 2");
          break;
        case 011:
          Serial.println("Decimal Input: 3");
          break;
        case 100:
          Serial.println("Decimal Input: 4");
          break;
        case 101:
          Serial.println("Decimal Input: 5");
          break;
        case 110:
          Serial.println("Decimal Input: 6");
          break;
        case 111:
          Serial.println("Decimal Input: 7");
          break;
      }
      digit = 1;
    }
  }

}
