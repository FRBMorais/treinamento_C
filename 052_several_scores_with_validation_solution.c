/* 
    Programmer: Felipe Rosa 
    Date: 29/04
*/


#include <stdio.h>

int new_calculus(int *counter) {
    
    int validator = 0;

    while(validator != 1 && validator != 2) {
        
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &validator);
        if (validator == 1) {
            *counter = 0;
            return 0;
        } else if(validator == 2) {
            return 1;
        }
    }


}

int main() {
    
    float value; 
    float average;
    int counter = 0;
    int validator;

    while(counter < 2) {
        
        scanf("%f", &value);
        
        if(value >= 0 && value <= 10) {
            counter++;
            average += value;
        } else {
            printf("nota invalida\n");
        }

        if(counter == 2) {
            printf("media = %.2f\n", average / 2);
            average = 0;
            
            validator = new_calculus(&counter);

            if (validator){
                return 0;
            } 
        }

    }
    
   
    return 0;
}