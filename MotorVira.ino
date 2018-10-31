 String val;

  const int motorE = 5; //velocidade motor A - de 0 a 255 esquerdo
  const int motorD = 6; //velocidade motor B - de 0 a 255 direito
  const int dirE = 7; //direcao do motor A - HIGH ou LOW esquerdo
  const int dirD = 8; //direcao do motor B - HIGH ou LOW  direito

void setup() {
  pinMode(motorE, OUTPUT);
  pinMode(motorD, OUTPUT);
  pinMode(dirD, OUTPUT);
  pinMode(dirD, OUTPUT); //>1010 - preto

  digitalWrite(dirD, HIGH); 
  digitalWrite(dirE, HIGH);
  delay(3000);
  Serial.begin(9600);
  
}

void loop() {
  
    Serial.println("Digita: ");
    val=Serial.read();
    
  switch (val) {
    case 'w': 
     analogWrite(motorE,150);
     analogWrite(motorD,150);
     break;
    case 'a': 
     analogWrite(motorD,120);
     analogWrite(motorE,70);
     break;
    case 'd':
     analogWrite(motorD,70);
     analogWrite(motorE,120);
     break;
    case 's':
     analogWrite(motorE,0);
     analogWrite(motorD,0);
     break;
    
 }
 
}





