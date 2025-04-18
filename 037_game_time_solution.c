#include <stdio.h>
 
int main() {

    int hrs_inicio, hrs_fim, hrs_duracao;
    scanf("%d %d", &hrs_inicio,  &hrs_fim);
    
    if(hrs_fim > hrs_inicio) {
        hrs_duracao = hrs_fim - hrs_inicio;
    } else if (hrs_inicio == hrs_fim) {
        hrs_duracao = 24;
    } else {
        hrs_duracao = 24 - hrs_inicio;
        hrs_duracao += hrs_fim;
    }
    
    printf("O JOGO DUROU %d HORA(S)\n", hrs_duracao);
    
    return 0;
}