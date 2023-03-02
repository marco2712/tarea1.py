// lock
#include <stdio.h>

// Marco Antonio Riascos Salguero 
// codigo: 8952273

int main(){
    int r, l, r2, l2, grades, suma;
     int stop = 0;
    scanf("%d %d %d %d", &r, &l, &r2, &l2);
    while (stop != 1){
        if(r == 0 && l == 0 && r2 == 0 && l2 ==0){
            stop = 1;
        }
        else{
            grades = 720;
            int giro1;
            int giro2;
            int giro3;
            giro1 = (40 + (l - r)) % 40;
            giro2 = (40 + (r - r2)) % 40;
            giro3 = (40 + (l2 - r2)) % 40;
            suma = grades + (giro1 * 9)  + (giro2 * 9) + (giro3 * 9);
            printf("%d\n",suma);
            scanf("%d %d %d %d", &r, &l, &r2, &l2);
        }
    }    
        
    return 0;
}