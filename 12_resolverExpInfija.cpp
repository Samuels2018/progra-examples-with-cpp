/*

Dada una expresión matemática bien formada con elementos enteros positivos en forma infija almacenada en una
lista de cadenas. Cree la funcion:
func resolverExpInfija(Lista<cadena>: exp): entero
Que dada una lista de caracteres que contiene expresiones como esta:
[{(30+5)+(28 * 3)}+8]
Retorna el resultado de evaluar la expresión (en este caso retorna 127).


entrada esperada:
[ { ( 30 + 5 ) + ( 28 * 3 ) } + 8 ]


salida esperada:
127

*/


#include <iostream>
#include "Lista.h"
#include <string>
#include <sstream>
using namespace std;

// Prioridad de operadores
int prioridad(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

// Convierte infija a postfija usando solo listas
Lista<string> infijaAPostfija(Lista<string> exp) {
    Lista<string> salida;
    Lista<string> pila;
    int n = exp.Tamano();
    for (int i = 1; i <= n; ++i) {
        string token = exp.Consultar(i);
        cout << "Token: " << token << endl;

        if (isdigit(token[0])) {
            salida.Insertar(token, salida.Tamano() + 1);
        } else if (token == "(" || token == "[" || token == "{") {
            pila.Insertar(token, pila.Tamano() + 1);
        } else if (token == ")" || token == "]" || token == "}") {
            string abre;
            if (token == ")") abre = "(";
            if (token == "]") abre = "[";
            if (token == "}") abre = "{";
            while (!pila.EsVacia() && pila.Consultar(pila.Tamano()) != abre) {
                salida.Insertar(pila.Consultar(pila.Tamano()), salida.Tamano() + 1);
                pila.Eliminar(pila.Tamano());
            }
            if (!pila.EsVacia()) pila.Eliminar(pila.Tamano()); // Quita el paréntesis de apertura
        } else { // operador
            while (!pila.EsVacia() && prioridad(pila.Consultar(pila.Tamano())) >= prioridad(token)) {
                salida.Insertar(pila.Consultar(pila.Tamano()), salida.Tamano() + 1);
                pila.Eliminar(pila.Tamano());
            }
            pila.Insertar(token, pila.Tamano() + 1);
        }

        // Imprimir estado de pila y salida
        cout << "Pila: ";
        for (int j = 1; j <= pila.Tamano(); ++j) cout << pila.Consultar(j) << " ";
        cout << "\nSalida: ";
        for (int j = 1; j <= salida.Tamano(); ++j) cout << salida.Consultar(j) << " ";
        cout << "\n-------------------\n";
    }
    while (!pila.EsVacia()) {
        salida.Insertar(pila.Consultar(pila.Tamano()), salida.Tamano() + 1);
        pila.Eliminar(pila.Tamano());
    }

    // Imprimir salida final
    cout << "Postfija final: ";
    for (int j = 1; j <= salida.Tamano(); ++j) cout << salida.Consultar(j) << " ";
    cout << endl;

    return salida;
}

// Evalúa una expresión postfija usando solo listas
int evaluaPostfija(Lista<string> postfija) {
    Lista<int> pila;
    int n = postfija.Tamano();
    for (int i = 1; i <= n; ++i) {
        string token = postfija.Consultar(i);
        if (isdigit(token[0])) {
            pila.Insertar(stoi(token), pila.Tamano() + 1);
        } else {
            int b = pila.Consultar(pila.Tamano());
            pila.Eliminar(pila.Tamano());
            int a = pila.Consultar(pila.Tamano());
            pila.Eliminar(pila.Tamano());
            int res = 0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") res = a / b;
            pila.Insertar(res, pila.Tamano() + 1);
        }
    }
    int resultado = pila.Consultar(1);
    return resultado;
}

// Función principal
int resolverExpInfija(Lista<string> exp) {
    Lista<string> postfija = infijaAPostfija(exp);
    int resultado = evaluaPostfija(postfija);
    return resultado;
}

// Ejemplo de uso
int main() {
    string tokens;
    Lista<string> exp;

    getline(cin, tokens);
    stringstream ss(tokens);
    string token;
    while (ss >> token) {
        exp.Insertar(token, exp.Tamano() + 1);
    }

    // Ahora sí procesa toda la expresión
    infijaAPostfija(exp);

    // Si quieres evaluar la expresión, descomenta y usa tu función de evaluación
    cout << resolverExpInfija(exp) << endl; // Debe imprimir 127

    return 0;
}