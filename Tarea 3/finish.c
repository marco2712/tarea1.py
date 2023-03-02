#include <stdio.h>

// Marco Antonio Riascos Salguero
// codigo: 8952273

int main(){
    int t, casos, gas, k;
    int array[100001];
    int array2[100001];
    scanf("%d", &t);
    casos = 1;
    while(casos <= t){
        int i = 0;
        int j = 0;
        scanf("%d",&gas);
        while(i < gas){
            scanf("%d", &array[i]);
            i++;
        }
        while(j < gas){
            scanf("%d", &array2[j]);
            j++;
        }
        k = 0;
        int flag = 0;
        int position = 0;
        int suma = 0;
        int resta = 0;
        int totalsuma = 0;
        int totalresta = 0;
        while(k < gas){
            totalsuma += array[k];
            totalresta += array2[k];
            if(array[k] >= array2[k] || flag == 1){
                if(flag != 1){
                    position = k+1;
                    flag = 1;
                }
                suma += array[k];
                resta += array2[k];  
                if(resta > suma){
                    flag = 0;
                    suma = 0;
                    resta = 0;
                }              
            }    
            k ++;
        }
        if(suma >= resta && totalsuma >= totalresta){
            printf("Case %d: Possible from station %d\n", casos, position);
        }
        else{
                printf("Case %d: Not possible\n", casos);
            }
        casos ++;
    }
    return 0;
}