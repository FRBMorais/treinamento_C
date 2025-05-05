/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/

#include <stdio.h>


int main() {
	
    int n, last_digit;
    scanf("%d", &n);
    
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        last_digit = n % 10;
        n = n / 10;

        sum += last_digit;
    }

    printf("%d\n", sum);
    return 0;
}