//servo - 12
//ultrasonic - trig: 10, echo 11
//FB motor - pin1:2,3; pin2:4,5
//LR motor - pin1:6,7; pin3:8,9

#include<Servo.h>
Servo servo;
int angle = 90;
long duration;
int distance;
int x, y, z;

void setup() {
  for(int i=2; i<=10; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(11, INPUT);
  servo.attach(12);
  servo.write(angle);
}

int ping() {
  digitalWrite(10, LOW); delayMicroseconds(2); digitalWrite(10, HIGH); delayMicroseconds(10); digitalWrite(10, LOW);
  duration = pulseIn(11, HIGH); distance = duration * 0.034 / 2;
  return distance;
}

void forward() {digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, LOW); digitalWrite(5, LOW);}

void backward() {digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, LOW); digitalWrite(5, LOW);}

int sweep() {
  servo.write(0); x=ping();
  servo.write(90); y=ping();
  servo.write(180); z=ping();
  if (x<y and x<z){return 1;}
  if (y<x and y<z){return 2;}
  return 3;
}

void loop() {
}


 // scan from 0 to 180 degrees
  //for(angle = 0; angle < 180; angle++)  
  //{                                  
    //servo.write(angle);               
    //delay(15);                   
  //} 
  // now scan back from 180 to 0 degrees
  //for(angle = 180; angle > 0; angle--)    
  //{                                
    //servo.write(angle);           
    //delay(15);       
  //}
