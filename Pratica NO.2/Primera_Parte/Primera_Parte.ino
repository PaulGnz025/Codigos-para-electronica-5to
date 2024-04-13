#define push_button 2 // push button conectado al pin 2
#define led 3

void setup()
{
  pinMode(push_button, INPUT); //pin2 comom entrada
  pinMode(led, OUTPUT);
  Serial.begin(9600); //Inicio la comunicacion serial
  Serial.println("Lectura de un Pulsador");// Envio el texto entre comillas al pueto serie
}

void loop()
{
  // Variable local, que se encarga de almacenar el valor(abierto o cerrado)
  //del pulsador conectado al pin2
  bool estado_boton = digitalRead(push_button);
  if (estado_boton == HIGH) //¿He presionado elinterruptor?
  {
    //si lo he presionado
    digitalWrite(led, LOW); //apago el led
   } 
  else{
    // si no lo he presionadp
    digitalWrite(led, HIGH); //Mantengo encendido el led