#include <Servo.h>

const int LDRBE = A0; //LDR Baixo Esquerda
const int LDRBD = A1; //LDR Baixo Direita
const int LDRCE = A2; //LDR Cima Esquerda
const int LDRCD = A3; //LDR Cima Direita
const int servoOrigem = 90;

Servo servoEixoY;
Servo servoEixoX;

void setup(){
  servoEixoX.attach(7);
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
  if((luzCimaEsq > luzCimaDir) && posX<180){
    posX++;
	  servoEixoX.write(posX);
  	Serial.print("Posicao X: ");
    Serial.println(posX);
  }else if((luzCimaDir > luzCimaEsq) && posX>0){
    posX--;
  	servoEixoX.write(posX);
    Serial.print("Posicao X: ");
    Serial.println(posX);
  }
  
  //Controle circunferência
  if((luzBaixoEsq > luzBaixoDir) && posY<180){
    posY++;
	  servoEixoY.write(posY);
  	Serial.print("Posicao Y: ");
    Serial.println(posY);
  }else if((luzBaixoDir > luzBaixoEsq) && posY>0){
    posY--;
  	servoEixoY.write(posY);
    Serial.print("Posicao Y: ");
    Serial.println(posY);
  }
  delay(100);
}