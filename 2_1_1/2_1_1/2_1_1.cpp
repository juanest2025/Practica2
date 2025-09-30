#include <iostream>
using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun_b(array, 10);
}
void fun_a(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam) {
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

//cual es su direccion en memoria? ¿Cuantos bytes se dedican para almacenar cada elemento
//de array? 4 bytes x 10 elementos = 40 bytes
//
//cual es la direccion y el contenido en memoria del elemento array[3]? serian 12 bytes
//
//describa el efecto que tiene la funcion fun b sobre el arreglo array.... invierte el orden de los elementos
//
