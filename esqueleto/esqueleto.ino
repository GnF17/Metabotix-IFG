#include <Servo.h>

/*
Portas:
  LED: 5
  Sensor presenca: 4
  Servo 1: 2
  Servo 2: 3
*/
const int servo_1 = 2;
const int servo_2 = 3;
int sensor = 4;
int led = 5;
int botao = 6;

int valorSensor, valorBotao;

Servo servo1;
Servo servo2;

void abrir(){
  servo1.write(170);
  servo2.write(170);
  delay(500);
  servo1.write(0);
  servo2.write(0);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(sensor, INPUT);
  servo1.attach(servo_1);
  servo2.attach(servo_2);
  servo1.write(0);
  servo2.write(0);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  valorBotao = digitalRead(botao);
  valorSensor = digitalRead(sensor);
  Serial.println(valorSensor);
  //if (valorBotao==HIGH){
    if(valorSensor==1){
      digitalWrite(led, HIGH);
      abrir();
      digitalWrite(led, LOW);
    }
  //}

}
