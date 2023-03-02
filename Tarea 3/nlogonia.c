#include <stdio.h>


// Marco Antonio Riascos Salguero
// codigo: 8952273
//     Punto B - nlogonia 

int main(){
    int k, n, m, x,y,i;
    scanf("%d", &k);
    while(k != 0){
        scanf("%d %d",&n ,&m);
        for(i = 0; i < k; i ++){
            scanf("%d %d", &x, &y);
            if (x == n || m == y){
                printf("divisa\n");
            }    
            else if (x < n && y > m ){
                printf("NO\n");
            }  
            else if (x > n && y > m ){
            printf("NE\n");
            }  
            else if (x < n && y < m ){
                printf("SO\n");
            }
            else if (x > n && y < m ){
                printf("SE\n");
            }
        }
        scanf("%d", &k);
    }
    return 0;
}