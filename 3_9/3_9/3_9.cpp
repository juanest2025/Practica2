#include <iostream>
using namespace std;
//funcion calcular la longitud cadena
int longitudCadena(char cad[]) {
    int len = 0;
    while (cad[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    int n;
    char cadena[100];

    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Ingrese la cadena numerica: ";
    cin >> cadena;

    int longitud = longitudCadena(cadena);
    int faltante = n - (longitud % n); //calcula cuantos ceros hga
    if (faltante == n) faltante = 0; //si ya multiplo no se rellenar

    //crea una nueva cadena con ceros a la izquierda si es necesario
    char completa[120];
    int j = 0;

    for (int i = 0; i < faltante; i++) {
        completa[j++] = '0'; //agregar ceros
    }
    for (int i = 0; i < longitud; i++) {
        completa[j++] = cadena[i];
    }
    completa[j] = '\0'; //marca fin de cadena

    //procesa en grupos de n
    int suma = 0;
    for (int i = 0; i < j; i += n) {
        int numero = 0;
        for (int k = 0; k < n; k++) {
            numero = numero * 10 + (completa[i + k] - '0');
        }
        suma += numero;
    }

    cout << "Original: " << cadena << "." << endl;
    cout << "Suma: " << suma << "." << endl;

    return 0;
}
