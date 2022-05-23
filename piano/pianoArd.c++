//Definindo notas musicais
int DO   = 262;
int RE   = 294;
int MI   = 330;
int FA   = 349;
int SOL  = 392; 
int LA   = 440;
int SI   = 494;
int DO_2 = 523;

int botao1 = 13;
int botao2 = 12;
int botao3 = 11;
int botao4 = 10;
int botao5 = 9;
int botao6 = 8;
int botao7 = 7;
int botao8 = 6;

int pinoBuzzer = 5;

int vDO, vRE, vMI, vFA, vSOL, vLA, vSI, vDO2;


int tempo = 30;


void setup()
{

  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);
  pinMode(botao4, INPUT);
  pinMode(botao5, INPUT);
  pinMode(botao6, INPUT);
  pinMode(botao7, INPUT);
  pinMode(botao8, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop()
{
int vDO = digitalRead(botao1);
int vRE = digitalRead(botao2);
int vMI = digitalRead(botao3);
int vFA = digitalRead(botao4);
int vSOL = digitalRead(botao5);
int vLA = digitalRead(botao6);
int vSI = digitalRead(botao7);
int vDO2 = digitalRead(botao8);
  
  if(vDO == 1){
   tone(pinoBuzzer,DO,100); 
  }
   if(vRE == 1){
   tone(pinoBuzzer,RE,100); 
  }
   if(vMI == 1){
   tone(pinoBuzzer,MI,100); 
  }
   if(vFA == 1){
   tone(pinoBuzzer,FA,100); 
  }
   if(vSOL == 1){
   tone(pinoBuzzer,SOL,100); 
  }
   if(vLA == 1){
   tone(pinoBuzzer,LA,100); 
  }
   if(vSI == 1){
   tone(pinoBuzzer,SI,100); 
  }
   if(vDO2 == 1){
   tone(pinoBuzzer,DO_2,100); 
  }
  delay(tempo);
}