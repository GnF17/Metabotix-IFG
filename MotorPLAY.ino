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

void Controle(int Motor, int Velocidade, int Direcao){
  if(Direcao==1){
    digitalWrite(Motor,HIGH);
  }else{
    digitalWrite(Motor,HIGH);
  }
  if(Velocidade==0){
    analogWrite(Motor,0);
  }else{
    analogWrite(Motor,Velocidade);
  }
  
}
void SeguirReto(){
  Controle(MotorE, 154, 1);
  Controle(MotorD, 209, 0);
}
void VirarDireita(){
  Controle(MotorE, 150, 1);
  Controle(MotorD, 100, 1);  
}
void VirarEsquerda(){
  Controle(MotorE, 100, 1);
  Controle(MotorD, 150, 1);  
} 
void Parar(){
  Controle(MotorE, 0, 1);
  Controle(MotorD, 0, 1);  
}
void Tras(){
  Controle(MotorE, 180, 1);
  Controle(MotorD, 180, 1);  
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
  digitalWrite(direcaoE, HIGH); 
  digitalWrite(direcaoD, HIGH);
  Serial.begin(9600);
  Guia();
}

void loop() {
  
  SeguirReto();
  
}
