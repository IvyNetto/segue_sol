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
}

void loop()
{
  if (LDRA > LDRB) {
    AB();
    
  } else if (LDRB > LDRA){
    BA();
    
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
  for(int pos=circulo.read(); LDRA > LDRB; pos++){
    circulo.write(pos);
  }
}
  
void BA() {
  for(int pos=circulo.read(); LDRB > LDRA; pos--){
    circulo.write(pos);
  }
}  
  
