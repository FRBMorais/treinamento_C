/* 
    Programmer: Felipe Rosa 
    Date: 05/05
*/
#include <stdio.h>
#define DIMENSION 12


float calculaSoma(float matrix[][DIMENSION]) {
    float sum = 0;

    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            if( j > i) {
                sum += matrix[i][j];
            }
            
        }
    }
    return sum;
    
}


float calculaMedia(float matrix[][DIMENSION]) {
    int qtd = (DIMENSION * DIMENSION - DIMENSION) / 2; // 66
    return calculaSoma(matrix) / qtd;
}


int main() {

    char soma_media; /* input - caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média*/

    float matrix[DIMENSION][DIMENSION];
    scanf("%c", &soma_media);

    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    if(soma_media == 'S') {
        printf("%.1f\n", calculaSoma(matrix));
    } else if(soma_media == 'M') {
        printf("%.1f\n", calculaMedia(matrix));
    }

    return 0;
}