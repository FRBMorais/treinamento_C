/* 
    Programmer: Felipe Rosa 
    Date: 04/04
*/


#include <stdio.h>
#define MAX_SIZE 61

void fillFibVector(long long fib[], int size) {
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i < size; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}


int main() {
 
    int T;
    long long fib[MAX_SIZE];
    int test;
    
    fillFibVector(fib, MAX_SIZE);
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++) {
        scanf("%d", &test);
        
        printf("Fib(%d) = %lld\n", test, fib[test]);
    }
 
    return 0;
}