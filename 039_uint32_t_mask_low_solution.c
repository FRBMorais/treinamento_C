/* 
    Programmer: Felipe Rosa 
    Date: 18/04
*/


#include <stdio.h>

long long uint32_t_mask_low(int n) {
    return (1U << n) - 1; /* primeiro geramos uma potencia de 2, exemplo 32 -> 32 - 1 = 31
                            quando subtraimos 1, essa potencia vira 0, 
                            porem todos os anteriores viram 1 */
}


int main() {

    int number;
    scanf("%d", &number);
    printf("%lld\n", uint32_t_mask_low(number));

    return(0);
}