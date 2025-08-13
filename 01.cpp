
// El que esté libre de pecado, que reparta el pan...
// la entrada de los datos es de esta manera 
// ./a.out < entrada01.txt
// compilar: g++ some_name.cpp


#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


int main (int argc, char *argv[]) {
  int initcialTam, case01, case02, j = 1, k;
  string line, p, p1;
  Lista<string>* first = new Lista<string>();
  Lista<string>* second = new Lista<string>();

  cin>>initcialTam;
  cin>>case01;
  cin>>case02;

  
  while(getline(cin, line)) {
    if (line.empty()) continue;
    istringstream ss(line);
    if (ss >> p) {
      first->Insertar(p, first->Tamano() + 1); // insertar SIEMPRE al final (1-based)
    }
    if (ss >> p1) {
      second->Insertar(p1, second->Tamano() + 1); // insertar SIEMPRE al final (1-based)
    }
  }

  int paso = case01; // o el valor que quieras usar como paso
  int pos = 1; // posición inicial
  bool derecha = true;

  while (first->Tamano() > 1) {
      // Calcular la siguiente posición a eliminar
      int tam = first->Tamano();
      if (derecha) {
          pos = (pos + paso - 2) % tam + 1; // -2 porque pos ya es 1-based y queremos avanzar paso-1
      } else {
          pos = (pos - paso);
          while (pos < 1) pos += tam;
      }
      first->Eliminar(pos);

      // Cambiar dirección
      derecha = !derecha;
  }

  // Mostrar el contenido de ambas listas para depuración (1-based)
  cout << "--- Lista first ---" << endl;
  for (int i = 1; i <= first->Tamano(); i++) {
    cout << first->Consultar(i) << endl;
  }

  paso = case02; // o el valor que quieras usar como paso
  pos = 1; // posición inicial
  derecha = true;

  while (second->Tamano() > 1) {
      // Calcular la siguiente posición a eliminar
      int tam = second->Tamano();
      if (derecha) {
          pos = (pos + paso - 2) % tam + 1; // -2 porque pos ya es 1-based y queremos avanzar paso-1
      } else {
          pos = (pos - paso);
          while (pos < 1) pos += tam;
      }
      second->Eliminar(pos);

      // Cambiar dirección
      derecha = !derecha;
  }

  cout << "--- Lista second ---" << endl;
  for (int i = 1; i <= second->Tamano(); i++) {
    cout << second->Consultar(i) << endl;
  }


  return 0;


}