#include <iostream>
using namespace std;

//funcion que convierte un entero en cadena
void intToString(int numero, char cadena[]) {
    //caso especial: numero = 0
    if (numero == 0) {
        cadena[0] = '0';
        cadena[1] = '\0';
        return;
    }

    bool negativo = false;
    if (numero < 0) { //manejar negativos
        negativo = true;
        numero = -numero;
    }

    char temp[20]; //arreglo temporal para guardar los digitos al reves
    int i = 0;

    while (numero > 0) {
        int digito = numero % 10;
        temp[i++] = digito + '0'; //convertir a caracter
        numero /= 10;
    }

    if (negativo) {
        temp[i++] = '-';
    }

    //ahora invertimos temp en cadena
    int j = 0;
    for (int k = i - 1; k >= 0; k--) {
        cadena[j++] = temp[k];
    }
    cadena[j] = '\0'; //fin de cadena
}

int main() {
    int numero;
    char cadena[20]; //espacio para el numero convertido

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    intToString(numero, cadena);

    cout << "El numero convertido a cadena es: " << cadena << endl;

    return 0;
}
