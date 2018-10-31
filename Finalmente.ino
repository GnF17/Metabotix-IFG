int sensorD= A2;
int sensorM= A1;
int sensorE= A0;
int valorSensorD;
int valorSensorE;
int valorSensorM;

const int x=990;
const int motorE = 5; 
const int motorD = 6; 
const int direcaoE = 7; 
const int direcaoD = 8;  

void leituraSensor(){
  valorSensorD= analogRead(sensorD);
  valorSensorM= analogRead(sensorM);
  valorSensorE= analogRead(sensorE);
}


void controle(String motor, int velocidade, int direcao){
  if(motor=="D"){
     analogWrite(motorD, velocidade);
     digitalWrite(direcaoD, direcao);
  }else if(motor=="E"){
     analogWrite(motorE, velocidade);
     digitalWrite(direcaoE, direcao);  
  }
 
}
void seguirReto(){
  controle("E", 100, HIGH);
  controle("D", 100, HIGH);
}
void virarDireita(){
  controle("E", 150, HIGH);
  controle("D", 100, HIGH);  
}
void virarEsquerda(){
  controle("E", 100, HIGH);
  controle("D", 190, HIGH);  
} 
void parar(){
  controle("E", 0, HIGH);
  controle("D", 0, HIGH);  
}
void tras(){
  controle("E", 180, LOW);
  controle("D", 180, LOW);  
}
void seguirLinha(){
  if(valorSensorE<x&&valorSensorM>x&&valorSensorD<x){
      seguirReto();
  }
  if(valorSensorE>x&&valorSensorM>x&&valorSensorD<x){
      virarEsquerda();
  }
  if(valorSensorE<x&&valorSensorM>x&&valorSensorD>x){
      virarDireita();
  }
  if(valorSensorE<x&&valorSensorM<x&&valorSensorD<x){
     parar();
  }
}
void andar(){
  leituraSensor();
  seguirLinha();
}

void setup() {
  pinMode(motorE, OUTPUT);
  pinMode(motorD, OUTPUT);
  pinMode(direcaoE, OUTPUT);
  pinMode(direcaoD, OUTPUT);
  digitalWrite(direcaoE,HIGH);
  digitalWrite(direcaoD,HIGH);
  Serial.begin(9600);
}


void loop(){
    andar();
    
}  


