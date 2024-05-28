#include <Wire.h>
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// Para la LCD
#define direccion_lcd 0x20  // Verifica que esta es la dirección correcta con un escáner I2C
#define filas 2
#define columnas 16

// Para el teclado matricial
#define filas_teclado 2
#define columnas_teclado 3
#define f1_teclado 5
#define f2_teclado 6
#define c1_teclado 2
#define c2_teclado 3
#define c3_teclado 4

// Para otros componentes
int ledPins[] = {14, 15, 16, 17};
int A = 8;
int B = 7;
int C = 10;
int D = 11;
int E = 12;
int G = 13;

// Variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3'},
  {'4','5','6'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado};

// Constructor
LiquidCrystal_I2C lcdMck(direccion_lcd, columnas, filas);   // LCD con dirección 0x20 y tamaño 16x2
Servo servo1;                                              // Servomotor controlado por medio del PWM en el pin 9
Keypad teclado_paul = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

void setup() {
  Serial.begin(9600);
  Serial.println("Proyecto final 2B");

  Wire.begin();
  
  // Configuración de la LCD
  lcdMck.init();
  lcdMck.backlight();
  lcdMck.setCursor(0, 0);
  lcdMck.print("Paul Gonzalez");
  lcdMck.setCursor(0,1);
  lcdMck.print("Proyecto Final");

  // Configuración del servo
  servo1.attach(9);
  
  // Configuración de pines como salida
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  char tecla = teclado_paul.getKey();
  
  if (tecla) {
    Serial.print("La tecla presionada es: ");
    Serial.println(tecla);

    switch (tecla) {
      case '1':
        for (int i = 0; i < 100; i++) {
          delay(150);
          Serial.println(i);
          delay(150);
        }
        break;

      case '2':
        for (int i = 99; i > -1; i--) {
          delay(150);
          Serial.println(i);
          delay(150);
        }
        break;

      case '3':
        for (int m = 0; m < 2; m++) {
          for (int led = 0; led < 4; led++) { 
            digitalWrite(ledPins[led], HIGH);
            delay(250);
            digitalWrite(ledPins[led], LOW);
          }

          for (int led = 3; led >= 0; led--) {
            digitalWrite(ledPins[led], HIGH);
            delay(250);
            digitalWrite(ledPins[led], LOW);
          }
        }
        break;

      case '4':
        for (int i = 0; i < 1; i++) {
          // Primera parte de la animación de serpiente
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(G, LOW);
          delay(2500);

          // Segunda parte de la animación de serpiente
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(G, LOW);
          delay(2500);

          // Tercera parte de la animación
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(G, HIGH);
          delay(2500);

          // Cuarta parte de la animación
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, LOW);
          digitalWrite(G, HIGH);
          delay(2500);

          // Quinta parte de la animación
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, LOW);
          digitalWrite(E, HIGH);
          digitalWrite(G, HIGH);
     
          delay(2500);
          //
          
          digitalWrite(E, LOW);
          digitalWrite(G, LOW);
          delay(1000);
          digitalWrite(G, HIGH);
          delay(1000);
          digitalWrite(G, LOW);
        }
      case '5':
        // Acciones para la tecla '5'
        servo1.write(180);
        delay(5000);
        servo1.write(0);
        delay(3000);
        break;
    }
  }
}
