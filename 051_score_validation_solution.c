/* 
    Programmer: Felipe Rosa 
    Date: 29/04
*/


#include <stdio.h>


int main() {
    
    float value; 
    float average;
    int counter = 0;
    
    while(counter < 2) {
        scanf("%f", &value);
        
        if(value >= 0 && value <= 10) {
            counter++;
            average += value;
        } else {
            printf("nota invalida\n");
        }
    }
    
    printf("media = %.2f\n", average / 2);
    return 0;
}