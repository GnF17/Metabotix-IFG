#include <Servo.h>

const int pinoServo = 4;
Servo servo;

void rabo(){
  servo.write(135);
  delay(1000);
  servo.write(45);
}
void setup() {
  // put your setup code here, to run once:
  servo.attach(pinoServo);
  servo.write(45);
}

void loop() {
  // put your main code here, to run repeatedly:
  rabo();
  delay(1000);
}
