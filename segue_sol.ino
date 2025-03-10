#include<Servo.h>

Servo parabola;
Servo circulo;

void setup()
{
  parabola.attach(9);
  circulo.attach(7);
  Serial.begin(9600);
  parabola.write(origem());
  circulo.write(origem());
}

void loop()
{
  nulo();
  
}

int origem() {
  return 0;
}

void nulo() {
  for(int pos=circulo.read(); pos<= 180; pos++){
    circulo.write(pos);
    Serial.println(pos);
    delay(300);
  }
  circulo.write(origem());
}