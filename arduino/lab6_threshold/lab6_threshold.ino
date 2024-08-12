float minV=10;
float maxV=0;
float threshold;
  
void setup() {
  Serial.begin(9600);
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

      Serial.println("frequency"+String(frequency));
    }

    i++;
  }
    
  previous = current;
}
