/*


En matemáticas, estadística y finanzas, se define la media móvil como el promedio de una sucesión de números en lo que
se llama una “ventana deslizante”, por ejemplo, si se tiene la sucesión an = 1, 7, 9, 10, 5, 9 y definimos una ventana de
tamaño 3, tendríamos el siguiente resultado: Mv = 5.6, 8.6, 8, 8. La explicación consiste en que al principio, la ventana
tomó los primeros 3 valores y les obtuvo el promedio y su resultado fue 5.6, luego la ventana se mueve un espacio, y tomó
los números 7, 9, 10 y les obtuvo su promedio, y así sucesivamente. Cree una función que dada una lista y un valor de
ventana calcule la media móvil. No use apuntadores, solución de tiempo máxima en O(n2 )


entrada:
6
1 7 9 10 5 9
3

salida:
5.666667 8.666667 8.000000 8.000000 

*/

#include <iostream>
#include "Lista.h"
#include <iomanip>
using namespace std;

// Calcula la media móvil usando solo la clase Lista
Lista<double> media_movil(Lista<int> datos, int k) {
    Lista<double> resultado;
    int n = datos.Tamano();
    for (int i = 1; i <= n - k + 1; ++i) { // 1-based
        double suma = 0;
        for (int j = 0; j < k; ++j) {
            suma += datos.Consultar(i + j);
        }
        resultado.Insertar(suma / k, resultado.Tamano() + 1);
    }
    return resultado;
}

int main() {
    int n, k, valor;
    cin >> n;
    Lista<int> datos; // Cambia a objeto, no puntero
    for (int i = 0; i < n; ++i) {
        cin >> valor;
        datos.Insertar(valor, datos.Tamano() + 1);
    }
    cin >> k;

    Lista<double> resultado = media_movil(datos, k); // Pasa objeto, no puntero

    cout << fixed << setprecision(6);
    for (int i = 1; i <= resultado.Tamano(); ++i) {
        cout << resultado.Consultar(i) << " ";
    }
    cout << endl;

    // No uses delete para objetos automáticos
    return 0;
}

