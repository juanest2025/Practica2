int potPin = A0;     // Pin analógico donde está el potenciómetro
int ledPin = 9;      // Pin digital PWM para el LED
int valorPot = 0;    // Variable para leer el potenciómetro
int brillo = 0;      // Variable para guardar el brillo

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Leer el potenciómetro (0 a 1023)
    valorPot = analogRead(potPin);

    // Escalar a rango PWM (0 a 255)
    brillo = map(valorPot, 0, 1023, 0, 255);

    // Ajustar brillo del LED
    analogWrite(ledPin, brillo);

    delay(10); // Pequeño retardo para estabilidad
}
