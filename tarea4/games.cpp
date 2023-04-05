#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

// Marco Antonio Riascos Salguero
// codigo 8952273

/*  
La complegidad del aloritmo es O(n), ya que es de complegidad lineal, en cada momento donde se agregan los vectores,
luego utiliza la funcion sort para organizar el vector y al escoger las cadenas que son la mitad del vector, se trabja con strings,
utilizando el codigo ascii para saber cual va primero en orden alfaabetcio.
*/

int main(){
    int cases, posicion;
    char array[1000][30];
    scanf("%d", &cases);
    while(cases != 0){
        vector<string>vec_names(cases);
        for(posicion = 0; posicion < cases; ++posicion){
            cin >> vec_names[posicion]; // organiza las cadenas en cada vector
        }    
        sort(vec_names.begin(), vec_names.end()); // orde las cadenas segun el codigo ascii
        string half_left = vec_names[cases/2 -1]; // encuentra la cadena de la mitad -1
        string half_right = vec_names[cases/2]; // encuentra el caracter siguiente a la mitad
        int i = 0;
        while (i < half_left.size() && half_left[i] == half_right[i]) { //  verifica si los caracteres de la palabras son iguales y
            i++;   // si lo son, i dice el tamaño mas pequeño posible de la cadena 
        }
        if (i == half_left.size()) { // si i es del mismo tamaño de la cadena mas pequeña debe imprimir la cadena 
            cout << half_left << endl;
        } else {
            char new_caracter = half_left[i]; // si i es diferente entonces imprime los caracteres hasta el iteradro i +1
            cout << half_left.substr(0, i);
            cout << (char)(new_caracter + 1);
            cout << endl;
        }
        scanf("%d", &cases);
    }        
    return 0;
}