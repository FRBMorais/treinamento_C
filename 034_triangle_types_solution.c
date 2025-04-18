/* 
    Programmer: Felipe Rosa 
    Date: 17/04
*/


#include <stdio.h>
#include <math.h>

#define SIZ_ARRAY 3


int bubbleSort(double arr[], int len_array) {
    
    double temp;
    
    for(int i = 0; i < len_array - 1; i++) {
        for(int j = 0; j < len_array - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    
    double arr[SIZ_ARRAY];
    
    scanf("%lf", &arr[0]);
    scanf("%lf", &arr[1]);
    scanf("%lf", &arr[2]);
    
    bubbleSort(arr, 3);
    
    if(arr[2] >= arr[0] + arr[1]) {
        printf("NAO FORMA TRIANGULO\n");
        return(0);
    } 
    
    if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0]) {
        printf("TRIANGULO RETANGULO\n");
    } 
    
    if (arr[2] * arr[2] > arr[1] * arr[1] + arr[0] * arr[0]) {
        printf("TRIANGULO OBTUSANGULO\n");
    } 
    
    if (arr[2] * arr[2] < arr[1] * arr[1] + arr[0] * arr[0]) {
        printf("TRIANGULO ACUTANGULO\n");
    } 
    
    if(arr[2] == arr[0] && arr[1] == arr[2]) {
        printf("TRIANGULO EQUILATERO\n");
    } 
    
    if ( (arr[2] == arr[0] && arr[2] != arr[1]) || (arr[1] == arr[2] && arr[1] != arr[0]) || (arr[0] == arr[1] && arr[0]  != arr[2])) {
        printf("TRIANGULO ISOSCELES\n");
    }
    
    return 0;
}


