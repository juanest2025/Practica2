#include <iostream>
using namespace std;

int main() {
    int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000,
                            500, 200, 100, 50};
    int cantidad = 0;
    int faltante = 0;

    cout << "Ingrese la cantidad de dinero: ";
    cin >> cantidad;

    int n = sizeof(denominaciones) / sizeof(denominaciones[0]); //sizeof devuleve el tamaño de bytes de 1 elemento en el arreglo
    int valores[n]; //para guardar cuantos billetes/monedas de cada denominacion

    for (int i = 0; i < n; i++) {
        valores[i] = cantidad / denominaciones[i];
        cantidad = cantidad % denominaciones[i];
    }

    // lo que queda es el faltante
    faltante = cantidad;

    // Imprimir resultados
    for (int i = 0; i < n; i++) {
        cout << denominaciones[i] << ":" << valores[i] << endl;
    }
    cout << "Faltante: " << faltante << endl;

    return 0;
}

