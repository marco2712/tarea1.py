/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
queue
Fecha: 11 de Mayo
*/
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <tuple>
using namespace std;
/*
La complegidad de este algoritmo es O(n) *O(log), ya que en algunos casos debe recorre la lsita completa para buscar un objetvo especifico
pero al trabjar con mapas reduce la complejidad ya que busca un numero especifico, lo que lo convierte en una complejidad constante,
y al trabajar con listas circulares soblemenete ensaldas de la libreira de std, permite agregar tuplas al final de la lista en timpo constante
*/

/*
Funcion: posicionEnMap
Entrada: recibe una lista de tuplas de numeros esteros por referencia y un mapa de numeros enteros
Salida: es una funcion buleana que permite verificar si la primera tupla esta en el mapa con el fin de saber si se debe imprimir
o es una copia quedo al final que ya se utilizo; funciona con iteradores sobre el mapa y la funcion find que es logaritmica 
al usar mapas
*/
bool posicionEnMap( list<tuple<int, int>>& miLista, map<int,int>& miMap){
    bool ans = false;
    int valorEntero, valorEntero2;
    valorEntero = std::get<0>(miLista.front()); // obtiene el primer vvalor de la tuplas
    map<int, int>::iterator iter = miMap.find(valorEntero);
    if (iter != miMap.end()){ //Itera hasta que encuentra una clave que coincida
        valorEntero2 = std::get<1>(miLista.front()); // obtiene el segundo valor de la tuplas
        if(iter->second == valorEntero2) 
            ans = true;
    }
    return ans;  
}
/*
Funcion: posicionEnMap
Entrada: recibe una lista de tuplas de numeros esteros por referencia y un mapa de numeros enteros
Salida: imprime el dato que se requiere, crea un copia de la tupla al final de la lista y elimina la primera de la lista
*/
void impresionDato(list<tuple<int, int>>& miLista, map<int,int>& miMap){
    int valorEntero, valorEntero2;
    valorEntero = get<0>(miLista.front());
    valorEntero2 = get<1>(miLista.front());
    cout << valorEntero << endl;
    miLista.push_back(make_tuple(valorEntero,valorEntero2)); // crea la copia que se envia al fnal de la lista
    miLista.pop_front(); // elimina la tupla actual
}

int main(){
    int numberPeople, cases, menor;
    int numberCase = 0;
    scanf("%d %d",&numberPeople, &cases);
    while(numberPeople != 0 && cases != 0){
        list<tuple<int, int>> miLista;  // se crea una lista de tuplas de enterps vacia
        ++numberCase; 
        map<int, int> miMap; // se crea un mapa de vectores vacio
        if(numberPeople < cases)
            menor = numberPeople;// verificaion que permite hacer menos trabajo y ahorrar espacio en la memoria al moemto de
        else{                    // crear tuplas y el mapa
            menor = cases;
        }    
        for(int i = 1; i <= menor; ++i){ //ciclo incial que crea las tuplas y clasves en el mapa
            miMap[i] = 1;
            miLista.push_back(make_tuple(i, 1));
        }
        cout << "Case " << numberCase<< ":" << endl;
        int k = 0;
        while(k <= cases){
            string character;
            getline(cin,character); // Recibe la linea de input
            if(character == "N"){
                if(posicionEnMap(miLista, miMap)){ // Verifica la primera posicion de la lista para impirmirlo
                    impresionDato(miLista, miMap);
                }
                else{
                    while(!posicionEnMap(miLista, miMap)){
                        miLista.pop_front(); // si la tupla no esta en el mapa, la elimina
                    }
                    impresionDato(miLista, miMap);
                }
            }
            else if(character.size() >= 3){
                int number = stoi(character.substr(2)); // Permte convertir a enteros, los numeros que acompañan a la E, su complegidad 
                map<int, int>::iterator iter = miMap.find(number);//depende del largo de la cadena, y en el peor de los casos podria ser O(n**2)
                if (iter != miMap.end()){
                    miMap[number] += 1;
                    miLista.push_front(make_tuple(number,miMap[number]));
                } 
                else{ // Permite crear nuevos valores en el mapa y agrega dicho valor al inicio de la lista
                    miMap[number] = 1;
                    miLista.push_front(make_tuple(number,1));
                }
            }
            ++k;
        }
        scanf("%d %d",&numberPeople, &cases);
    }
    return 0;
}