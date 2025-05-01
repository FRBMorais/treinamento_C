/* 
    Programmer: Felipe Rosa 
    Date: 30/04
*/

#include <stdio.h>
 
int main() {
 
    int entrada;
    scanf("%d", &entrada);
    
    do {
        for(int i = 1; i <= entrada; i++) {
            printf("%d ", i);
        }
        printf("\n");
        scanf("%d", &entrada);
    } while (entrada != 0);
 
    return 0;
}