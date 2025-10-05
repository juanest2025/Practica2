int valores[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
int cantidad[10]; // Para guardar cuántos billetes o monedas de cada tipo
int n = 10;       // Número de denominaciones

void setup() {
    Serial.begin(9600);
    while (!Serial) { } // Esperar a que se abra el monitor serial

    Serial.println("=== CALCULADOR DE BILLETES Y MONEDAS ===");
    Serial.println("Ingrese una cantidad de dinero:");
}

void loop() {
    // Si hay datos disponibles en el monitor serial
    if (Serial.available() > 0) {
        long dinero = Serial.parseInt(); // Leer cantidad
        if (dinero > 0) {
            long restante = dinero;

            // Calcular cuántos billetes/monedas de cada tipo
            for (int i = 0; i < n; i++) {
                cantidad[i] = restante / valores[i];
                restante = restante % valores[i];
            }

            // Mostrar resultados
            Serial.println("RESULTADO:");
            for (int i = 0; i < n; i++) {
                Serial.print(valores[i]);
                Serial.print(": ");
                Serial.println(cantidad[i]);
            }

            // Mostrar si queda faltante
            Serial.print("Faltante: ");
            Serial.println(restante);
            Serial.println("===========================");
            Serial.println("Ingrese otra cantidad:");
        }

        // Limpiar el buffer serial
        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}
