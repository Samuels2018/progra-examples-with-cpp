/*


Enunciado del Ejercicio

Problema:
"Registro de Atletas en una Competencia de Natación"
Se necesita procesar información de atletas durante una competencia. El programa debe:

    Mantener una lista predefinida de números de competidores ([7, 14, 1]).

    Registrar nuevos datos de un atleta:

        Nombre (ej: "Ana")

        Diferencia de tiempo (segundos respecto al líder, ej: 1.25)

        Edad (ej: 28)

    Añadir un nuevo número de competidor (32) después de registrar al atleta.

    Mostrar las listas actualizadas:

        Números de competidores (original + nuevo)

        Edad del atleta registrado

        Diferencia de tiempo registrada

        Nombre del atleta



Entrada de Datos para Probar

Formato:
text

<Nombre> <Diferencia_de_tiempo> <Edad>

Ejemplo:
text

Ana 1.25 28

*(Valores de prueba: Nombre = "Ana", Diferencia = 1.25 segundos, Edad = 28 años)*
Salida Esperada

Resultado en consola:
text

32 7 14 1  // Lista actualizada de números de competidores
28         // Lista de edades (solo contiene la edad de Ana)
1.25       // Lista de diferencias de tiempo (solo contiene 1.25)
Ana        // Lista de nombres (solo contiene "Ana")



*/

#include <iostream>
#include "Lista.h"
#include <string>
using namespace std;


void entrada(Lista<float> L,Lista<int> L4,Lista<string> L5){
    
  int edad, i=0;
  float diferencia;
  string nombre,linea;

  cin >> nombre;
  cin >> diferencia;
  cin >> edad;
  L5.insertar(nombre, 1);
  L.insertar(diferencia, 1);
  L4.insertar(edad, 1);

    

}



int main(){
  int casos;

  Lista<int> l;
  Lista<float> lista3;
  Lista<int> l4;
  Lista<string> l5;

  l.insertar(1,1);
  l.insertar(14,1);
  l.insertar(7,1);


  entrada(lista3,l4,l5);

  l.insertar(32,1);

  l.imprimirLista();
  l4.imprimirLista();
  lista3.imprimirLista();
  l5.imprimirLista();

  return 0;
}

