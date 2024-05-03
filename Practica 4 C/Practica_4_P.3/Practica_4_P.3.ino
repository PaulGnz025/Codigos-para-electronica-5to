int ledPins[] = {6, 7, 8, 9, 10};
int A = 11;
int B = 12;
int C = 14;
int D = 15;
int E = 16;
int F = 17;
int G = 18;

void setup()
   {
  
      pinMode(2, INPUT);
      pinMode(3, INPUT);
      pinMode(4, INPUT);
      pinMode(5, INPUT);
      pinMode(A, OUTPUT);
      pinMode(B, OUTPUT);
      pinMode(C, OUTPUT);
      pinMode(D, OUTPUT);
      pinMode(E, OUTPUT);
      pinMode(F, OUTPUT);
      pinMode(G, OUTPUT);
  

  Serial.begin(9600);
}

void loop() {
  

  if(digitalRead(2)== HIGH && digitalRead(4)== LOW){
    delay(1000);
    Serial.println("Practica No.4 Allan Paul Gonzalez Tzunun");
  }
  if(digitalRead(3)==HIGH && digitalRead(5)== LOW ){
for (int m = 0; m < 2; m++) {
    for (int led = 0; led < 4; led++) { 
      digitalWrite(ledPins[led], HIGH);
      delay(500);
      digitalWrite(ledPins[led], LOW);
    }

    for (int led = 4; led >= 0; led--) {
      digitalWrite(ledPins[led], HIGH);
      delay(500);
      digitalWrite(ledPins[led], LOW);

    }
}
  }
  if(digitalRead(4)== HIGH && digitalRead(2)==LOW){ 
    for(int i = 0; i<1 ; i++) {
      digitalWrite( A, HIGH);
      digitalWrite( F, HIGH);
      digitalWrite( E, HIGH);
      digitalWrite( D, HIGH);
      delay(750);
      digitalWrite( A, LOW);
      digitalWrite( F, LOW);
      digitalWrite( E, LOW);
      digitalWrite( D, LOW);
      delay (2000);
      digitalWrite( E, HIGH);
      digitalWrite( D, HIGH);
      digitalWrite( C, HIGH);
      digitalWrite( F, HIGH);
      digitalWrite( B, HIGH);
      delay (750);
      digitalWrite (E, LOW);
      digitalWrite (D, LOW);
      digitalWrite (C ,LOW);
      digitalWrite( F, LOW);
      digitalWrite( B, LOW);
      delay(2000);
      digitalWrite (A, HIGH);
      digitalWrite (B, HIGH);
      digitalWrite (C, HIGH);
      digitalWrite (G, HIGH);
      digitalWrite (F, HIGH);
      digitalWrite (E, HIGH);
      delay(750);
      digitalWrite (A, LOW);
      digitalWrite (B, LOW);
      digitalWrite (C, LOW);
      digitalWrite (G, LOW);
      digitalWrite (F, LOW);
      digitalWrite (E, LOW);
      delay(2000);
      digitalWrite (F, HIGH);
      digitalWrite (G, HIGH);
      digitalWrite (E, HIGH);
      digitalWrite (D, HIGH);
      delay (750);
      digitalWrite (F, LOW);
      digitalWrite (G, LOW);
      digitalWrite (E, LOW);
      digitalWrite (D, LOW);
      delay(2000);
      digitalWrite (E, HIGH);
      digitalWrite (G, HIGH);
      delay(750);
      digitalWrite (E ,LOW);
      digitalWrite (G, LOW);
      delay(2000);
      digitalWrite (F, HIGH);
      digitalWrite (A, HIGH);
      digitalWrite (B, HIGH);
      digitalWrite (E, HIGH);
      digitalWrite (C, HIGH);
      digitalWrite (D, HIGH);
      delay(750);
      digitalWrite (F, LOW);
      digitalWrite (A, LOW);
      digitalWrite (B, LOW);
      digitalWrite (E, LOW);
      digitalWrite (C, LOW);
      digitalWrite (D, LOW);
    }
    }
  if(digitalRead(4)== HIGH && digitalRead(2)== HIGH ||digitalRead(5)== HIGH && digitalRead(3)== HIGH ){
      delay(1000);
    Serial.println("Gracias por su atencion");
  }
}
