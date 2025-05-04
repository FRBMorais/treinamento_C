/* 
    Programmer: Felipe Rosa 
    Date: 03/04
*/


#include <stdio.h>
 

int main() {
 
    int cases;
    long long init, n, a_n;
    long long output;
    
    scanf("%d", &cases);
    
    for(int i = 0; i < cases; i++) {
        
        scanf("%lld %lld", &init, &n);
        
        if(!(init & 1)) {
            init++;
        }
        
       
        a_n = init + 2 * (n - 1);
        output = (init + a_n) * n / 2;
    
        printf("%lld\n", output);
        
    }
 
    return 0;
}