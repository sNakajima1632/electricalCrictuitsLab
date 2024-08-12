
void setup() {

Serial.begin(9600); 
pinMode(A3, INPUT);

}

void loop() {

  // read the input on analog pin A3
double sensorValue = analogRead(A3);
float voltValue = sensorValue*5.0/1023;

  // print out the value you read:
Serial.println("[State 1] Press Button 1");
  // pause before reading again
delay(3000);
sensorValue = analogRead(A3);
voltValue = sensorValue*5.0/1023;

Serial.println("Voltage (in Volts) = " + String(voltValue));

delay(1000);

Serial.println("[State 2] Press Button 2");

delay(3000);
sensorValue = analogRead(A3);
voltValue = sensorValue*5.0/1023;

Serial.println("Voltage (in Volts) = " + String(voltValue));

delay (1000);

Serial.println("[State 3] Press both buttons");

delay(3000);
sensorValue = analogRead(A3);
voltValue = sensorValue*5.0/1023;

Serial.println("Voltage (in Volts) = " + String(voltValue));

delay(1000);

Serial.println("[State 4] Don't press any button");

delay(3000);
sensorValue = analogRead(A3);
voltValue = sensorValue*5.0/1023;

Serial.println("Voltage (in Volts) = " + String(voltValue));
}
