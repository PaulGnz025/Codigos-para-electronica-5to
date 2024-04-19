struct NO1{
  char NP1[50];
int numerodulce;
};

struct NO2{
  char NP2[50];  
 int numerodulce;
};
struct NO3{
  char NP3[50];
int numerodulce;
};
struct NO4{
  char NP4[50];
  int numerodulce;
};
NO1 dulce1 = {"Chocolate", 45};
NO2 dulce2 = {"Chicle", 60};
NO3 dulce3 = {"Paletas",50};
NO4 dulce4 = {"Gomitas",54};

byte contador = 0;

void setup() {
  
  Serial.begin(9600);
  Serial.println("Registro de maqunina expendedora de Oficina 5");
  Serial.println("El boton Izquierdo avanza y el derecho retrocede");
  pinMode(2, INPUT);
  pinMode(3,INPUT);
}

void loop(){
  if(digitalRead(2)==HIGH){
    delay(350);
    contador = contador + 1;
    
    if(contador == 1){
      Serial.println(dulce1.NP1);
      Serial.println(dulce1.numerodulce);}
    
    if(contador == 2){
      Serial.println(dulce2.NP2);
      Serial.println(dulce2.numerodulce);}
    
    if(contador == 3){
      Serial.println(dulce3.NP3);
      Serial.println(dulce3.numerodulce);}
    
    if(contador == 4){
      Serial.println(dulce4.NP4);
      Serial.println(dulce4.numerodulce);}
  } else if (digitalRead(3)==HIGH){
    delay(350);
    contador = contador-1;
    
    if(contador == 1){
      Serial.println(dulce1.NP1);
      Serial.println(dulce1.numerodulce);}
    
    if(contador == 2){
      Serial.println(dulce2.NP2);
      Serial.println(dulce2.numerodulce);}
    
    if(contador == 3){
      Serial.println(dulce3.NP3);
      Serial.println(dulce3.numerodulce);}
    
    if(contador == 4){
      Serial.println(dulce4.NP4);
      Serial.println(dulce4.numerodulce);}    
  }

}
