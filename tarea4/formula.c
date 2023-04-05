#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Marco Antonio Riascos Salguero
// codigo 8952273

/*
La complegida este algoritmo se podria asumir que es O(n**2), ya que se debe recorrer una matiz de pilotos y las vueltas que hicieron,
y depues va escogiendo aquellos que tiene puntuacion, y para ello debe recorrer otro arreglo en el cual estan los puntos de los pilotos,
si es que ganaron puntos.
*/

void winner_points(int matrix_pilots[500][100],int f_laps, int f_pilots, int* sistema, int premiados){
    int*  array = (int*) calloc(f_pilots, sizeof(int)); // se hace un arreglo dinamico para crear un arreglo de tamaño que desconocemos
    int i = 0;
    int j;
    int mayor = 0;
    while(i < f_pilots){ // Recorre los pilotos
        j=0; 
        while(j < f_laps){ // Recorre las vueltas
            if (matrix_pilots[i][j] -1 < premiados){// Verifica que el piloto esté dentro de los premiados
                array[i]+= sistema[matrix_pilots[i][j]-1];// en la posicon del piloto se le agragn los puntos que obtuvo dependiendo del sistema de evalucacion 
                if(array[i] > mayor){ // verifica que lo que esta en la posicion del arreglo, sea el maximo puntaje obtenido por un piloto
                    mayor = array[i]; // si algun piloto obtuvo mas puntos, se le agrega esos puntos al mayor 
                }
            }
            ++j;
        }
        ++i;
    }
    int printer = 0;
    int number_one = 0;
    while(printer < f_pilots){
        if (array[printer] == mayor){ // Verifica si el piloto actual es uno de los ganadores
            if(number_one == 0){ // este condicional verifica si es el primer competidor de haber mas, a fin de no imprimir con el espcio que deben tener
                printf("%d", (printer +1) ); 
                number_one = 1;
            }
            else{
                printf(" %d", (printer +1));
            }    
        }
        ++printer;
    }
    printf("\n");
}

int main(){
    int lap;
    int pilots;
    int posicion;
    int matrix[500][100];  // se crea la matix mas grande posible para almacenar los datos
    scanf("%d %d", &lap, &pilots); //  se crean los variables que almcenan el numero de pilotos y de vueltas 
    while(lap != 0 && pilots != 0){
        int laps = 0;
        int list_pilots[pilots];
        int temp;
        int number_laps = 0;
        while(number_laps < lap){  // se hace un doble ciclo que permite copiar la matiz, tal cual para trabajar y saber en que poccion llego cada piloto
            int number_pilots = 0;
            while(number_pilots < pilots){ // la forma en la que esta codificada la matriz permite organizar los pilatos y las careras por columnas tal que
                scanf("%d", &matrix[number_pilots][number_laps]); // en la primera colummna se almcena todas las carreras el piloto 1 y asi sucesivamente
                ++number_pilots;    
            }
            ++ number_laps;
        }
        scanf("%d", &laps);
        int i = 0;
        while(i  < laps){
            int system;
            scanf("%d", &system); //despues de recibir el numero de vueltas se crea un arreglo con el numero de sistemas qye se va recibir 
            int number_system[system];
            int j = 0;
            while(j < system){
                scanf("%d", &number_system[j]); // se guardan en el arreglo el nuemro de premiados y los puntos a otorgar
                ++ j;
            }
            winner_points(matrix, lap, pilots, number_system, system); //se invoca la funcion, que resuleve el algoritmo e imprime
            ++ i;
        }    
        scanf("%d %d", &lap, &pilots);
    }
    return 0;
}