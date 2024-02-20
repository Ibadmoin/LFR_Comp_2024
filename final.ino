#define MS A1      // Middle Sensor
#define LS A2      // Left sensor
#define RS A0      // Right sensor

#define LM1 5       // left motor
#define LM2 6       // left motor
#define RM1 7       // right motor
#define RM2 8       // right motor

#define ENA 9      // Enable for left motor
#define ENB 10     // Enable for right motor


void setup()
{
  Serial.begin(9600);
  pinMode(MS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  digitalWrite(ENA, HIGH); // Enable left motor
  digitalWrite(ENB, HIGH); // Enable right motor

}

void loop()
{

  if(digitalRead(MS))     // Middle Sensor On Line
  {
    if(!digitalRead(LS) && !digitalRead(RS)) //LS and RS not on line
    {
    Serial.println("move forward");
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    }
    else if(digitalRead(LS) && !digitalRead(RS)) //Sharp Left
    {
    Serial.println("Sharp Left");
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW); 
    digitalWrite(RM2, HIGH);
    }
    else if(!digitalRead(LS) && digitalRead(RS)) //Sharp Right
    {
    Serial.println("Sharp Right");
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    else if(digitalRead(LS) && digitalRead(RS)) 
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    Serial.println("Stop");
    }
  }
  else
  {
  if(digitalRead(LS) && !digitalRead(RS))     // Turn left
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW); 
    digitalWrite(RM2, HIGH);
    Serial.println("Left");
  }
  else if(!digitalRead(LS) && digitalRead(RS))     // turn right
  {
    digitalWrite(LM1, LOW); 
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    Serial.println("Right");
  } 
    else if(!digitalRead(LS) && !digitalRead(RS))     // turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  }
  delay(5);
}
