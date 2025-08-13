/*

Verificar Paréntesis Balanceados

Descripción:
Verifique si una cadena tiene paréntesis (), corchetes [] y llaves {} balanceados usando una pila.

Entrada:
text

3
([)]
{[()]}
((()))

Salida esperada:
text

No
Sí
Sí


*/


#include<iostream>
#include "Lista.h"
#include<string>
using namespace std;

bool esPar(char abre, char cierra) {
  return (abre == '(' && cierra == ')') ||
  (abre == '[' && cierra == ']') ||
  (abre == '{' && cierra == '}');
}

int main() {
  int n;
  string linea;
  cin >> n;
  cin.ignore();

  for (int caso = 0; caso < n; ++caso) {
    getline(cin, linea);
    Lista<char> pila;
    bool balanceado = true;
    for (char c : linea) {
      if (c == '(' || c == '[' || c == '{') {
        pila.Insertar(c, pila.Tamano() + 1);
      } else if (c == ')' || c == ']' || c == '}') {
        if (pila.EsVacia() || !esPar(pila.Consultar(pila.Tamano()), c)) {
          balanceado = false;
          break;
        } else {
          pila.Eliminar(pila.Tamano());
        }
      }
    }
    if (!pila.EsVacia()) balanceado = false;
    cout << (balanceado ? "Sí" : "No") << endl;
  }
  return 0;
}