/*


Dada una lista de enteros, se pide que cree la siguiente función:
func compact(Lista<int> list): Lista<Lista<int>>
que dada una lista ordenada con elementos repetidos, devuelva una lista comprimida. Por ejemplo:
L = [1, 1, 1, 3, 3, 3, 5, 5]
compact(L) = [[1, 3], [3, 3], [5, 2]]
Basicamente, se debe devolver una lista de listas, en donde cada lista componente va a tener dos
elementos, el primero es el elemento original, y el segundo es la cantidad de veces que aparece este
elemento. La solucion debe ser a lo sumo O(n). NO USAR APUNTADORES

entrada esperada:
8
1 1 1 3 3 3 5 5

salida esperada:
[[1, 3], [3, 3], [5, 2]]
[1, 3], [3, 3], [5, 2]
*/



#include <iostream>
#include "Lista.h"
using namespace std;

// Compacta una lista ordenada en una lista de listas [valor, cantidad]
Lista< Lista<int> > compact(Lista<int>& list) {
    Lista< Lista<int> > resultado;
    int n = list.Tamano();
    if (n == 0) return resultado;

    int actual = list.Consultar(1);
    int cuenta = 1;

    for (int i = 2; i <= n; ++i) {
        int valor = list.Consultar(i);
        if (valor == actual) {
            cuenta++;
        } else {
            Lista<int> par;
            par.Insertar(actual, 1);
            par.Insertar(cuenta, 2);
            resultado.Insertar(par, resultado.Tamano() + 1);
            actual = valor;
            cuenta = 1;
        }
    }
    // Agregar el último grupo
    Lista<int> par;
    par.Insertar(actual, 1);
    par.Insertar(cuenta, 2);
    resultado.Insertar(par, resultado.Tamano() + 1);

    return resultado;
}

int main() {
    // Entrada de prueba:
    // 8
    // 1 1 1 3 3 3 5 5
    int n, valor;
    cin >> n;
    Lista<int> lista;
    for (int i = 0; i < n; ++i) {
        cin >> valor;
        lista.Insertar(valor, lista.Tamano() + 1);
    }

    Lista< Lista<int> > comprimida = compact(lista);

    // Salida de prueba:
    // [[1, 3], [3, 3], [5, 2]]
    for (int i = 1; i <= comprimida.Tamano(); ++i) {
        Lista<int> par = comprimida.Consultar(i);
        cout << "[" << par.Consultar(1) << ", " << par.Consultar(2) << "]";
        if (i < comprimida.Tamano()) cout << ", ";
    }
    cout << endl;
    return 0;
}