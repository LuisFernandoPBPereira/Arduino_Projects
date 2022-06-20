#include <Servo.h>

Servo servoMotorObj; //cria um novo objeto servo


int const servoMotorPin = 3;
int sensorUltOut = 13;
int sensorUltIn = 12;
int ledVerm = 9;
int ledVerd = 8;
char leitura;



void setup()
{
  Serial.begin(9600);
  servoMotorObj.attach(servoMotorPin);
  pinMode(sensorUltOut, OUTPUT);
  pinMode(sensorUltIn, INPUT);
  pinMode(ledVerm, OUTPUT);
  pinMode(ledVerd, OUTPUT);
  
  montaMenu();
}

void loop()
{
  while(Serial.available() > 0){
  
    leitura = Serial.read();
    //trataLeitura(leitura);
  }
  //Configurando o estado do sensor ultrassônico
  digitalWrite(sensorUltOut, LOW);
  delayMicroseconds(2); //1 Microsegundo equivale a 0,001 ms
  digitalWrite(sensorUltOut, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorUltOut, LOW);
  
  long time = pulseIn(sensorUltIn, HIGH);
  float distancia = (time * 0.0001 * 349)/2;
  servoMotorObj.write(0);
  
  if(leitura == 'Q' || leitura == 'q'){
  	map(100, 0, 1023, 0, 180);
  	servoMotorObj.write(100);
  	delay(15);
    digitalWrite(ledVerd, HIGH);
    digitalWrite(ledVerm, LOW);
    delay(250);
  }
  else if(leitura == 'W' || leitura == 'w'){
  	map(0, 0, 1023, 0, 180);
  	servoMotorObj.write(0);
  	delay(15);
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledVerd, LOW);
    delay(250);
  }
  else if(leitura == 'A' || leitura == 'a'){
    
    if(distancia >= 0 && distancia <= 150){
		abrePortao();
    }
    else {
		fechaPortao();
    }
    Serial.println("Modo aproximacao ativado");
    delay(500);
  }

}

void montaMenu(){
	
    Serial.println("---------------------------------------------");
    Serial.println("--A U T O M A C A O   R E S I D E N C I A L--");
    Serial.println("----------- Opcoes com Leds 3 DSN -----------");
    Serial.println("---------------------------------------------");
    Serial.println("** Utilize o seu teclado de seu computador **");
  	Serial.println("---------------------------------------------");
    Serial.println("-PORTAO(VERMELHO = FECHADO / VERDE = ABERTO)-");
    Serial.println("- Q -> Abre o portao / W  -> Fecha o portao -");
  	Serial.println("--------- A -> Ativa a aproximacao ----------");
    Serial.println("---------------------------------------------");
  	Serial.println("------------------ ALERTA -------------------");
  	Serial.println("---------------------------------------------");
  	Serial.println("Nao se pode usar os dois mecanismos ao mesmo tempo");
	
  	pulaLinha(2);
}

void pulaLinha(int qtdeLinhas){

  for(int p = 0; p< qtdeLinhas; p++){
  
    Serial.println("");
  }
}

void abrePortao(){
  	  map(100, 0, 1023, 0, 180);
      servoMotorObj.write(100);
      delay(15);
      digitalWrite(ledVerd, HIGH);
      digitalWrite(ledVerm, LOW);
}

void fechaPortao(){
      map(0, 0, 1023, 0, 180);
      servoMotorObj.write(0);
      delay(15);
      digitalWrite(ledVerm, HIGH);
      digitalWrite(ledVerd, LOW);
}

