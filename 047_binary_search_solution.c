/* 
    Programmer: Felipe Rosa 
    Date: 23/04
*/


#include <stdio.h>


int search(int* nums, int numsSize, int target) {
    
    int a = 0;
    int b = numsSize - 1;
    int mid;
    
    while(a <= b) {
        mid = a + ((b - a) >> 1);

        if( nums[mid] == target ) {
            return mid;
        } else if ( nums[mid] > target) {
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }

    return -1;
}

int main() {

    int vetor[6] = {-1,0,3,5,9,12};
    int resposta = search(vetor, 6, 9);

    printf("%d", resposta);
}