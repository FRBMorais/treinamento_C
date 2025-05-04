/* 
    Programmer: Felipe Rosa 
    Date: 04/04
*/


#include <stdio.h>
#define max_size_vetor 5
#define numero_entradas 15


void imprimeVetorPar(int vetor[], int size_vetor) {
    for(int i = 0; i < size_vetor; i++) {
        printf("par[%d] = %d\n", i, vetor[i]);
    }
}


void imprimeVetorImpar(int vetor[], int size_vetor) {
    for(int i = 0; i < size_vetor; i++) {
        printf("impar[%d] = %d\n", i, vetor[i]);
    }
}


int main() {
 
    int pares[max_size_vetor], impares[max_size_vetor];
    
    int cursor_pares = 0;
    int cursor_impares = 0;
    int valor;
    
    for(int i = 0; i < numero_entradas; i++) {
        
        scanf("%d", &valor);
        
        if(valor & 1) {
            impares[cursor_impares] = valor;
            cursor_impares++;
        } else {
            pares[cursor_pares] = valor;
            cursor_pares++;
        }
        
        if(cursor_impares == max_size_vetor) {
            imprimeVetorImpar(impares, max_size_vetor);
            cursor_impares = 0;
        }

        if(cursor_pares == max_size_vetor) {
            imprimeVetorPar(pares, max_size_vetor);
            cursor_pares = 0;
        }
    }
    
    imprimeVetorImpar(impares, cursor_impares);
    imprimeVetorPar(pares, cursor_pares);

    return 0;
}