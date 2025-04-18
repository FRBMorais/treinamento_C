/* 
    Programmer: Felipe Rosa 
    Date: 18/04
*/

#include <stdio.h>
 
int main() {
 
    float number;
    scanf("%f", &number);
    
    if(number >= 0 && number <= 2000.00) {
        printf("Isento\n");
    } else if (number > 2000.00 && number <= 3000.00) {
        float parcela_1 = (number - 2000.00) * 0.08;
        printf("R$ %.2f\n", parcela_1);
    } else if (number > 3000.00 && number <= 4500.00) {
        float parcela_1 = (3000.00 - 2000.00) * 0.08;
        float parcela_2 = (number - 3000.00) * 0.18;
        printf("R$ %.2f\n", parcela_1 + parcela_2);
    } else if (number > 4500.00) {
        float parcela_1 = (3000.00 - 2000.00) * 0.08;
        float parcela_2 = (4500.00 - 3000.00) * 0.18;
        float parcela_3 = (number - 4500.00) * 0.28;
        printf("R$ %.2f\n", parcela_1 + parcela_2 + parcela_3);
    }
        
    return 0;
}