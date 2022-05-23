//SENSOR DE COLISÃO

//incluindo biblioteca LCD
#include <LiquidCrystal.h>

//pinos utilizados pelo LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//declarando variáveis
int outputUlt = 13;
int inputUlt = 12;
int ledVerd = 11;
int ledAmar = 10;
int ledVerm =  9;
int buzzer  =  8;

void setup()
{
  //abrindo comunicação com o LCD
  lcd.begin(16, 2);
  //Abrindo monitor serial
  Serial.begin(9600);
  //Configurando pinos
  pinMode(outputUlt, OUTPUT);
  pinMode(inputUlt, INPUT);
  pinMode(ledVerd, OUTPUT);
  pinMode(ledAmar, OUTPUT);
  pinMode(ledVerm, OUTPUT);
  
}

void loop()
{
  //Configurando o estado do sensor ultrassônico
  digitalWrite(outputUlt, LOW);
  delayMicroseconds(2); //1 Microsegundo equivale a 0,001 ms
  digitalWrite(outputUlt, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputUlt, LOW);
  
  long time = pulseIn(inputUlt, HIGH);
  float distancia = (time * 0.0001 * 349)/2;
  
  //condicionais if e else
  if(distancia > 100){//SE distancia for maior que 100cm
  	digitalWrite(ledVerd, HIGH);//led ligado
    digitalWrite(ledAmar, LOW);//led desligado
    digitalWrite(ledVerm, LOW);//led desligado
    
    //limpa a tela do lcd
    lcd.clear();
    
    //cursor na posição determinada
    lcd.setCursor(3,0);
    
    //aparece na tela
    lcd.print("Distancia");
    
    //cursor na posição determinada
    lcd.setCursor(4,1);
    
    //aparece na tela
    lcd.print("Segura");
    delay(1000);
    
  }else if(distancia >= 30 && distancia <= 100){
    //SE a distãncia for maior igual a 30 
    //e distância for menor igual a 100
  	digitalWrite(ledVerd, LOW);//led desligado
    digitalWrite(ledAmar, HIGH);//led ligado
    digitalWrite(ledVerm, LOW);//led desligado
    
    tone(buzzer, 500);//buzzer toca a 500Hz
    delay(500);
    noTone(buzzer);//desliga buzzer
    delay(100);
    
    digitalWrite(ledAmar, LOW);//desliga led
    delay(100);
    
    //limpa a tela
    lcd.clear();
    
    //cursor na posição determinada
    lcd.setCursor(3,0);
    
    //aparece na tela
    lcd.print("Distancia");
    
    //cursor na posição determinada
    lcd.setCursor(3,1);
    
    //aparece na tela
    lcd.print("Perigosa");
    
  }else{//SENÃO
  	digitalWrite(ledVerd, LOW);//led desligado
    digitalWrite(ledAmar, LOW);//led desligado
    digitalWrite(ledVerm, HIGH);//led ligado
    
    tone(buzzer, 1000);//buzzer toca a 1000Hz
    delay(500);
    noTone(buzzer);//desliga o buzzer
    delay(100);
    
    digitalWrite(ledVerm, LOW);//desliga o led 
    delay(100);
    
    //limpa a tela do lcd
    lcd.clear();
    
    //cursor na posição determinada
    lcd.setCursor(3,0);
    
    //aparece na tela
    lcd.print("PERIGO DE");
    
    //cursor na posição determinada
    lcd.setCursor(3,1);
    
    //spsrece na tela
    lcd.print("COLISAO!!!");
  }
  
  //verificando distância no monitor serial
  Serial.print(distancia);
  Serial.println("cm");
}