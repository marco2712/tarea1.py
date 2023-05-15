/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
rails
*/
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
La complegidad de este algoritmo es cuadratica por el hecho de tener dos ciclos anidados, en el caso de que debe recorrer el vector
y vertificarlo con la pila, mientras sean diferentes, en el peor de los es que la linea de trenes se reciba invertida por lo que 
tendria que llenar toda la pila y despues verificar por cada uno otra vez.
*/

int main() {
    int numberTrains;
    cin >> numberTrains; // Numero de trenes por caso
    cin.ignore();
    while (numberTrains != 0) {
        string trains;
        getline(cin, trains);
        vector<int> array(numberTrains); // vector que almacena las poscciones de los trenes
        while(trains != "0") {
            stack<int> pilatrains;
            stringstream ss(trains);
            int number;
            int add = 0;
            while (ss >> number) { //ciclo que recibe la linea leida y convirte a entero los numeros
                array[add] = number;
                ++add;
            }
            int count = 1;
            int i = 0;
            while (i < numberTrains && count <= numberTrains){
                if (!pilatrains.empty()) {
                    while(!pilatrains.empty() && array[i] == pilatrains.top()){
                        pilatrains.pop();  // si hay considencias en el top de la pila y el vector, se elimina el tren de la pila
                        ++i;
                    }
                    pilatrains.push(count);
                    ++count;
                }
                else{ // suma en a pila para pooder comparar con el vector
                    pilatrains.push(count);
                    ++count;
                } 
            } 
            while(!pilatrains.empty() && array[i] == pilatrains.top()){ // ciclo que permite recorrer la pila dado el caso que se lleno
                pilatrains.pop();                               // y salio del primer ciclo
                ++i;
            }
            if(pilatrains.empty()){ 
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            while(!pilatrains.empty()){ //Elimina todos los elementos de la pila en el caso que no se puede
                pilatrains.pop();
            }
            getline(cin, trains);
        }
        printf("\n");
        cin >> numberTrains;
        cin.ignore();
    }
    return 0;
}