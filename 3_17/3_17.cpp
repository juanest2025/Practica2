#include <iostream>
using namespace std;

//funcion calcula  suma de  divisores propios de numero
int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            suma += i;
    }
    return suma;
}

int main() {
    int limite;
    cout << "Ingrese un numero: ";
    cin >> limite;

    int sumaAmigables = 0;

    for (int a = 2; a < limite; a++) {
        int b = sumaDivisores(a);
        if (b != a && b < limite) {
            if (sumaDivisores(b) == a) {
                sumaAmigables += a + b;
            }
        }
    }

    //evitar duplicados
    sumaAmigables /= 2;

    cout << "El resultado de la suma es: " << sumaAmigables << "." << endl;

    return 0;
}

