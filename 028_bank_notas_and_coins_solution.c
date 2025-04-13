#include <stdio.h>
 
int main() {
 
    double input_number;
    int integer_part;
    int float_part;
    
    scanf("%lf", &input_number);
    
    integer_part = input_number / 1;
    
    int notas_100, 
        notas_50, 
        notas_20, 
        notas_10, 
        notas_5, 
        notas_2,
        restante;
        
    notas_100 = integer_part / 100;
    restante = integer_part % 100;
    
    notas_50 = restante / 50;
    restante %= 50;
    
    notas_20 = restante / 20;
    restante %= 20;
    
    notas_10 = restante / 10;
    restante %= 10;
    
    notas_5 = restante / 5;
    restante %= 5;
    
    notas_2 = restante / 2;
    restante %= 2;
    
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas_100);
    printf("%d nota(s) de R$ 50.00\n", notas_50);
    printf("%d nota(s) de R$ 20.00\n", notas_20);
    printf("%d nota(s) de R$ 10.00\n", notas_10);
    printf("%d nota(s) de R$ 5.00\n", notas_5);
    printf("%d nota(s) de R$ 2.00\n", notas_2);
    
    int moeda_1,
        moeda_50,
        moeda_25, 
        moeda_10, 
        moeda_05, 
        moeda_01;
        
    moeda_1 = restante;
    
    float_part = (input_number - integer_part) * 100;
    
    moeda_50 = float_part / 50;
    restante = float_part % 50;
    
    moeda_25 = restante / 25;
    restante %= 25;
    
    moeda_10 = restante / 10;
    restante %= 10;
    
    moeda_05 = restante / 5;
    restante %= 5;
    
    moeda_01 = restante;
    
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moeda_1);
    printf("%d moeda(s) de R$ 0.50\n", moeda_50);
    printf("%d moeda(s) de R$ 0.25\n", moeda_25);
    printf("%d moeda(s) de R$ 0.10\n", moeda_10);
    printf("%d moeda(s) de R$ 0.05\n", moeda_05);
    printf("%d moeda(s) de R$ 0.01\n", moeda_01);
    return 0;
}