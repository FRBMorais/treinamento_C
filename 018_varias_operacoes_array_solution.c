/* 
    Programmer: Felipe Rosa 
    Date: 06/04
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool isPalindrome(int arr[], int length) {

    for(int i = 0; i < length / 2; i++){
        if( arr[i] != arr[length - i - 1]) {
            return false;
        }
    }

    return(true);
}


void printArrayInvertido(int arr[], int length) {
    
    printf("Array invertido: ");
    for(int i = length - 1; i > -1; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


int segundo_maior(int arr[], int length) {
    int maior_valor, segundo_maior; 
    
    if (arr[0] >= arr[1]){
        maior_valor = arr[0];
        segundo_maior = arr[1];
    } else {
        maior_valor = arr[1];
        segundo_maior = arr[0];
    }


    for (int i = 0; i < length; i++) {

        if (arr[i] > maior_valor) {
            segundo_maior = maior_valor; 
            maior_valor = arr[i];
        } else if (arr[i] > segundo_maior && arr[i] < maior_valor) {
            segundo_maior = arr[i];
        }
    }

    if (maior_valor == segundo_maior) {
        return(999);
    } else {
        return segundo_maior;
    }
    
}


int quantidade_pares(int arr[], int length) {
   int cont_quantidade_pares = 0;
   
   for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0){
            cont_quantidade_pares += 1;

        }
   }

   return cont_quantidade_pares;
}


int quantidade_impares(int arr[], int length) {
    int cont_quantidade_impares = 0;
   
    for (int i = 0; i < length; i++) {
         if (arr[i] % 2 != 0){
            cont_quantidade_impares += 1;
 
         }
    }
 
    return cont_quantidade_impares;
 }
 


double media(int arr[], int length) {
    
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    return (float)sum / length;
}


int maior_valor(int arr[], int length) {
    
    int maior = arr[0];
    for(int i = 0; i < length; i++) {
        if(arr[i] > maior) {
            maior = arr[i];
        }
    }

    return maior;
}


int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int)); /* Alocacao dinamica do array */


    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    if (n == 0) {
        printf("Array vazio. Nenhum valor fornecido.");
    } else {
        
        printf("Maior valor: %d\n", maior_valor(arr, n));
        printf("Média: %.1f\n", media(arr, n));
        
        if(isPalindrome(arr, n)) {
            printf("Array é palíndromo.\n");
        } else {
            printf("Array não é palíndromo.\n");
        }
        
        printArrayInvertido(arr, n);

        if (segundo_maior(arr, n) == 999) {
            printf("Segundo maior valor: N/A\n");
        } else {
            printf("Segundo maior valor: %d\n", segundo_maior(arr, n));
        }
        
        printf("Pares: %d\n", quantidade_pares(arr, n));
        printf("Ímpares: %d\n", quantidade_impares(arr, n));
    }


    free(arr);
    return(0);
}