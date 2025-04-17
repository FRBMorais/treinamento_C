#include <stdio.h>
 
int main() {
 
    float sum = 0;
    float nota, media;
    
    float pesos[4] = {2, 3, 4, 1};

    for(int i = 0; i < 4; i++) {
        scanf("%f", &nota);
        sum += nota * pesos[i];
    }
    
    media = sum / 10;
    
    printf("Media: %.1f\n", media);
    if(media >= 7.0) {
        printf("Aluno aprovado.\n");
        return 0;
    } else if (media < 5.0) {
        printf("Aluno reprovado.\n");
        return 0;
    } else {
        printf("Aluno em exame.\n");
        scanf("%f", &nota);
        sum += nota;
    }
    
    printf("Nota do exame: %.1f\n", nota);
    
    media = (nota + media) / 2;
    
    if(media >= 5.0) {
        printf("Aluno aprovado.\n");
    } else {
        printf("Aluno reprovado.\n");
    }
    
    printf("Media final: %.1f\n", media);
    
    return 0;
}