/* 
    Programmer: Felipe Rosa 
    Date: 03/04
*/
#include <stdio.h>


int main() {

    int T; /* input - quantity tests cases (1 ≤ T ≤ 3000) */
    int PA, PB; /* input - populacoes da cidade A e B, (100 ≤ PA < 1000000, PA < PB ≤ 1000000)*/
    double G1, G2; /* input - crescimento populacional em %, (0.1 ≤ G1 ≤ 10.0, 0.0 ≤ G2 ≤ 10.0, G2 < G1) */
    scanf("%d", &T);
    
    int anos;
    for(int i = 0; i < T; i++) {
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

        anos = 0;
        while( (PB >= PA)) {
            PB = PB * (1 + (float)G2 / 100);
            PA = PA * (1 + (float)G1 / 100);
            anos++;
            if (anos > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }

        if (anos <= 100) {
            printf("%d anos.\n", anos);
        }
    }

    return 0;

}