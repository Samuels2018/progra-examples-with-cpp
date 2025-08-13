/*
Reordenar Lista: Primero-Ultimo

Descripción:
Reordene una lista enlazada: primer elemento, último elemento, segundo elemento, penúltimo, etc.
Implemente con lista doblemente enlazada.

Entrada:
text

2
3
A B C D E
2
1 2 3

Salida esperada:
text

A E B D C
1 3 2



*/


#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


void reordenarPrimeroUltimo(Lista<string>& original, Lista<string>& resultado) {
  int ini = 1;
  int fin = original.Tamano();
  bool turnoInicio = true;
  resultado.Vaciar(); // Limpiar resultado antes de usar
  while (ini <= fin) {
    if (turnoInicio) {
      resultado.Insertar(original.Consultar(ini), resultado.Tamano() + 1);
      ini++;
    } else {
      resultado.Insertar(original.Consultar(fin), resultado.Tamano() + 1);
      fin--;
    }
    turnoInicio = !turnoInicio;
  }
}

int main (int argc, char *argv[]) {
  int n, ord;
  string text;
  cin >> n;
  cin >> ord;
  cin.ignore();
  for (int caso = 0; caso < n; ++caso) {
    Lista<string> pila;
    Lista<string> resultado;
    getline(cin, text);
    if (text.empty()) continue; // Salta líneas vacías
    istringstream ss(text);
    string palabra;
    while (ss >> palabra) {
      pila.Insertar(palabra, pila.Tamano() + 1); // Inserta al final (1-based)
    }

    reordenarPrimeroUltimo(pila, resultado);

    for (int i = 1; i <= resultado.Tamano(); ++i) {
      cout << resultado.Consultar(i);
      if (i < resultado.Tamano()) cout << " ";
    }
    cout << endl;
  }
  return 0;
}