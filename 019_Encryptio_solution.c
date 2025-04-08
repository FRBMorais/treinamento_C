/* 
    Programmer: Felipe Rosa 
    Date: 07/04
*/

#include <stdio.h>


char step_1(char x) {
    
    if(x >= 'a' && x <= 'z') {
        x += 3;
    } else if (x >= 'A' && x <= 'Z') {
        x += 3;
    }
    return x;

}


void step_2_reverse_array(char array[], int len_array) {

    char temp;
    for (int i = 0; i < len_array / 2; i++) {
        temp = array[i];
        array[i] = array[len_array - i - 1];
        array[len_array - i - 1] = temp;
    }
}


char step_3(char x) {
    
    return x - 1;

}




int main() {

    int n;
    scanf("%d", &n); /* Quantidade de linhas a serem encryptadas */
    getchar(); // consome o '\n' após o número

    char m[1000];

    for (int i = 0; i < n; i++) {
        int i_c = 0; 
        do {
            scanf("%c", &m[i_c]);
            i_c++;    
        } while(m[i_c - 1] != '\n'); 

        for(int a = 0; a < i_c - 1; a++) {
            m[a] = step_1(m[a]);
        }

        step_2_reverse_array(m, i_c - 1);

        for(int a = (i_c - 1) / 2; a < i_c - 1; a++) {
            m[a] = step_3(m[a]);
        }

        for(int a = 0; a < i_c - 1; a++) {
            printf("%c", m[a]);
        }

        printf("\n");

    }
    return(0);
}


