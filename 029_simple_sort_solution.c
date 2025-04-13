/* 
    Programmer: Felipe Rosa 
    Date: 13/04
*/


#include <stdio.h>
#define SIZE_ARRAY 3


void bubbleSort(int len_array, int arr[]) {
    
    int temp;
    for(int i = 0; i < len_array - 1; i++) {
        
        for(int j = 0; j < len_array - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
               temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
            }        
        }
    }

    
}


int main() {
    
    int arr[SIZE_ARRAY];
    int arr_result[SIZE_ARRAY];


    for(int i = 0; i < SIZE_ARRAY; i++) {
        scanf("%d", &arr[i]);
        arr_result[i] = arr[i];
    }
    
    bubbleSort(sizeof(arr_result) / sizeof(int), arr_result);
    
    for(int i = 0; i < SIZE_ARRAY; i++) {
        printf("%d\n", arr_result[i]);
    }
    
    printf("\n");
    
    for(int i = 0; i < SIZE_ARRAY; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}


