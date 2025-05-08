/* 
    Programmer: Felipe Rosa 
    Date: 07/05
*/
#include <stdio.h>
 
int main() {
    
    int cases;
    scanf("%d", &cases);

    int r1, r2;
    for(int i = 0; i < cases; i++) {
        scanf("%d %d", &r1, &r2);

        printf("%d\n", r1 + r2);
    }

    return 0;
}