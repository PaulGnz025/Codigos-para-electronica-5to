// Codigo de osilador aestable
#define LedNaranja 4
#define tiempo_espera 500

void setup()
{
  pinMode(LedNaranja, OUTPUT);
  digitalWrite(LedNaranja, LOW);
}

  void loop()
  {
    digitalWrite(LedNaranja, HIGH);
    delay(tiempo_espera);
    digitalWrite(LedNaranja, LOW);
    delay(tiempo_espera);
  }