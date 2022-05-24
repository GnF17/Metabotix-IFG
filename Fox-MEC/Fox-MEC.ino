#include <Servo.h>

int sensorE = A2;  //Sensor Esquerda
int sensorC = A3;  //Sensor valorC 
int sensorD = A4;  //Sensor Direita

const int pinoServo = 4;
Servo servo;

/*
Preto: <500
Branco: >=500
*/

int valorCorte = 500;

int valorE, valorC, valorD;

const int motorA = 5; // velocidade motor A - de 0 a 255
const int motorB = 6; // velocidade motor B - de 0 a 255
const int dirA = 7; // direcao do motor A - HIGH ou LOW
const int dirB = 8; // direcao do motor B - HIGH ou LOW

/*
Direcoes:
  - dirA HIGH: tras
  - dirB LOW: tras
  - dirA LOW: frente
  - dirB HIGH: frente
*/

void tras() {
  digitalWrite(dirA, HIGH); // SENTIDO DE ROTACAO 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 200); // VELOCIDADE
  analogWrite(motorB, 200);
}

void frente() {
  digitalWrite(dirA, LOW); // SENTIDO DE ROTACAO 
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 200); // VELOCIDADE
  analogWrite(motorB, 200);
}

void direita() {
  digitalWrite(dirA, LOW); // SENTIDO DE ROTACAO 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 200); // VELOCIDADE
  analogWrite(motorB, 200);
}

void esquerda() {
  digitalWrite(dirA, HIGH); // SENTIDO DE ROTACAO 
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 200); // VELOCIDADE
  analogWrite(motorB, 200);
}

void rabo(){
  servo.write(135);
  delay(20);
  servo.write(45);
}

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  servo.attach(pinoServo);
  servo.write(45);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorE = analogRead(sensorE);
  valorC = analogRead(sensorC);
  valorD = analogRead(sensorD);
  if (valorE>=valorCorte && valorC>=valorCorte && valorD>=valorCorte){
    rabo();
    delay(100);
  } else{
    if (valorE<valorCorte && valorC<valorCorte && valorD<valorCorte){
      direita();
      delay(100);
      frente();
      delay(100);
    } else {
      if (valorE<valorCorte && valorC>=valorCorte && valorD>=valorCorte){
        esquerda();
        delay(50);
      } else {
        if (valorE>=valorCorte && valorC<valorCorte && valorD>=valorCorte){
          frente();
          delay(100);
        } else {
          if (valorE>=valorCorte && valorC>=valorCorte && valorD<valorCorte){
            direita();        
            delay(50); 
          }
        }
      }
    }
  }
}

/*
Portas:
  A1, A2 e A3: sensor IR
  velocidade motor A: 5
  velocidade motor B: 6
  direção motor A:  7
  direção motor B: 8
  servo motor: 4
  trig: 2
  echo: 3
*/
