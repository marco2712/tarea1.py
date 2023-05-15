/*
Autor: Marco Antonio Riascos Salguero
codigo: 8952273
Fecha: 11 de Mayo
word
*/

#include <iostream>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

/*
La complegidad de este algoritmo pude ser O(n**2)*O(log), ya que tiene varias ciclos anidados lo que hace que repita varias veces
una instruccioin pero cabe resaltar que trabja con un mapa, lo que hace que complejidad disminuya porque busca una posicon espefica,
lo que se hace en tiempo constante
*/

struct mapValue {
    int ocurrences;
    int found;
};

int main() {
    std::string character;
    std::getline(std::cin, character);
    list<string> listaWords;
    while (character != "#"){

        listaWords.push_back(character);  //La creacion de una lista con las letras por lineas
        std::getline(std::cin, character);
    }
    string Dicword;
    std::getline(cin, Dicword);
    while(Dicword != "#"){
        int maincount = 0;
        list<string>::iterator it;
        for(it = listaWords.begin(); it != listaWords.end(); ++it){ // ciclo qye recorre la lista de letras 
            int count = 0;
            map<char,mapValue>puzzle;  //creacion de un mapa vacio
            for(int i = 0; i < Dicword.size(); ++i){
                map<char,mapValue>::iterator iter = puzzle.find(Dicword[i]);  // verifica si una letra ya existe en el diccionario
                if (iter != puzzle.end()){
                    puzzle[Dicword[i]].ocurrences += 1;
                }
                else{
                    puzzle[Dicword[i]].found = 0;
                    puzzle[Dicword[i]].ocurrences = 1;
                }
            }
            string word = *it;
            map<char,mapValue>::iterator itDic;
            for(itDic = puzzle.begin(); itDic != puzzle.end(); ++itDic){ //ciclo que permite recorrer el diccionario
                int flag = 0;
                for(int i = 0; i < word.size(); ++i){
                    if(itDic->first == word[i] && itDic->second.ocurrences >= 0){
                        itDic->second.ocurrences -= 1;
                        if(flag == 0){  // Bandera que permite saber si ya encontro la letra en el diccionario
                            itDic->second.found = 1;
                            flag = 1;
                        }
                        if(itDic->second.found == 1 && itDic->second.ocurrences >= 0){
                            count += 1;
                        }
                    }
                    
                }
            }
            if(count >= word.size()){ // verifica cunats veces encontro la letras del puzzle
                maincount += 1;
            }
        }
        cout << maincount << endl; //Imprime el resultado de veces que la palabra se puede formar
        std::getline(cin,Dicword);
    }
    return 0;
}

