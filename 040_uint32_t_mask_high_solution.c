/* 
    Programmer: Felipe Rosa 
    Date: 18/04
*/


#include <stdio.h>

unsigned long mask_high(unsigned n, int number_bits) {
    if(n > number_bits) {
        n = number_bits;
    }
    unsigned long complete_value = (1U << number_bits) - 1;
    unsigned long mascara_lsb = (1U << (number_bits - n)) - 1;
    return complete_value & ~mascara_lsb; /* elimina os bits menos significativos*/
}


int main() {

    int n, n_bits;
    scanf("%d %d", &n, &n_bits);
    printf("%ld\n", mask_high(n, n_bits));

    return(0);
}