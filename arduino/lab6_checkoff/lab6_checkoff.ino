#define D1 12 //Display digit 1 control
#define segA  4 //Display segment A control
#define segB  5 //Display segment B control
#define segC  6 //Display segment C control
#define segD  7 //Display segment D control
#define segE  8 //Display segment E control
#define segF  9 //Display segment F control
#define segG  10 //Display segment G control
boolean digit0[] = {0, 0, 0, 0, 0, 0, 1};
boolean digit1[] = {1, 0, 0, 1, 1, 1, 1};
boolean digit2[] = {0, 0, 1, 0, 0, 1, 0};
boolean digit3[] = {0, 0, 0, 0, 1, 1, 0};
boolean digit4[] = {1, 0, 0, 1, 1, 0, 0};
boolean digit5[] = {0, 1, 0, 0, 1, 0, 0};
boolean digit6[] = {0, 1, 0, 0, 0, 0, 0};
boolean digit7[] = {0, 0, 0, 1, 1, 1, 1};
boolean digit8[] = {0, 0, 0, 0, 0, 0, 0};
boolean digit9[] = {0, 0, 0, 0, 1, 0, 0};
#define digit_pause 50
int segments[] = {segA, segB, segC, segD, segE, segF, segG};

float minV=10;
float maxV=0;
float threshold;
  
void setup() {
  Serial.begin(9600);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(D1, OUTPUT);
  digitalWrite(D1,LOW);
  for(int seg = 0; seg < 7; seg++){
    digitalWrite(segments[seg],HIGH);
  }

  pinMode(A3, INPUT);
  int j=0;
  while(j<100){
    int sensorValue = analogRead(A3);
    float read = sensorValue*5.0/1023;
    if(read<minV){
      minV = read;
    }
    j++;
    delay(10);
  }
  j=0;
  while(j<100){
    int sensorValue = analogRead(A3);
    float read = sensorValue*5.0/1023;
    if(read>maxV){
      maxV = read;
    }
    j++;
    delay(10);
  }
threshold = (minV+maxV)/2;
Serial.println(threshold);
}

float previous = 0;
float t[2];
int i = -1;
float period = 0;
float frequency = 0;
int displayF = 0;

void loop() {
  delay(100);
  int sensorValue = analogRead(A3);
  float current = sensorValue*5.0/1023;

  if(current > threshold && previous <= threshold){
    i = abs(i%2);
    t[i] = millis();
    if(i>0){
      period = abs(t[0]/1000 - t[1]/1000);
      frequency = 1/period;
      displayF = int(frequency+0.5);

      Serial.println("frequency"+String(frequency));
    }

    i++;
  }

  digitalWrite(D1,HIGH);
  dispNum(displayF);
    
  previous = current;
}

void dispNum(int num)
{
  switch (num){
    case 0:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit0[i]);
    }
    break;

    case 1:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit1[i]);
    }
    break;

    case 2:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit2[i]);
    }
    break;

    case 3:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit3[i]);
    }
    break;

    case 4:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit4[i]);
    }
    break;

    case 5:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit5[i]);
    }
    break;

    case 6:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit6[i]);
    }
    break;

    case 7:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit7[i]);
    }
    break;

    case 8:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit8[i]);
    }
    break;

    case 9:
    for(int i = 0; i< 7; i++) {
      digitalWrite(segments[i],digit9[i]);
    }
    break;
  }
}