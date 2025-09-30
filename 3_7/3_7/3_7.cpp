#include <iostream>
using namespace std;

//funcion elimina caracteres repetidos
void eliminarRepetidos(char original[], char sinRepetidos[]) {
    int i = 0;
    int k = 0;
    bool visto[256] = {false}; //arreglo marca caracteres vistos

    while (original[i] != '\0') { //recorrer la cadena
        unsigned char c = original[i];
        if (!visto[c]) {          //si no lo hemos visto antes
            visto[c] = true;      //marcarlo como visto
            sinRepetidos[k++] = c; //agregarlo a la nueva cadena
        }
        i++;
    }
    sinRepetidos[k] = '\0'; //marcar final cadena
}

int main() {
    char cadena[100];
    char resultado[100];

    cout << "Ingrese una cadena: ";
    cin >> cadena;

    eliminarRepetidos(cadena, resultado);

    cout << "Original: " << cadena << ". Sin repetidos: " << resultado << endl;

    return 0;
}
