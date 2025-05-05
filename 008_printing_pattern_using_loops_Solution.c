/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	
    // Complete the code to print the pattern.
    /* preciso fazer um quadrado com cada um dos inteiros*/
    
    /*
    1 -> 1 - ok
    2 -> 3 - ok
    3 -> 5 - ok
    4 -> 7 - ok
    5 -> 9 - ok
    n -> (n - 1) * 2 + 1 - quantidade de elementos por linha
    
    mesma quantidade de linhas e colunas, eh um quadrado
    */
    
    int limite_superior = (n - 1) * 2 + 1;
    
    int a = 1;  /* Cursor lado esquerdo */
    int b = limite_superior - 1; /* Cursor lado direito*/
    
    for (int i = 1; i <= limite_superior; i++) {
        
        int value = n;
        
        for (int j = 1; j <= limite_superior; j++) {
            
            printf("%d ", value);
            
            if (j < a) {
                value -= 1;
            } else if (j > b) {
                value += 1;
            }
            
        }
        
        printf("\n"); 
        
        if(i <= (limite_superior - 1) / 2) {
            a += 1;
        } else {
            a -= 1;
        }
        
        if(i <= (limite_superior - 1) / 2) {
            b -= 1;
        } else {
            b += 1;
        }
        
    
    }
    
    return 0;
}
