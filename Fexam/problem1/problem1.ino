char mode = 'F';

void setup()
{
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
Serial.begin(9600);
}

void loop()
{
delay(10); // Delay a little bit to improve simulation performance

  if(Serial.available()){
    char c = Serial.read();
    if(c == 'F' || c == 'S'){
      mode = c;
    }
  }

    if(mode == 'F'){
      Serial.println("fastmode");

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delay(250);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delay(250);

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delay(250);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delay(750);
    }

    else if(mode == 'S'){
      Serial.println("slowmode");

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delay(500);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delay(500);

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delay(500);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delay(1500);
    }
}