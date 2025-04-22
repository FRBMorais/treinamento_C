/* 
    Programmer: Felipe Rosa 
    Date: 21/04
*/


#include <stdio.h>
 
int main() {
    
    int a, b;
    int temp;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    if(a == b) {
        printf("%d\n", 0);
        return 0;
    } else if (a > b) {
        temp = b;
        b = a;
        a = temp;
    }
    
    temp = 0;
    for(int i = a + 1; i < b; i++) {
        if( i & 1 ) {
            temp += i;
        }
    }
    
    printf("%d\n", temp);
    return 0;
}