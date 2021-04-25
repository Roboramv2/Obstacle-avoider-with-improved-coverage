//FB motor - A2, A3
//LR motor - A0, A1
//servo (0, 90, 180) = (right, front, left)

#define ENA 3
#define ENB 5
#define trig 10
#define echo 11
#define ser 12

#include<Servo.h>
Servo servo;
int angle = 90;
long duration;
int distance;
int x, y, z;
int d;
int dir;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(ser);
  servo.write(angle);
  digitalWrite(ENB, LOW);
  digitalWrite(2, HIGH);
}

int ping() {
  digitalWrite(10, LOW); delayMicroseconds(2); digitalWrite(10, HIGH); delayMicroseconds(10); digitalWrite(10, LOW);
  duration = pulseIn(11, HIGH); distance = duration * 0.034 / 2;
  return distance;
}

void backward() {digitalWrite(ENA, HIGH); digitalWrite(A2, HIGH); digitalWrite(A3, LOW);}
void forward() {digitalWrite(ENA, HIGH); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);}
void left() {digitalWrite(ENB, HIGH); digitalWrite(A0, HIGH); digitalWrite(A1, LOW);}
void right() {digitalWrite(ENB, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, HIGH);}
void br() {digitalWrite(ENA, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);}

int sweep() {
  servo.write(0); x=ping();
  delay(1500);
  servo.write(90); y=ping();
  delay(1500);
  servo.write(180); z=ping();
  delay(1500);
  servo.write(90);
  if (x<z){return 1;}else if (z<x){return 2;}
}

void loop() {
  delay(500);
  d = ping();
  if(d>20) {
    forward();
    delay(2000);
  } else if(d<20) {
    br();
    dir = sweep();
    if (dir==1) {
      left();
      forward();
    }else if(dir == 2) {
      right();
      forward();
    }
  }
}
