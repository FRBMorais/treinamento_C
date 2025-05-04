/* 
    Programmer: Felipe Rosa 
    Date: 03/04
*/


#include <stdio.h>
 
int isPerfect(int n) {
    if(n == 1) {
        return 0;
    }
    int sum = 0;

    int i = 1;
    while(sum < n) {
        sum += i;
        i++;
    }

    if(sum == n) {
        return 1;
    } else {
        return 0;
    }
}


int main() {

    int cases;
    int n;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++) {
        scanf("%d", &n);
        if(isPerfect(n)) {
            printf("%d eh perfeito\n", n);
        } else {
            printf("%d nao eh perfeito\n", n);
        }
    }
    return 0;
}