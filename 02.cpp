/*


Dada una lista enlazada y un tamaño de grupo k, invierta los elementos de cada grupo de k nodos. Si el último grupo tiene menos nodos, déjelos como están.
Implementar con lista doblemente enlazada propia.

2
3
A B C D E F
2
X Y Z
*/



#include<iostream>
#include "Lista.h"
#include<string>
#include <sstream>

using namespace std;


int main (int argc, char *argv[]) {

  int n, n1, n2;
  string letras, letras1, linea;
  Lista<string>* data = new Lista<string>();
  Lista<string>* data1 = new Lista<string>();

  cin>>n;
  cin>>n1;
  cin.ignore();
  getline(cin, linea); // lee la línea completa: "A B C D E F"
  istringstream ss(linea);
  while (ss >> letras) {
    data->Insertar(letras, data->Tamano() + 1);
  }
  cin>>n2;
  cin.ignore();
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> letras1) {
    data1->Insertar(letras1, data1->Tamano() + 1);
  }


  // Mostrar el contenido de ambas listas para depuración (1-based)
  /*cout << "--- Lista data ---" << endl;
  for (int i = 1; i <= data->Tamano(); i++) {
    cout << data->Consultar(i) << endl;
  }
  cout << "--- Lista data1 ---" << endl;
  for (int i = 1; i <= data1->Tamano(); i++) {
    cout << data1->Consultar(i) << endl;
  }*/



  // Invertir la lista data en grupos de tamaño n1
  Lista<string>* resultado = new Lista<string>();
  int tam = data->Tamano();
  for (int i = 1; i <= tam; i += n1) {
    int fin = i + n1 - 1;
    if (fin > tam) fin = tam;
    // Insertar el grupo invertido
    for (int j = fin; j >= i; j--) {
      resultado->Insertar(data->Consultar(j), resultado->Tamano() + 1);
    }
  }

  // Mostrar la lista invertida por grupos
  cout << "--- Lista data invertida por grupos ---" << endl;
  for (int i = 1; i <= resultado->Tamano(); i++) {
    cout << resultado->Consultar(i) << " ";
  }
  cout << endl;

  return 0;

}