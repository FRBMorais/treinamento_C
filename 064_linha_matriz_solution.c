/* 
    Programmer: Felipe Rosa 
    Date: 04/04
*/
#include <stdio.h>
#define DIMENSION 12


float calculaSoma(float matrix[][DIMENSION], int line) {
    float sum = 0;
    for(int j = 0; j < DIMENSION; j++) {
        sum += matrix[line][j];
    }
    return sum;
    
}


float calculaMedia(float matrix[][DIMENSION], int line) {
    return calculaSoma(matrix, line) / DIMENSION;
}


int main() {

    int L; /*input - L (0 ≤ L ≤ 11) indicando a linha que será considerada para operação*/
    char soma_media; /* input - caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média*/

    float matrix[DIMENSION][DIMENSION];
    scanf("%d %c", &L, &soma_media);

    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    if(soma_media == 'S') {
        printf("%.1f\n", calculaSoma(matrix, L));
    } else if(soma_media == 'M') {
        printf("%.1f\n", calculaMedia(matrix, L));
    }

    return 0;
}