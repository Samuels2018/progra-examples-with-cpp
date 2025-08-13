/*
4. Eliminar Duplicados Consecutivos
Descripción:
Elimine caracteres duplicados consecutivos en una cadena usando una pila.
Ej: "abbaca" → "ca".

Entrada:
text

2
abbaca
aabccb

Salida esperada:
text

ca
b

*/


#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


int main (int argc, char *argv[]) {
  int n;
  string text;
  cin >> n;
  Lista<string>* pila = new Lista<string>();
  cin.ignore();

  for (int caso = 0; caso < n; ++caso) {
    getline(cin, text);

    for (char c : text) { // Itera sobre cada carácter de la cadena
      string s(1, c);
      if (!pila->EsVacia() && pila->Consultar(pila->Tamano()) == s) {
        pila->Eliminar(pila->Tamano()); // Quita el duplicado
      } else {
        pila->Insertar(s, pila->Tamano() + 1); // Inserta al final (simula push)
      }
    }

    // Imprimir resultado
    for (int i = 1; i <= pila->Tamano(); ++i) {
      cout << pila->Consultar(i);
    }
    cout << endl;
    delete pila;
  }
  
  return 0;
}