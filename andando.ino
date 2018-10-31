const int motorA = 5; //velocidade motor A - de 0 a 255
const int motorB = 6; //velocidade motor B - de 0 a 255
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);

}

void loop() {
 
  digitalWrite(dirA, HIGH); //SENTIDO DE ROTACAO
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 255); //VELOCIDADE
  analogWrite(motorB, 255);

}
