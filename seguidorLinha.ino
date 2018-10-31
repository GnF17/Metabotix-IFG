//Standard PWM DC control
int M1 = 5;
int E1 = 7;  //Ele so vai pra tras
int E2 = 8;
int M2 = 6;

int sensorE = A0;  //Sensor Esquerda
int sensorCE = A1;  //Sensor Centro 
int sensorD = A2;  //Sensor Direita

int valorCorte = 999;
int vel = 150;

int valorCE, valorE, valorD = 0;

void setup(){
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop(){
  valorCE = analogRead(sensorCE);
  valorE = analogRead(sensorE);
  valorD = analogRead(sensorD);
  
  if((valorCE > valorCorte)){ //Andar na linha
    analogWrite(E1, vel);
    analogWrite(E2, vel);
    
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
  
  }
  
  if((valorCE < valorCorte) && (valorD > valorCorte)){  //Virar para direita
    analogWrite(E1, 70);
    analogWrite(E2, 30);
    
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
  
  }
  
  if((valorCE < valorCorte) && (valorE > valorCorte)){  //Virar para esquerda
    analogWrite(E1, 30);
    analogWrite(E2, 70);
    
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
  
  }
  /*
  if((valorCE > valorCorte) && (valorCD > valorCorte) && (valorD > valorCorte)){
    analogWrite(E1, vel);
    analogWrite(E2, vel);
    
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    delay(500);
  }
  if((valorCE > valorCorte) && (valorCD > valorCorte) && (valorE > valorCorte)){
    analogWrite(E1, vel);
    analogWrite(E2, vel);
    
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    delay(500);
  }*/
}
