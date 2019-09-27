#include <Ultrasonic.h>
#include <SoftwareSerial.h>

const int p1 = A1; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p2 = A2; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p3 = A3; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p4 = A4; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
int corte = 25; //3000 -> 1M Ohm 2500 -> 2M Ohm
const int motorA = 5; //velocidade motor A - de 0 a 255
const int motorB = 6; //velocidade motor B - de 0 a 255
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW  
const int Trigger = 12;
const int Echo = 13;
long cm, duration;
int a,b,c,d,x,red,grn,blu;
#define sio      6           // ColorPAL 
#define unused   255         // Pino não existente # para SoftwareSerial
#define sioBaud  4800
SoftwareSerial serin(sio, unused); // Seta 2 softwares seriais no mesmo pino 
SoftwareSerial serout(unused, sio);

void frente(){
  digitalWrite(dirA, LOW); 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 180);
  analogWrite(motorB, 180);
}
void direita(){
  digitalWrite(dirA, LOW); 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 50);
  analogWrite(motorB, 230);
 // delay(1500);
}
void esquerda(){
  digitalWrite(dirA, LOW); 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 230);
  analogWrite(motorB, 50);
  //delay(1500);
}
void parar(){
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 0);
  analogWrite(motorB, 0);
}
void ir(){
  x = analogRead(p1); //direita
  a = map(x, 0, 30, 0, 100);
  b = analogRead(p2); //esquerda
  c = analogRead(p3); //centro-direita
  d = analogRead(p4); //centro-esquerda
}
void ultrassonico(){
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(Trigger, LOW);
  duration = pulseIn(Echo, HIGH);
  cm = duration/58;
}
void desviar(){
  parar();
  delay(500);
  esquerda();
  delay(450);
  frente();
  delay(500);
  parar();
  delay(200);
  direita();
  delay(450);
  frente();
  delay(500);
  parar();
  delay(500);
  direita();
  delay(450);
  frente();
  delay(300);
  parar();
  delay(200);
  esquerda();
  delay(450);
  frente();
  delay(100);
}
void reset() { // Reset ColorPAL
  delay(200);
  pinMode(sio, OUTPUT);
  digitalWrite(sio, LOW);
  pinMode(sio, INPUT);
  while (digitalRead(sio) != HIGH);
  pinMode(sio, OUTPUT);
  digitalWrite(sio, LOW);
  delay(80);
  pinMode(sio, INPUT);
  delay(200);
}
void readData() {
  char buffer[32];
 
  if (serin.available() > 0) {
    // Espera pelo $ e então lê os 3 próximos números hex
    buffer[0] = serin.read();
    if (buffer[0] == '$') {
      for(int i = 0; i < 9; i++) {
        while (serin.available() == 0);     // Espera pelo próximo caracter
        buffer[i] = serin.read();
        if (buffer[i] == '$')               // Retorna cedo se achar o $
          return;
      }
      parseAndPrint(buffer);
      delay(10);
    }
  }
}
void parseAndPrint(char * data) {
  // Converte dados hex em inteiros 
  sscanf (data, "%3x%3x%3x", &red, &grn, &blu);  // Pega os valores R, G e B da string
}
void cor(){
  readData();
  if (grn>0000 && grn<=0010){
    return true; //Retorna true se for verde 
  }
}
              
void setup(){
  Serial.begin(9600); //INICIALIZAÇÃO DA SERIAL
  pinMode(p1, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  reset();                    // Reseta ColorPal
  serout.begin(sioBaud);
  pinMode(sio, OUTPUT);
  //serout.print("=(00 $ m)!"); // Loop print valores
  serout.end();               // Interrompe transmissão para a porta serial 
  pinMode(sio, INPUT);
  serin.begin(sioBaud);       // Configura a porta serial para recebimento
}

void loop(){
  ir(); //Menor que o corte = preto
  ultrassonico(); 
  if (cm<=20){
    desviar();
  }
  if (c<=corte && d<=corte && a>corte && b>corte && cm>20){ //FRENTE
    frente();
  }
  if (a<=corte && c<=corte && b>corte && d>corte){ //DIREITA
    direita();
  }
  if (b<=corte && d<=corte && a>corte && c>corte){ //ESQUERDA
    esquerda();
  }
  if (c>corte && d>corte && a>corte && b>corte){ //PARAR
    parar();
  }
 }
