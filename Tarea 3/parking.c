#include <stdio.h>
#include <stdlib.h> 

// Marco Antonio Riascos Salguero 
// codigo: 8952273

int main(){
    int casos, array[100];
    scanf("%d", &casos);
    int flag = 0;
    int n = 0;
    int x = 0;\
    while (n < casos && flag != 1){
        int menor = 1000;
        int mayor = -1000;
        int result;
        scanf("%d",&x);
        int i = 0;
        while(i < x){
            scanf("%d",&array[i]);
            if (menor>array[i]){
                menor = array[i];
            }
            if (mayor<array[i]){
                mayor = array[i];
            }
            i++;
            if (i == x){
                result = (mayor-menor)*2;
                printf("%d\n",result);
            }
        }
        n++;
        if (n == casos){
            flag = 1;
        }
    }
    return 0;
}