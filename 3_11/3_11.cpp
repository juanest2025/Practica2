#include <iostream>
using namespace std;

const int filas = 15;
const int columnas = 20;

//funcion estado de la sala
void mostrarSala(char sala[filas][columnas]) {
    cout << "   ";
    for (int j = 0; j < columnas; j++) {
        if (j + 1 < 10) cout << j + 1 << "  ";
        else cout << j + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < filas; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < columnas; j++) {
            cout << sala[i][j] << "  ";
        }
        cout << endl;
    }
}

//funcion inicializar  sala, todos libres
void inicializarSala(char sala[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            sala[i][j] = '-';
        }
    }
}

//funcion reservar asiento
void reservar(char sala[filas][columnas], char fila, int asiento) {
    int f = fila - 'A';
    int c = asiento - 1;

    if (f < 0 || f >= filas || c < 0 || c >= columnas) {
        cout << "Error, asiento invalido.\n";
        return;
    }

    if (sala[f][c] == '+')
        cout << "Ese asiento ya esta reservado.\n";
    else {
        sala[f][c] = '+';
        cout << "Asiento reservado correctamente.\n";
    }
}

//funcion cancelar reserva
void cancelar(char sala[filas][columnas], char fila, int asiento) {
    int f = fila - 'A';
    int c = asiento - 1;

    if (f < 0 || f >= filas || c < 0 || c >= columnas) {
        cout << "Error, asiento invalido.\n";
        return;
    }

    if (sala[f][c] == '-')
        cout << "Error, ese asiento ya está libre.\n";
    else {
        sala[f][c] = '-';
        cout << "Reserva cancelada correctamente.\n";
    }
}

int main() {
    char sala[filas][columnas];
    inicializarSala(sala);

    char opcion;
    do {
        cout << "//---SISTEMA DE RESERVAS DE CINE---- \n";
        cout << "1. Mostrar sala\n";
        cout << "2. Reservar asiento\n";
        cout << "3. Cancelar reserva\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == '1') {
            mostrarSala(sala);
        }
        else if (opcion == '2') {
            char fila;
            int asiento;
            cout << "Ingrese fila (A-O): ";
            cin >> fila;
            cout << "Ingrese numero de asiento (1-20): ";
            cin >> asiento;
            reservar(sala, fila, asiento);
        }
        else if (opcion == '3') {
            char fila;
            int asiento;
            cout << "Ingrese fila (A-O): ";
            cin >> fila;
            cout << "Ingrese numero de asiento (1-20): ";
            cin >> asiento;
            cancelar(sala, fila, asiento);
        }

    } while (opcion != '4');

    cout << "Saliendo....que pase un lindo dia.\n";
    return 0;
}
