float vx = 0;
float vy = 0;
float vz = 0;

float offsetx = 0;
float offsety = 0;
float offsetz = 0;
float sensx = 0;
float sensy = 0;
float sensz = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  float calibx = 0;
  float caliby = 0;
  float calibz = 0;
  float z0 = 0;
  float y0 = 0;
  float x0 = 0;
  float z1 = 0;
  float y1 = 0;
  float x1 = 0;

  Serial.println("About to start calibration");
  delay(2000);
  
  Serial.println("Keep accelerometer steady in horizontal position");
  delay(2000);  
  Serial.println("Do not move");
  for(int t = 0; t < 20; t++){
    vx = analogRead(A2)*5.0/1023;
    vy = analogRead(A1)*5.0/1023;
    vz = analogRead(A0)*5.0/1023;
    
    calibx += vx;
    caliby += vy;
    calibz += vz;

    delay(100);
  }
  calibx = calibx/20.0;
  caliby = caliby/20.0;
  calibz = calibz/20.0;
  x0 = calibx;
  y0 = caliby;
  z1 = calibz;

  Serial.println("Place accelerometer with X-axis pointing upwards");
  delay(5000);
  calibx = 0;
  caliby = 0;
  calibz = 0;
  Serial.println("Do not move");
  for(int t = 0; t < 20; t++){
    vx = analogRead(A2)*5.0/1023;
    vz = analogRead(A0)*5.0/1023;
    
    calibx += vx;
    calibz += vz;

    delay(100);
  }
  calibx = calibx/20.0;
  calibz = calibz/20.0;
  x1 = calibx;
  z0 = calibz;
  
  Serial.println("Place accelerometer with Y-axis pointing upwards");
  delay(5000);
  calibx = 0;
  caliby = 0;
  calibz = 0;
  Serial.println("Do not move");
  for(int t = 0; t < 20; t++){
    vy = analogRead(A1)*5.0/1023;
    
    caliby += vy;

    delay(100);
  }
  caliby = caliby/20.0;
  y1 = caliby;

  offsetx = x0;
  offsety = y0;
  offsetz = z0;
  sensx = x1-x0;
  sensy = y1-y0;
  sensz = z1-z0;

  Serial.println("xoffset: " + String(offsetx) + ", yoffset: " + String(offsety) + ", zoffset: " + String(offsetz));
  Serial.println("xsensitivity: " + String(sensx) + ", ysensitivity: " + String(sensy) + ", zsensitivity: " + String(sensz));
  Serial.println("Calibration complete. Now displaying acceleration data in X, Y, and Z axis.");

  /*hard code sens and offset
  offsetx = 1.61;
  offsety = 1.59;
  offsetz = 1.62;

  sensx = 0.06;
  sensy = 0.07;
  sensz = 0.06;
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  float ax = 0;
  float ay = 0;
  float az = 0;

  float axytan[200];

  float diff = 0;
  int zeroCount = 0;
  int crossCount = 0;

  Serial.println("start movement within 5 seconds");
  delay(5000);

  for(int i=0;i<200;i++){    
    vx = analogRead(A2)*5.0/1023;
    vy = analogRead(A1)*5.0/1023;
    vz = analogRead(A0)*5.0/1023;
 
    ax = (vx-offsetx)/sensx;
    ay = (vy-offsety)/sensy;
    az = (vz-offsetz)/sensz;

    axytan[i] = ay/ax;
    //Serial.println(axytan[i]);
    
    delay(50);
  }

  delay(50);

  for(int j=0;j<198;j++){
    diff = axytan[j+1] - axytan[j];
    Serial.println(diff);
    if(diff < 0.5 && diff > -0.5){
      zeroCount += 1;
    }    
    if(axytan[j+1] < 0 && axytan[j] > 0){
      crossCount += 1;
    }
    delay(10);
  }

  if(zeroCount > 150){
    Serial.println("no motion");
  }
  else if(zeroCount < crossCount + 10 && zeroCount > crossCount - 10){
    Serial.println("circular motion");
  }
  else{
    Serial.println("reciprocating motion");
  }
}
