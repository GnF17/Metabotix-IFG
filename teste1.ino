const int motorA = 5; //velocidade motor A - de 0 a 255 - esquerdo
const int motorB = 6; //velocidade motor B - de 0 a 255 - direito
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW  
int Sensor1 = A0;
int Valor_Sensor1 = 0; 
int Sensor2 = A1; 
int Valor_Sensor2 = 0;
int Sensor3 = A2; 
int Valor_Sensor3 = 0;

void Frente(){
  analogWrite(motorA, 100); 
    analogWrite(motorB, 100);
}

void LadoDireito(){
   do {    
          analogWrite(motorA, 70); 
          analogWrite(motorB, 30);
          Valor_Sensor2 = analogRead(Sensor2);
          Valor_Sensor1 = analogRead(Sensor1);
        } while (Valor_Sensor2 < 980 && Valor_Sensor1 < 986);
}

void LadoEsquerdo(){
   do {
          analogWrite(motorA, 30); 
          analogWrite(motorB, 70);
          Valor_Sensor2 = analogRead(Sensor2);
          Valor_Sensor3 = analogRead(Sensor3);
       } while (Valor_Sensor2 < 980 && Valor_Sensor3 < 1000);
}

void Branco(){
  analogWrite(motorA, 0); 
    analogWrite(motorB, 0);
}

void Preto(){
  analogWrite(motorA, 0); 
    analogWrite(motorB, 150);
        delay (40);
}

void setup(){
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  digitalWrite(dirA, HIGH); 
  digitalWrite(dirB, HIGH);
  Serial.begin(9600);
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); 
  Valor_Sensor2 = analogRead(Sensor2); 
  Valor_Sensor3 = analogRead(Sensor3);
  Serial.println(Valor_Sensor1);
  if((Valor_Sensor1 < 986) && (Valor_Sensor2 >= 980) && (Valor_Sensor3 < 1000)){
  	  Frente();
  }
  
  if((Valor_Sensor1 >= 986) && (Valor_Sensor2 < 980) && (Valor_Sensor3 < 1000)){
      LadoEsquerdo();
  }
  
  if((Valor_Sensor1 < 986) && (Valor_Sensor2 < 980) && (Valor_Sensor3 >= 1000)){
      LadoDireito();
  }  
  if((Valor_Sensor1 < 986) && (Valor_Sensor2 < 980) && (Valor_Sensor3 < 1000)){
      Branco();  
  } 
  if((Valor_Sensor1 >= 986) && (Valor_Sensor2 >= 980) && (Valor_Sensor3 >= 1000)){
      Preto();
  } 
}
