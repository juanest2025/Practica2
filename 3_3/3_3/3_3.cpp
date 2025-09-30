#include <iostream>
using namespace std;

//funcion que compara dos cadenas de caracteres
bool compararCadenas(const char cadena1[], const char cadena2[]) {
    int i = 0;

    //recorremos ambas cadenas mientras no termine una
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false; //si hay diferencia, no son iguales
        }
        i++;
    }

    //si ambas terminan al mismo tiempo son iguales
    return (cadena1[i] == '\0' && cadena2[i] == '\0');
}

int main() {
    char cadena1[100];
    char cadena2[100];

    cout << "Ingrese la primera cadena: ";
    cin.getline(cadena1, 100);

    cout << "Ingrese la segunda cadena: ";
    cin.getline(cadena2, 100);

    if (compararCadenas(cadena1, cadena2)) {
        cout << "Verdadero: Las cadenas son iguales" << endl;
    } else {
        cout << "Falso: Las cadenas son diferentes" << endl;
    }

    return 0;
}
