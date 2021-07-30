#include<Servo.h>
int trigPin=12;
int echoPin=11;
int pingTravelTime;
float pingTraveldistance;
float distanceToTarget;
Servo Xservo;

int   Xpin=7;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(Xpin,OUTPUT);
  
   Xservo.attach(Xpin);
   
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(trigPin,LOW);
   delayMicroseconds(10);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   pingTravelTime=pulseIn(echoPin,HIGH);
  pingTraveldistance=(pingTravelTime*539.*5280.*12)/(3600.*1000000);
     distanceToTarget=pingTraveldistance/2+1. ;
      Serial.print(distanceToTarget);
      Serial.println("  inches");
   delay(500);
   if(distanceToTarget>=5){
    Xservo.write(90);
   
   }
   if(distanceToTarget<=5){
    Xservo.write(0);
    delay(500);
     Xservo.write(90);
   
   
    
   }
}
