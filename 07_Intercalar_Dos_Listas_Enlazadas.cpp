/*

Intercalar Dos Listas Enlazadas

Descripción:
Intercale dos listas enlazadas: nodo de lista1, nodo de lista2, etc.
Si una lista es más larga, añada los nodos restantes al final.

Entrada:
text

2
3
A B C
X Y Z
2
1 2 3
4

Salida esperada:
text

A X B Y C Z
1 4 2 3


*/


#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


void intercalarListas(Lista<string> l1, Lista<string> l2, Lista<string>& resultado) {
  int i = 1, j = 1;
  int tam1 = l1.Tamano();
  int tam2 = l2.Tamano();
  while (i <= tam1 || j <= tam2) {
    if (i <= tam1) {
      resultado.Insertar(l1.Consultar(i), resultado.Tamano() + 1);
      i++;
    }
    if (j <= tam2) {
      resultado.Insertar(l2.Consultar(j), resultado.Tamano() + 1);
      j++;
    }
  }
}
int main (int argc, char *argv[]) {
  int n;
  string linea, palabra;
  cin >> n;
  cin.ignore();

  for (int caso = 0; caso < n; ++caso) {
    // Leer y descartar el tamaño de la primera lista
    getline(cin, linea);

    // Leer la primera lista
    getline(cin, linea);
    istringstream ss1(linea);
    Lista<string> l1;
    while (ss1 >> palabra) {
      l1.Insertar(palabra, l1.Tamano() + 1);
    }

    // Leer y descartar el tamaño de la segunda lista
    getline(cin, linea);

    // Leer la segunda lista
    getline(cin, linea);
    istringstream ss2(linea);
    Lista<string> l2;
    while (ss2 >> palabra) {
      l2.Insertar(palabra, l2.Tamano() + 1);
    }

    Lista<string> resultado;
    intercalarListas(l1, l2, resultado);

    for (int i = 1; i <= resultado.Tamano(); ++i) {
      cout << resultado.Consultar(i);
      if (i < resultado.Tamano()) cout << " ";
    }
    cout << endl;
  }
  return 0;
}