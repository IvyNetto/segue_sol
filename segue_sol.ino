#include<Servo.h>

Servo parabola;
Servo circulo;
int LDRA = A0;
int LDRB = A1;
int entrada = 0; // variavel-> ta armazenando o valor do LDR1

void setup()
{
  parabola.attach(9);
  circulo.attach(7);
  Serial.begin(9600);
  parabola.write(origem());
  circulo.write(origem());
  pinMode(LDRA, INPUT);
  pinMode(LDRB, INPUT);
  delay(2000);
}

void loop()
{
  Serial.print("\nLDRA: "); //debug
  Serial.print(analogRead(LDRA)); //debug
  Serial.print("\nLDRB: "); //debug
  Serial.print(analogRead(LDRB)); //debug
  delay(2000); //debug
  if (analogRead(LDRA) > analogRead(LDRB)) {
    AB();
    delay(1000);
  } else if (analogRead(LDRB) > analogRead(LDRA)){
    BA();
    delay(1000);
  }
  
}

int origem() { //talvez descartado
  return 90;
}

void nulo() {
  for(int pos=circulo.read(); pos<= 180; pos++){
    circulo.write(pos);
    Serial.println(pos);
    delay(300);
  }
  circulo.write(origem());
}

void AB() {
  for(int pos=circulo.read(); analogRead(LDRA) > analogRead(LDRB); pos++){
    if(pos>180){
      pos=180;
    }else{
      circulo.write(pos);
      Serial.println(pos); //debug
    }
  }
}
  
void BA() {
  for(int pos=circulo.read(); analogRead(LDRB) > analogRead(LDRA); pos--){
    if(pos<0){
      pos=0;
    }else{
    circulo.write(pos);
    Serial.println(pos); //debug
    }
  }
}  
  
