/* 
    Programmer: Felipe Rosa 
    Date: 29/04
*/

#include <stdio.h>
 
 
int calculate_13_divisible(int n) {

    if ( n % 13 == 0 ) {
        return 1;
    } else {
        return 0;
    }
} 

void order(int *a, int *b) {
    int temp;
    if(*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}


int main() {
 
    int x, y;
    int sum = 0;
    
    scanf("%d %d", &x, &y);
    order(&x, &y);

    for(int i = x; i <= y; i++) {  
        if(!calculate_13_divisible(i)) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}