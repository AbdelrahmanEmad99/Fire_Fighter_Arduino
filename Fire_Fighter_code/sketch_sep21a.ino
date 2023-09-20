/*------ Arduino Fire Fighting Robot Code by hobby project---- */
 
#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;

const int RELAY_PIN = 11;// Vin
 
#define Right 8    // right sensor
#define Forward 9   //front sensor

#define LM1 7       // left motor
#define LM2 6       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
 
void setup()
{
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
 
  myservo.attach(12);
  myservo.write(90); 
}
 
void put_off_fire()  
{
    //delay (500);
 
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    
   digitalWrite(RELAY_PIN , HIGH);

    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  digitalWrite(RELAY_PIN,LOW);
  myservo.write(90);
  
  fire=false;

} 
void loop()
{
  
  digitalWrite(RELAY_PIN, LOW);
  //delay(500);

   myservo.write(90); //Sweep_Servo();  

if (digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
     fire = true;
    }
 
else if (digitalRead(Forward) ==0) 
    {
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
     fire = false;
    }
    
    else if (digitalRead(Forward) ==1 && digitalRead(Right)==0) 
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
   
    }
    
//delay(300);
//change this value to increase the distance
 
     while (fire == true)
     { 
      
      put_off_fire();
     }
}
