/*Este projeto consiste em recriar um cancela
automática, com um sensor ultrassônico,
ao veículo se aproximar a menos de 1,5 metros,
a cancela se abre e acende o led Verde, ao a cancela
fechar, acende o led vermelho*/

#include <Servo.h>

Servo servoMotorObj; //cria um novo objeto servo


int const servoMotorPin = 3;
int sensorUltOut = 13;
int sensorUltIn = 12;
int ledVerm = 9;
int ledVerd = 8;



void setup()
{
  servoMotorObj.attach(servoMotorPin);
  pinMode(sensorUltOut, OUTPUT);
  pinMode(sensorUltIn, INPUT);
  pinMode(ledVerm, OUTPUT);
  pinMode(ledVerd, OUTPUT);
}

void loop()
{
  //Configurando o estado do sensor ultrassônico
  digitalWrite(sensorUltOut, LOW);
  delayMicroseconds(2); //1 Microsegundo equivale a 0,001 ms
  digitalWrite(sensorUltOut, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorUltOut, LOW);
  
  long time = pulseIn(sensorUltIn, HIGH);
  float distancia = (time * 0.0001 * 349)/2;
  
  
  if(distancia >= 0 && distancia <= 150){
  	map(100, 0, 1023, 0, 180);
  	servoMotorObj.write(100);
  	delay(15);
    digitalWrite(ledVerd, HIGH);
    digitalWrite(ledVerm, LOW);
  }
  else{
  	map(0, 0, 1023, 0, 180);
  	servoMotorObj.write(0);
  	delay(15);
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledVerd, LOW);
  }
}