#include <iostream>
using namespace std;


//{x, y, ancho, alto}
//donde (x, y) es la esquina superior izquierda.

//Explicación breve:

//Se calcula la esquina inferior derecha de cada rectángulo (x + ancho, y + alto).
//La intersección ocurre entre los máximos de las esquinas superiores y los mínimos de las inferiores.
//Si el resultado da un ancho o alto negativo (no se superponen), el rectángulo resultante se llena con ceros.

//Ejemplo de salida:
//Rectángulo A: {0, 0, 8, 4}
//Rectángulo B: {5, 2, 6, 7}
//Intersección C: {5, 2, 3, 2}



// Función que calcula la intersección entre dos rectángulos
void interseccionRectangulos(int A[4], int B[4], int C[4]) {
    // Coordenadas del rectángulo A
    int Ax1 = A[0];
    int Ay1 = A[1];
    int Ax2 = A[0] + A[2]; // x + ancho
    int Ay2 = A[1] + A[3]; // y + alto

    // Coordenadas del rectángulo B
    int Bx1 = B[0];
    int By1 = B[1];
    int Bx2 = B[0] + B[2];
    int By2 = B[1] + B[3];

    // Calcular coordenadas de la intersección
    int Cx1 = max(Ax1, Bx1);
    int Cy1 = max(Ay1, By1);
    int Cx2 = min(Ax2, Bx2);
    int Cy2 = min(Ay2, By2);

    // Verificar si hay intersección
    if (Cx1 < Cx2 && Cy1 < Cy2) {
        // Si hay intersección, llenar el arreglo C
        C[0] = Cx1;          // x
        C[1] = Cy1;          // y
        C[2] = Cx2 - Cx1;    // ancho
        C[3] = Cy2 - Cy1;    // alto
    } else {
        // Si no hay intersección, devolver todo 0
        C[0] = C[1] = C[2] = C[3] = 0;
    }
}

int main() {
    int A[4] = {0, 0, 8, 4};  // Rectángulo A
    int B[4] = {5, 2, 6, 7};  // Rectángulo B
    int C[4];                 // Rectángulo de intersección

    interseccionRectangulos(A, B, C);

    cout << "Rectángulo A: {" << A[0] << ", " << A[1] << ", " << A[2] << ", " << A[3] << "}" << endl;
    cout << "Rectángulo B: {" << B[0] << ", " << B[1] << ", " << B[2] << ", " << B[3] << "}" << endl;
    cout << "Intersección C: {" << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "}" << endl;

    return 0;
}


