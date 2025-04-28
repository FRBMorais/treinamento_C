/* 
    Programmer: Felipe Rosa 
    Date: 28/04
*/

#include <stdio.h>
 
 
void order(int *a, int *b) {
    int temp;
    if(*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}


void show_result(int a, int b) {
    
    int sum = 0;
    for(int i = a; i <= b; i++) {
        printf("%d ", i);
        sum += i;
    }
    printf("Sum=%d\n", sum);
}


int main() {
 
    int a = 1, b = 1;
    scanf("%d %d", &a, &b);
    
    do {
        order(&a, &b);
        show_result(a, b);
        scanf("%d %d", &a, &b);
        
    } while (a > 0 && b > 0);
    
    return 0;
}