/* 
    Programmer: Felipe Rosa 
    Date: 25/04
*/


#include <stdio.h>
 
int main() {
    
    float i = 0, j = 1;

    int total_loop = 20 / 2; 
    for(int a = 0; a < total_loop + 1; a++) {
        
        for(int b = 0; b < 3; b++) {

            if( (int)(i * 100) == (int)(i) * 100) {
                printf("I=%.0f J=%.0f\n", i, j);
            } else {
                printf("I=%.1f J=%.1f\n", i, j);
            }
            
            j += 1;
        }
        i += 0.2;
        j += 0.2 - 3;
    }
    return 0;
}