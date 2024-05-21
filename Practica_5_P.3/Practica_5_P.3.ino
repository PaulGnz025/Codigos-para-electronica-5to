
const int pin_2 = 2;
const int pin_3 = 3;
const int pin_4 = 4;
const int pin_5 = 5;
const int pin_6 = 6;
const int pin_7 = 7;
const int pin_8 = 8;
int Buzzer = 10;
int Rele = 11;

int segmentos(int A,int B,int C,int D,int E,int F,int G);

void setup()
{
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
  pinMode(pin_5, OUTPUT);
  pinMode(pin_6, OUTPUT);
  pinMode(pin_7, OUTPUT);
  pinMode(pin_8, OUTPUT);
  pinMode(Rele, OUTPUT);
  digitalWrite(Rele, HIGH);
}

void loop()
{
  int resultado;
  
  resultado = segmentos(1, 1, 1, 0, 0, 1, 1);
  delay(1000);
  resultado = segmentos(1, 1, 1, 1, 1, 1, 1);
  delay(1000);
  resultado = segmentos(1, 1, 1, 0, 0, 0, 0);
  delay(1000);
  resultado = segmentos(0, 0, 1, 1, 1, 1, 1);
  delay(1000);
  resultado = segmentos(1, 0, 1, 1, 0, 1, 1);
  delay(1000);
  resultado = segmentos(0, 1, 1, 0, 0, 1, 1);
  delay(1000);
  resultado = segmentos(1, 1, 1, 1, 0, 0, 1);
  delay(1000);
  resultado = segmentos(1, 1, 0, 1, 1, 0, 1);
  delay(1000);
  resultado = segmentos(0, 1, 1, 0, 0, 0, 0);
  delay(1000);
  resultado = segmentos(1, 1, 1, 1, 1, 1, 0);
  delay(1000);
  
  tone(Buzzer,250,500);
 
  digitalWrite(Rele, LOW);
  delay(500);
  digitalWrite(Rele, HIGH);
  delay(500);
}

int segmentos(int A, int B, int C, int D, int E, int F, int G) {
  digitalWrite(pin_2, A);
  digitalWrite(pin_3, B);
  digitalWrite(pin_4, C);
  digitalWrite(pin_5, D);
  digitalWrite(pin_6, E);
  digitalWrite(pin_7, F);
  digitalWrite(pin_8, G);
  
}