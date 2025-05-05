/* 
    Programmer: Felipe Rosa 
    Date: 05/05
*/
#include <stdio.h>
#define SIZE 201


void quantidades(int v[], size_t n) {
    v[0] = 1;
    for (size_t i = 1; i < n; ++i) {
        v[i] = v[i - 1] + i;
    }
}

void sequence(int sequence[]) {
    
    sequence[0] = 0;
    int pos = 1;
    for(int i = 1; i < SIZE; i++) {
        for(int j = 0; j < i; j++) {
            sequence[pos] = i;
            pos++;
        }
    }
}


void showSequence(int v[], int n, int quant_elem) {
    
    int i = 0;
    while(v[i] <= n) {
        
        if(quant_elem == i + 1) {
            printf("%d", v[i]);
            i++;
        } else {
            printf("%d ", v[i]);
            i++;

        }
    }
    printf("\n\n");
}


int main(void) {
    int quantidade[SIZE];
    quantidades(quantidade, SIZE);

    int *seq;
    int num_elementos = quantidade[200];

    // Aloca memória para 10 inteiros e inicializa com zero
    seq = (int *)calloc(num_elementos, sizeof(int));
    sequence(seq);

    int N;
    int i = 1;
    while (scanf("%d", &N) != EOF) {

        if(N == 0) {
            printf("Caso %d: %d numero\n", i, quantidade[N]);
            showSequence(seq, N, quantidade[N]);
        } else {
            printf("Caso %d: %d numeros\n", i, quantidade[N]);
            showSequence(seq, N, quantidade[N]);
        }
        i++;
    }

    free(seq);
}
