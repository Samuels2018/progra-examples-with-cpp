/*

. Evaluar Expresión Postfija

Descripción:
Evalúe expresiones en notación postfija (RPN).
Operadores: +, -, *, / (división entera).

Entrada:
text

3
5 1 2 + 4 * + 3 -
2 3 * 4 +
10 5 / 3 *

Salida esperada:
text

14
10
6

*/



#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


int main (int argc, char *argv[]) {
  int n, b, a, res = 0;
  string text;
  cin >> n;
  cin.ignore(); // Ignorar el salto de línea después del número de casos

  for (int i = 0; i < n; ++i) {
    getline(cin, text);
    istringstream ss(text);
    string token;
    Lista<int> pila;
    while (ss >> token) {
      if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
        pila.Insertar(stoi(token), pila.Tamano() + 1);
      } else {
        b = pila.Consultar(pila.Tamano());
        pila.Eliminar(pila.Tamano());
        a = pila.Consultar(pila.Tamano());
        pila.Eliminar(pila.Tamano());
        res = 0;
        if (token == "+") res = a + b;
        else if (token == "-") res = a - b;
        else if (token == "*") res = a * b;
        else if (token == "/") res = a / b;
        pila.Insertar(res, pila.Tamano() + 1);
      }
    }

    cout << pila.Consultar(1) << endl;
    // No es necesario eliminar la pila, ya que es una variable local
  }

  return 0;

}