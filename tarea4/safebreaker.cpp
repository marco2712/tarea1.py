#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Marco Antonio Riascos Salguero
// codigo 8952273

/*
la complejidad de este algotirmo yo podria decir que es muy grande ya que debe verificar entre los 9999 casos possibles con cada intento,
tambien tiene que comparar la combiancion con todos los elementos de la estructura si llega el caso que hay un numero posible para la combinacion;
tambien crea muchas copias de arreglos, por lo que creeria que tiene complejidad O(n**3), por cuestion de los ciclos anidados
*/

typedef struct Save Save;

struct Save{   // Utiliza una estructura para guardar los datos organizadamente 
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int num6;
};

// esta funcion auxiliar permite ir suamando 1 a la combinacion del arreglo hasta llegar a 9999
void sumar_arreglo(int* array){
    int i = 3;
    int flag = 0;
    while(i >= 0 && flag == 0){
        if(array[i] == 9){ // si el nummero es 9, lo cambia por un cero y le suma 1 a la posicion anterior del arreglo
            array[i] = 0;
            i -= 1;
        } 
        else{
            array[i] += 1;
            flag = 1;
        }
    }    
}
/*
La funcion compararArregloOcurrencias es la que se encarga de revisar si existe algun numero en la posicion correcta; por ende tiene que 
verificar todas las posiciones, y los if le permiten hacer eso; esta es la cerradura que dice que si la pista es 2 y hay 3 en la posicion 
correcta; esta combinacion no es valida segun la pista; por ello retorna un numero con el numero de ocurrencias 
*/

int compareArregloOcurrencia(Save* data, int* array, int iterador){
    int count = 0;
    if(data[iterador].num1 == array[0]){
        count += 1;
    }
    if(data[iterador].num2 == array[1]){
        count += 1;
    }
    if(data[iterador].num3 == array[2]){
        count += 1;
    }
    if(data[iterador].num4 == array[3]){
        count += 1;
    }
    return count;
}

/*
la funcion CompararNumero es la encargada de verificar la segun pista, que el numero este en la combinacion por ende un condicional 
que verifica que el numero este pero no en una posicion correcta, asi mismo itera hasta que las considencias son memnores que la pista

*/

int CompararNumero(Save* data, int* array, int iterador, int estruc, int iterador2){
    int i = 0;
    int contador = 0;
    int flag3 = 0;
    while(i < 4 && contador < iterador){ // verifica que el contador que dice cuantas ocurrecnias existen sea menor que la pista 
        if(data[estruc].num1 == array[i]){
            if(i =!0){                 // verifica que el numero este pero no en la posicon correcta
                ++contador;
            }
        }
        else if(data[estruc].num2 == array[i]){
            if(i != 1){
                ++contador;
            }
        }
        else if(data[estruc].num3 == array[i]){
            if(i != 2){
                ++contador;
            }
        }
        else if(data[estruc].num4 == array[i]){
            if(i != 3){
                ++contador;
            }
        }
        ++i;    
    }   
    return contador;
}
/*
La funcion solve, es la que se encarga de verificar si alguna combinacion pasa el numero de cerradruas, por ende invoca las otas funciones
auxiliares y es la encargada de imprimir los resulatdos.
*/
void solve(Save* data, int guesses){
    int array[4] = {0, 0, 0 ,0};
    int result[4];
    int i, k;
    int count;
    int second;
    int verify;
    int saveArreglo;
    int flag2 = 0;
    int contador2 = 0;
    int printer;
    for(i = 0; i < 9999; ++i){
        int flag = 0;
        k = 0;
        verify = 1;
        int prueba;
        while(k < guesses && flag == 0){  // el while le permite verificar si una combiancion pasa todas las pistas y flag le perimite terminar si alguna no cumple
            count = compareArregloOcurrencia(data, array, k); // la funcion de comparar ocurrencias en el lugar exacto
            second = CompararNumero(data, array, data[k].num6, k,data[k].num5);// funcion que verifica si el numero esta 
                if(count == data[k].num5 && second == data[k].num6){ // este condicional verifica que las pistas sean iguales a que retornan las funciones 
                    ++k;
                }
                else{                    // si la condicion no se cumple se detiene el while y se sigue a otra combinacion posible
                    flag = 1;
                    verify = 0;
                }
        }    
        if(verify == 1 && flag2 == 0){  // si al terminar el ciclo alguna combiancion pasa, se copia en otro arreglo la respuesta
            for(saveArreglo = 0; saveArreglo < 4; ++saveArreglo){
                result[saveArreglo] = array[saveArreglo];
            }
            ++contador2;
            flag2 = 1;
        }    
        else if(verify == 1 && flag2 == 1){ // si existe una combinacion posible, y otra la cumple tambien; entonces se agrega que hay otra solucion posible
            ++contador2;
        }    
        sumar_arreglo(array);
    }
    if(contador2 == 1){
        for(printer = 0; printer< 4; ++ printer){  // si solo hay combinacion posble, se imprime la combiancion
            printf("%d", result[printer]);
    }
    printf("\n");
    }
    else if (contador2 >= 2){  // si hay mas de una combinacion posible, po ende contador mayor o igual a 2
        printf("indeterminate\n");
    }
    else if(contador2 == 0){ // si ninguna combiancion paso la cerradura
        printf("impossible\n");
    }
}

int main(){
    int cases, guesses, i , k, number_cases;
    number_cases = 0;
    int array[10];
    scanf("%d", &cases);  // lectura de datos para el numero de casos
    while(cases > number_cases){
        scanf("%d", &guesses); // numero de intentos posibles
        Save data[10];
        char caracter1, caracter2;
        for(i = 0; i < guesses; ++i){  // este for permite almacenar la informacion en la estructura 
            scanf("%c",&caracter1);
            scanf("%c%c",&caracter1,&caracter2);
            data[i].num1 = caracter1 - '0';
            data[i].num2 = caracter2 - '0';
            scanf("%c%c",&caracter1,&caracter2);
            data[i].num3 = caracter1 - '0';
            data[i].num4 = caracter2 - '0';
            scanf("%c%d%c%d", &caracter1, &data[i].num5, &caracter2, &data[i].num6);
        }    
        solve(data, guesses); //invocaion de la funcion que resuleve el problema
        number_cases ++;
    }
    return 0;
}