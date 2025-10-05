#include <iostream>
using namespace std;

//funcion cuenta estrellas
int contEstrellas(int *matriz, int filas, int columnas) {
    int estrellas = 0;

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            int aij = *(matriz + i * columnas + j);
            int izquierda = *(matriz + i * columnas + (j - 1));
            int derecha = *(matriz + i * columnas + (j + 1));
            int arriba = *(matriz + (i - 1) * columnas + j);
            int abajo = *(matriz + (i + 1) * columnas + j);

            float promedio = (aij + izquierda + derecha + arriba + abajo) / 5.0;

            if (promedio > 6)
                estrellas++;
        }
    }
    return estrellas;
}

int main() {
    int matriz[6][7] = {
        {0, 3, 4, 0, 0, 0, 8},
        {5, 8, 6, 7, 0, 2, 3},
        {2, 6, 4, 7, 0, 1, 0},
        {0, 0, 4, 15, 4, 1, 0},
        {0, 0, 7, 12, 6, 9, 4},
        {5, 0, 10, 6, 4, 8, 0}
    };
    int filas = 6, columnas = 7;
    int total = contEstrellas(&matriz[0][0], filas, columnas);
    cout << "Numero de estrellas encontradas: " << total << endl;

    return 0;
}
