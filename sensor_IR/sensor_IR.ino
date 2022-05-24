int sensorE = A2;  //Sensor Esquerda
int sensorCE = A3;  //Sensor Centro 
int sensorD = A4;  //Sensor Direita

/*
Preto: <500
Branco: >=500
*/

int esquerda, centro, direita;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //Serial.print("oi");
  Serial.print("E: ");
  Serial.println(analogRead(sensorE));
  delay(500);
  Serial.print("C: ");
  Serial.println(analogRead(sensorCE));
  delay(500);
  Serial.print("D: ");
  Serial.println(analogRead(sensorD));
  delay(500);
  esquerda = analogRead(sensorE);
  centro = analogRead(sensorCE);
  direita = analogRead(sensorD);
  if (esquerda>=500 && centro>=500 && direita>=500){
    Serial.println("Branco");
    delay(1000);
  } else{
    if (esquerda<500 && centro<500 && direita<500){
      Serial.println("Preto");
      delay(1000);
    } else {
      if (esquerda<500 && centro>=500 && direita>=500){
        Serial.print("Esquerda preto ");
        Serial.println(esquerda);
        delay(1000);
      } else {
        if (esquerda>=500 && centro<500 && direita>=500){
          Serial.print("Centro preto ");
          Serial.println(centro);
          delay(1000);
        } else {
          Serial.print("Direita preto ");
          Serial.println(direita);
          delay(1000);
        }
      }
    }
  }
  // put your main code here, to run repeatedly:

}
