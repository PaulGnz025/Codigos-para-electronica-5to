 int S = 2;
 int R = 3;
void setup() {
  Serial.begin(9600);     
  Serial.println("CONTADOR ASCENDENTE Y DESCENTE");
  Serial.println("DERECHA RESTA - / IZQUIERDA SUMA");
  pinMode(2, INPUT);     
  pinMode(3, INPUT);     
}
 
 
int cont = 0;
 
void loop() {
  if(digitalRead(S)==HIGH){ 
   delay(350);
   cont = cont+1; 
     if (cont == 100){
      cont = 0;}
    Serial.println(cont);}
    else if(digitalRead(R)==HIGH) 
  {
   delay(350);
      cont = cont-1;
   if (cont <0){
      cont = 99;}
     Serial.println(cont);}

    }
