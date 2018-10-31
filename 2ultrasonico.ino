#include <Ultrasonic.h>

  const int pingTrigger1 = 10;
  const int pingTrigger2 = 12;
  const int Sensor_1 = 11; //baixo
  const int Sensor_2 = 13; //cima
  long duration,cm,cme;
  const int motorA = 5; //velocidade motor A - de 0 a 255 esquerdo
  const int motorB = 6; //velocidade motor B - de 0 a 255 direito
  const int dirA = 7; //direcao do motor A - HIGH ou LOW esquerdo
  const int dirB = 8; //direcao do motor B - HIGH ou LOW  direito
  const int ligaDesliga = 2;
  int Sensor1 = 1; //esquerdo
  int Valor_Sensor1 = 0; 
  int Sensor2 = 0; //direito
  int Valor_Sensor2 = 0;

void AndandoFrente(){
  analogWrite(motorA, 98); 
  analogWrite(motorB, 123);
}

void Parar(){
  analogWrite(motorA, 0); 
  analogWrite(motorB, 0);   
}

void VirarDireita(){
  analogWrite(motorA, 98); 
  analogWrite(motorB, 153);
  delay(100);
}

void SensorBaixo() {
  digitalWrite(pingTrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrigger1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrigger1, LOW);
  duration = pulseIn(Sensor_1, HIGH);
  Serial.println("Sensor 1");
  cm = duration/58;
  Serial.print(cm);
  Serial.println();
}

void SensorCima(){
  digitalWrite(pingTrigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrigger2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrigger2, LOW);
  duration = pulseIn(Sensor_2, HIGH);
  cme = duration/58;
  Serial.println("Sensor 2");
  Serial.print(cm);
  Serial.println();
  delay(100);
}

void setup() {

   pinMode(pingTrigger1, OUTPUT);
   pinMode(pingTrigger2, OUTPUT);
   pinMode(Sensor_1, INPUT);
   pinMode(Sensor_2, INPUT);
   pinMode(motorA, OUTPUT);
   pinMode(motorB, OUTPUT);
   pinMode(dirA, OUTPUT);
   pinMode(dirB, OUTPUT);
   pinMode(ligaDesliga, INPUT);
   digitalWrite(dirA, HIGH); 
   digitalWrite(dirB, HIGH);
   Serial.begin(9600);
}

void loop() {
  
    AndandoFrente();
    SensorBaixo();
    if (cm<10){
        Parar();
        SensorCima();
        if(cme<10){
          VirarDireita();
        } else {
//          usa a garra;
          }
    }
  delay(10);
}
