/* 
    Programmer: Felipe Rosa 
    Date: 13/04
*/


#include <stdio.h>


void calculate_the_maximum(int n, int k) {
  
  int maior_and = 0;
  int maio_or = 0;
  int maior_xor = 0;
  
  for(int a = 1; a < n; a++) {
    for(int b = a + 1; b <= n; b++) {
        
        if( (a & b) > maior_and && (a & b) < k) {
            maior_and = a & b;
        }
        
        if( (a | b) > maio_or && (a | b) < k) {
            maio_or = a | b;
        }
        
        if( (a ^ b) > maior_xor && (a ^ b) < k) {
            maior_xor = a ^ b;
        }
    }
   }
   
    
  printf("%d\n", maior_and);
  printf("%d\n", maio_or);
  printf("%d\n", maior_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
