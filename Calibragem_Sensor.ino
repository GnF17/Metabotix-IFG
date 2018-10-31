int SensorD= A2;
int SensorM= A1;
int SensorE= A0;
int ValorSensorD;
int ValorSensorE;
int ValorSensorM;
int cont=0;
void LeituraSensor(){
  ValorSensorD= analogRead(SensorD);
  ValorSensorM= analogRead(SensorM);
  ValorSensorE= analogRead(SensorE);
}
void ExibirValores(){ 
    Serial.print("\t");
    Serial.print(ValorSensorD);
    Serial.print("\t");
    Serial.print(ValorSensorM); 
    Serial.print("\t");
    Serial.println(ValorSensorE);  
}
void setup() { 
  Serial.begin(9600);
  Serial.println("CALIBRAGEM DOS SENSORES DE REFLETÂNCIA");
  Serial.println("\t D \t M \t E ");
}

void loop() {
  if(cont==10){
     Serial.println("CALIBRAGEM DOS SENSORES DE REFLETÂNCIA");
     Serial.println("\t D \t M \t E "); 
     cont=0;
  }
  LeituraSensor();
  ExibirValores();
  delay(1000);
  cont = cont+1;
}
