#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define pin_Servo 3
#define disp_manual 2
#define Racion_chica 4
#define Racion_mediana 5
#define Racion_grande 6
#define pin_trig 8
#define pin_echo 9
#define sensor_IR 10
#define pin_buzz 11
#define cantidad_de_comida 7

LiquidCrystal_I2C lcdPaul(direccion_lcd, columnas, filas);
Servo Servo_Paul;
float signSensor(void);

int estadoMenu = 0;
bool sirviendoRacionAutomatica = false;  // Variable para evitar interrupciones
bool state_sensor;

void setup() {
  pinMode(pin_trig, OUTPUT);          
  pinMode(pin_echo, INPUT);
  pinMode(pin_buzz, OUTPUT);
  pinMode(cantidad_de_comida , INPUT);
  digitalWrite(pin_trig, LOW);
  Serial.begin(9600);
  pinMode(disp_manual, INPUT);
  pinMode(Racion_chica, INPUT);
  pinMode(Racion_mediana, INPUT);
  pinMode(Racion_grande, INPUT);
  pinMode(sensor_IR, INPUT);

  Servo_Paul.attach(pin_Servo);
  Servo_Paul.write(0); // Posición inicial del servo

  // Iniciar el LCD
  lcdPaul.init();
  lcdPaul.backlight();
  mostrarMensajeInicial(); // Mostrar mensaje original
}

void loop() {

  // Verificar el estado manualmente sin interferencias
  if (digitalRead(cantidad_de_comida) == HIGH) {
    if(signSensor() >= 30.00 && signSensor() <= 49.00) {
      lcdPaul.clear();
      lcdPaul.setCursor(0,0);
      lcdPaul.print("Lleno");
      delay(500);
      lcdPaul.clear();
      mostrarMensajeInicial();
      estadoMenu = 0;
    }
    else if(signSensor() >= 20.00 && signSensor() <= 29.00) {
      lcdPaul.clear();
      lcdPaul.setCursor(0,0);
      lcdPaul.print("Suficiente");
      delay(500);
      lcdPaul.clear();
      mostrarMensajeInicial();
      estadoMenu = 0;
    }
    else if(signSensor() >= 0.00 && signSensor() <= 19.00) {
      lcdPaul.clear();
      lcdPaul.setCursor(0,0);
      lcdPaul.print("Poco");
      delay(500);
      lcdPaul.clear();
      mostrarMensajeInicial();
      estadoMenu = 0;
      tone(pin_buzz, 500);
      
    delay(500);
    noTone(pin_buzz);
    delay(500);
    }
  }

  state_sensor = digitalRead(sensor_IR);
  if (state_sensor == LOW) {
    lcdPaul.clear();
    lcdPaul.setCursor(0,0);
    lcdPaul.print("Racion auto");
    lcdPaul.setCursor(0,1);
    lcdPaul.print("Sirviendo ...");

    Servo_Paul.write(75);
    delay(250);
    Servo_Paul.write(0);
    delay(250);

    lcdPaul.clear();
    mostrarMensajeInicial();
    estadoMenu = 0;
  }

  // Leer el botón manual para mostrar el menú
  if (digitalRead(disp_manual) == HIGH && estadoMenu == 0) {
    mostrarMenu();
    estadoMenu = 1;
    delay(500);    
  }

  // Si el menú está activo, detectar la selección de la ración
  if (estadoMenu == 1) {
    if (digitalRead(Racion_chica) == HIGH) {
      lcdPaul.clear();
      lcdPaul.setCursor(0, 0);
      lcdPaul.print("Racion manual");
      seleccionarRacion("Chica", 20);  // Cambiar a 20 grados
    }
    else if (digitalRead(Racion_mediana) == HIGH) {
      lcdPaul.clear();
      lcdPaul.setCursor(0, 0);
      lcdPaul.print("Racion manual");
      seleccionarRacion("Mediana", 30);  // Cambiar a 30 grados
    }
    else if (digitalRead(Racion_grande) == HIGH) {
      lcdPaul.clear();
      lcdPaul.setCursor(0, 0);
      lcdPaul.print("Racion manual");
      seleccionarRacion("Grande", 45);  // Cambiar a 45 grados
    }
  }
}

void seleccionarRacion(char* tipoRacion, int angulo) {
  lcdPaul.setCursor(0, 1);
  lcdPaul.print("Sirviendo: ");
  lcdPaul.print(tipoRacion);

  Servo_Paul.write(angulo);  // Mover el servo al ángulo especificado
  delay(500);  // Pausar para que el servo complete el movimiento
  Servo_Paul.write(0);  // Regresar el servo a la posición inicial
  delay(500);

  lcdPaul.clear();
  mostrarMensajeInicial();
  estadoMenu = 0;
}

void mostrarMenu() {
  lcdPaul.clear();
  lcdPaul.setCursor(0, 0);
  lcdPaul.print("Seleccione racion");
  lcdPaul.setCursor(0, 1);
  lcdPaul.print("1:Ch 2:Med 3:Gra");
}

void mostrarMensajeInicial() {
  lcdPaul.setCursor(0, 0);
  lcdPaul.print("Dispensador auto");
  lcdPaul.setCursor(0, 1);
  lcdPaul.print("comida perros   ");
}

float signSensor(void) {
  digitalWrite(pin_trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig,LOW);

  long Sensor = pulseIn(pin_echo,HIGH);
  long distancia = Sensor / 59;
  return distancia;
}
