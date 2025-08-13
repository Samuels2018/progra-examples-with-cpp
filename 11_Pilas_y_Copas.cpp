

/*


En el mes de septiembre, hubo una fiesta de cumpleaños muy animada, habían
personas de todos los tipos: gente que gusta de bailar, gente que gusta de ir a comer,
jugadores de lol, fanáticos de karaoke, el típico alma de la fiesta, y por supuesto, tú,
que fuiste invitado por la anfitriona. Todos la estaban pasando bien en la reunión,
había buena música, pero, tú, al no conocer a nadie sólo podías observar cosas como:
gente bailando, personas debatiendo a capa y espada sobre la legalización del aborto,
parejas hablando, un tipo que estaba sentado solo consumiéndose las copas sin bailar
y sin hablar, y entre otras cosas.
A mitad de la fiesta, después de unas cuantas horas, empiezan los juegos de los shots.
Tú decides animarte a jugar y además corres con la suerte de que el chico que estaba
sentado tomando copas todo este tiempo, decide invitar a todos a un nuevo juego. El
juego consiste en que hay dos (2) pilas a (de tamaño n) y b(de tamaño m) de piezas
de madera numeradas, y ordenadas aleatoriamente, entonces, tienes las siguientes
reglas:
● En cada movimiento, puedes remover una pieza de la pila a o b.
● Cada vez que remueves una pieza, vas manteniendo la suma de todas las que
has removido.● Dejas de remover piezas si, en algún punto, la suma se vuelve más grande que
un número maxSum dado al comienzo del juego por el chico que se tomó
todas las copas sin bailar.
● Tu puntuación final es el total de enteros que fuiste capaz de remover de las
dos pilas antes de sobrepasar a maxSum. Debes tomar por el número de
segundos equivalente a cuántas piezas hayas logrado sacar.
Ya después de haber jugado bastante, tu otro yo se hace la pregunta: dadas las pilas a
y b, y maxSum, escogiendo siempre la mayor de las dos opciones en cada versus
escogiendo la menor de las dos ¿cuál es la máxima puntuación posible sin sobrepasar
a maxSum? Ejemplo:
con maxSum = 10, la máxima puntuación sería 4:
● Escogiendo la mayor: sacamos 6 y 7 de la pila b, lo cuál daría una suma de 13.
● Escogiendo la menor: sacamos 1, 2, 3, 4, lo cual daría una suma de 10.
Siendo la opción de escoger la menor la que le tocaría mayor castigo a la hora de las
copas. Entonces, se te pide que crees una función que reciba dos pilas, un entero
maxSum y retorne cuál sería la estrategia que más piezas logró sacar (escoger siempre
la mayor o escoger siempre la menor). Ayuda a tu otro yo a deshacerse de esta duda
existencial tan grande que le nubla la mente en plena fiesta


entrada
5 4 10
1 2 3 4 5
6 7 8 9

salida
4

*/


#include <iostream>
#include "Lista.h"
using namespace std;

// Estrategia: siempre sacar la mayor o la menor de las dos pilas
int maxPiezas(Lista<int> a, Lista<int> b, int maxSum, bool tomarMayor) {
    int suma = 0, piezas = 0;
    int topA = a.Tamano();
    int topB = b.Tamano();
    while (topA > 0 || topB > 0) {
        int valA = (topA > 0) ? a.Consultar(topA) : -1e9;
        int valB = (topB > 0) ? b.Consultar(topB) : -1e9;

        int elegido, pilaElegida;
        if (topA > 0 && topB > 0) {
            if (tomarMayor) {
                if (valA >= valB) { elegido = valA; pilaElegida = 1; }
                else { elegido = valB; pilaElegida = 2; }
            } else {
                if (valA <= valB) { elegido = valA; pilaElegida = 1; }
                else { elegido = valB; pilaElegida = 2; }
            }
        } else if (topA > 0) {
            elegido = valA; pilaElegida = 1;
        } else {
            elegido = valB; pilaElegida = 2;
        }

        if (suma + elegido > maxSum) break;
        suma += elegido;
        piezas++;
        if (pilaElegida == 1) topA--;
        else topB--;
    }
    return piezas;
}

int main() {
    // Entrada de ejemplo:
    // 5 4 10
    // 1 2 3 4 5
    // 6 7 8 9
    int n, m, maxSum, x;
    cin >> n >> m >> maxSum;
    Lista<int> a, b;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.Insertar(x, a.Tamano() + 1);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x;
        b.Insertar(x, b.Tamano() + 1);
    }

    int piezasMayor = maxPiezas(a, b, maxSum, true);
    int piezasMenor = maxPiezas(a, b, maxSum, false);

    cout << (piezasMayor > piezasMenor ? piezasMayor : piezasMenor) << endl;
    return 0;
}