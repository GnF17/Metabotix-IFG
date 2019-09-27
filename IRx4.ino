const int p1 = A1; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p2 = A2; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p3 = A3; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
const int p4 = A4; //PINO ANALÓGICO UTILIZADO PELO FOTOTRANSISTOR
int corte = 25; //3000 -> 1M Ohm 2500 -> 2M Ohm
int a,b,c,d, x;
const int motorA = 5; //velocidade motor A - de 0 a 255
const int motorB = 6; //velocidade motor B - de 0 a 255
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW  
const int Trigger = 12;
const int Echo = 13;
long cm, duration;

void frente(){
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 180);
  analogWrite(motorB, 180);
}
void direita(){
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 10);
  analogWrite(motorB, 230);
  delay(1500);
}
void esquerda(){
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 230);
  analogWrite(motorB, 10);
  delay(1500);
}
void parar(){
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 0);
  analogWrite(motorB, 0);
}
void ir(){
   a = analogRead(p1); //direita
   b = analogRead(p2); //esquerda
   c = analogRead(p3); //centro-direita
   d = analogRead(p4); //centro-esquerda
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
}

void loop(){
  ir(); //Maior que o corte = preto
  delay(1000);
  x = map(a, 0, 30, 0, 50);
  if (x<=corte) {
      Serial.print("Preto\t");
  } else {
       Serial.print("Branco\t");
  }
  Serial.print(x);
  Serial.print("\t");
  
  if (b<=corte){
      Serial.print("Preto\t");
  } else {
       Serial.print("Branco\t");
  }
  Serial.print(b);
  Serial.print("\t");
  
  if (c<=corte){
      Serial.print("Preto\t");
  } else {
       Serial.print("Branco\t");
  }
  Serial.print(c);
  Serial.print("\t");
  
  if (d<=corte){
      Serial.print("Preto\t");
  } else {
       Serial.print("Branco\t");
  }
  Serial.println(d);
  
  //int a = map(pinoFototransistor, 0, 255, 5, 15);
  //Serial.println(a);
  //Serial.println(map(analogRead(pinoFototransistor), 0, 1023, 0, 1));
 // 00==========if(analogRead(pinoFototransistor) < 250){ //SE A LEITURA DO PINO FOR MENOR QUE 800 BITS, FAZ
    //Serial.println("Recebendo sinal infravermelho"); //IMPRIME O TEXTO NA SERIAL
  //}else{ //SENÃO, FAZ
    //Serial.println("Sinal infravermelho interrompido"); //IMPRIME O TEXTO NA SERIAL
 // } */
 }
