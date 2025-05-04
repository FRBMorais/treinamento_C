/* 
    Programmer: Felipe Rosa 
    Date: 04/04
*/


#include <stdio.h>
 

int ehPrimo(int n) {

    int counter = 0;
    int init = 1;

    while(counter <= 2 && init <= n) {
        if((n % init) == 0) {
            counter++;
        }
        init++;
    }

    if(counter == 2) {
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
        if(ehPrimo(n)) {
            printf("%d eh primo\n", n);
        } else {
            printf("%d nao eh primo\n", n);
        }
    }
    return 0;
}