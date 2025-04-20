#include <stdio.h>
#define INPUT_SIZE 6


int main() {

    float number;
    float soma = 0;
    int quantity = 0;

    for(int i = 0; i < INPUT_SIZE; i++) {
        scanf("%f", &number);

        if(number > 0) {
            soma += number;
            quantity++; 
        }
    }

    printf("%d valores positivos\n", quantity);
    printf("%.1f\n", soma / quantity);
    return 0;
}