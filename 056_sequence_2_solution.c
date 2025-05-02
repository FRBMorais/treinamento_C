/* 
    Programmer: Felipe Rosa 
    Date: 02/04
*/

#include <stdio.h>
 
int main() {
 
    float sum = 1.0;
    int numerador = 3;
    int denominador = 2;
    
    while(numerador <= 39) {
        sum += (float)numerador / denominador;
        numerador = numerador + 2;
        denominador = denominador << 1;

        
    }
    
    printf("%.2f\n", sum);
    return 0;
}