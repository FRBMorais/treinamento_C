/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/


#include <stdio.h>
#include <stdlib.h>

/* ponteiros em C, podemos declarar de duas formas, nao faz diferenca
int* a, b;
int *a, *b;
*/
void update(int *a, int *b) { /* como na declaracao de ponteiros, precisamos usar a syntaxe de asterisco */
    int old_a = *a;  /* precisamos armazenar o valor de a, para podermos usar no calculo do b */
    *a = *a + *b;  /* diferentemente do outro asterisco, aqui eh para desreferenciar o ponteiro, e usar o valor real */
    *b = abs(old_a - *b);
}


int main() {
    int a, b;
    int *pa = &a; int *pb = &b;
    
    scanf("%d %d", &a, &b);

    update(pa, pb);

    printf("%d\n%d", a, b);
}