#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
dahdahdah.c
Marco Antonio Riascos Salguero 
89752273
La complegidad es lineal ya que el while trabaja revisando un los arreglos hasta el final. en el peor de los casos verfica hasta el ultimo
el ultimo caracrter, lo que lo convierte en O(n);
*/


// variables globles
#define character_numbers 60
#define code_morsa 200


int main(){
    int cases;
    int number_cases = 1;
    char ramdon;
    scanf("%d", &cases);
    scanf("%c", &ramdon);
    char dots[10];
    int j = 0;
    int cont;
    char letras[character_numbers][code_morsa] = {" ","A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5","6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"};
    char morsa[character_numbers][code_morsa] = { "\0", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--","-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
    while(cases >= number_cases){
        int i = 0;
        char space = 'A';
        if(number_cases == 1){  // el condiccional verfica que es el primer caso para no imprimir doble salto de linea como en los casos sigueintes
            printf("Message #%d\n", number_cases);

        }else{
            printf("\n\nMessage #%d\n", number_cases);
        }
        while(space != '\n'){ // Al comenzr el proceso de lectura verifica que no lea un espcio o un salto de linea para entrar al ciclo.
            scanf("%c", dots);
            i = 0;
            cont = 1;
            while(dots[i] != '\n' && dots[i] != ' '){ // En esta parte de la funcion; el programa lee caracter a caracter, hasta encontrar un espcio.
                i += 1;
                scanf("%c", &dots[i]);
                cont = 0;
            }
            space = dots[i];
            dots[i]='\0'; // al terminar leer una linea de caracteres le agrega \0, lo que significa que es el fin de la cadena.
            i = 0;
            while(strcmp(dots, morsa[i])){ // compara si la cadena leida es igual a algun caracter de la cadena letras y si lo es la imprime 
                ++i;                       // si se encuntra doble espacio, imprime un espacio que se declaro en los arreglos   
            }
            printf("%s", letras[i]);
        }  
         ++ number_cases;
        } 
    return 0;
}