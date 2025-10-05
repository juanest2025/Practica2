int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            suma += i;
    }
    return suma;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Ingrese un numero:");
}

void loop() {
    if (Serial.available() > 0) {
        int limite = Serial.parseInt();
        int sumaAmigables = 0;

        for (int a = 2; a < limite; a++) {
            int b = sumaDivisores(a);
            if (b != a && b < limite) {
                if (sumaDivisores(b) == a) {
                    sumaAmigables += a + b;
                }
            }
        }

        sumaAmigables /= 2; // evitar duplicados
        Serial.print("El resultado de la suma es: ");
        Serial.println(sumaAmigables);
        Serial.println("----------------------");

        // Espera para siguiente entrada
        delay(3000);
        Serial.println("Ingrese otro numero:");
    }
}

