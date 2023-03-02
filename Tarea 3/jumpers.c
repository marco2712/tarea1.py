// Jumpers    
#include <stdio.h>
#include <math.h>

// Marco Antonio Riascos Salguero 
// codigo: 8952273


int main(){
    int i ;
    int k ;
    int array[3000];
    int resta;
    int flag;
    while(scanf("%d", &array[0])!= EOF){
        k = 2;
        i = 1;
        while( i <= array[0]){
            scanf("%d", &array[i]);
         ++i;   
        }  
        flag = 0;
        while(k <= array[0] && flag == 0){
            resta = fabs(array[k] - array[k -1]);
            if (resta >= array[0]){
                flag = 1;
            }
            ++ k;
        }    
        if(flag == 1){
            printf("Not jolly\n");
        } 
        else{
            printf("Jolly\n");
        }   
    }          
    return 0;
}