const int MotorE = 5; 
const int MotorD = 6; 
const int direcaoE = 7; 
const int direcaoD = 8;  

byte Direcao;
void Play(){
  if (Serial.available() > 0){
    Direcao = Serial.read();  
    switch (Direcao){
      case 'w':
       SeguirReto();
       break;
      case 'a': 
       VirarEsquerda();
       break;
      case 'd':
       VirarDireita();
       break;
      case 'p':
       Parar();
       break;   
      case 's':
       Tras();
       break; 
    }
  }  
}

void Controle(String Motor, int Velocidade, int Direcao){
  if(Motor=="D"){
     analogWrite(MotorD, Velocidade);
     digitalWrite(direcaoD, Direcao);
  }else if(Motor=="E"){
         analogWrite(MotorE, Velocidade);
         digitalWrite(direcaoE, Direcao);  
  }
 
}
void SeguirReto(){
  Controle("E", 150, HIGH);
  Controle("D", 150, HIGH);
}
void VirarDireita(){
  Controle("E", 150, HIGH);
  Controle("D", 100, HIGH);  
}
void VirarEsquerda(){
  Controle("E", 100, HIGH);
  Controle("D", 150, HIGH);  
} 
void Parar(){
  Controle("E", 0, HIGH);
  Controle("D", 0, HIGH);  
}
void Tras(){
  Controle("E", 180, LOW);
  Controle("D", 180, LOW);  
}
void Guia(){
  Serial.println("\t\t FRENTE \n\t\t   W");
  Serial.println("\t ESQUERDA\t DIREITA\n\t  A  \t\t  D");
  Serial.println("\t\t  TRAS \n\t\t   S");
}
void setup() {
 
  pinMode(MotorE, OUTPUT);
  pinMode(MotorD, OUTPUT);
  pinMode(direcaoE, OUTPUT);
  pinMode(direcaoD, OUTPUT);
  digitalWrite(direcaoE,HIGH);
  digitalWrite(direcaoD,HIGH);
  Serial.begin(9600);
  Guia();
}

void loop() {
  
  Play();
  
}
