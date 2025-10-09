#include <Servo.h>

const int LDRCE = A0; //LDR Cima Esquerda cinza D
const int LDRCD = A1; //LDR Cima Direita branco C
const int LDRBE = A2; //LDR Baixo Esquerda amarelo B
const int LDRBD = A3; //LDR Baixo Direita roxo A
const int servoOrigem = 0;

Servo servoEixoY;
Servo servoEixoX;

void setup(){
  servoEixoX.attach(6);
  servoEixoY.attach(9);
  pinMode(LDRBE, INPUT);
  pinMode(LDRBD, INPUT);
  pinMode(LDRCE, INPUT);
  pinMode(LDRCD, INPUT);
  Serial.begin(9600);
  servoEixoY.write(servoOrigem);
  servoEixoX.write(servoOrigem);
}

void loop(){
  int luzBaixoEsq = analogRead(LDRBE);
  int luzBaixoDir = analogRead(LDRBD);
  int luzCimaEsq = analogRead(LDRCE);
  int luzCimaDir = analogRead(LDRCD);
  int posY = servoEixoY.read();
  int posX = servoEixoX.read();
  
  Serial.print("Luz Baixo Esquerda: ");
  Serial.println(luzBaixoEsq);
  Serial.print("Luz Baixo Direita: ");
  Serial.println(luzBaixoDir);
  Serial.print("Luz Cima Esquerda: ");
  Serial.println(luzCimaEsq);
  Serial.print("Luz Cima Direita: ");
  Serial.println(luzCimaDir);
  
  //Controle parábola
  if(((luzCimaEsq + luzCimaDir) < (luzBaixoEsq + luzBaixoDir)) && posX >= 0){
    posX++;
	  servoEixoX.write(posX);
  	Serial.print("Posicao X: ");
    Serial.println(posX);
  }
  else if(((luzCimaEsq + luzCimaDir) > (luzBaixoEsq + luzBaixoDir)) && posX <= 180){
    posX--;
  	servoEixoX.write(posX);
    Serial.print("Posicao X: ");
    Serial.println(posX);
  }
  
  //Controle circunferência
  if(((luzBaixoEsq + luzCimaEsq) > (luzBaixoDir + luzCimaDir)) && posY >= 0){
    posY--;
	  servoEixoY.write(posY);
  	Serial.print("Posicao Y: ");
    Serial.println(posY);
  }
  else if(((luzBaixoEsq + luzCimaEsq) < (luzBaixoDir + luzCimaDir)) && posY <= 180){
    posY++;
  	servoEixoY.write(posY);
    Serial.print("Posicao Y: ");
    Serial.println(posY);
  }
  if(posY >= 180 || posY <= 0){
    servoEixoY.write(servoOrigem);
    servoEixoX.write(servoOrigem);
  }
  if(posX >= 180 || posX <= 0){
    servoEixoY.write(servoOrigem);
    servoEixoX.write(servoOrigem);
  }
  delay(200);
}