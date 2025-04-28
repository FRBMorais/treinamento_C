/* 
    Programmer: Felipe Rosa 
    Date: 25/04
*/

#include <stdio.h>
 

int order(int *a, int *b) {
    
    int temp;
    if(*a > *b) {
        temp = *b;
        *b = *a;
        *a = temp;
    }
}


int sum_odd(int a, int b) {
    
    int first_number_sequence;
    int last_number_sequence;
    int number_elements;
    
    if(a & 1) {
        first_number_sequence = a + 2;
    } else {
        first_number_sequence = a + 1;
    }
    
    if(b & 1) {
        last_number_sequence = b - 2;
    } else {
        last_number_sequence = b - 1;
    }
    
    number_elements = (last_number_sequence - first_number_sequence) / 2 + 1;
    
    if(number_elements & 1) {
       return (last_number_sequence + first_number_sequence) * ((number_elements - 1) / 2) + (last_number_sequence + first_number_sequence) / 2;
    } else {
       return (last_number_sequence + first_number_sequence) * number_elements / 2;
    }
     
}


int main() {
    
    int N;
    int a, b;
    int answer;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        
        if(a == b) {
            printf("%d\n", 0);
        } else {
            order(&a, &b);
            answer = sum_odd(a, b);
            printf("%d\n", answer);
        }
        
    }
    
    return 0;
}