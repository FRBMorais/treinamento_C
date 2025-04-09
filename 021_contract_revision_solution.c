#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_SIZE 101

/* assinaturas */
void safeFgets(char *str, int size);
void clearBuffer(void);
void processString(char str[], int size_string, char ignored_char, char str_result[]);


int main() {

    char ignored_char;
    char N[MAX_NUMBER_SIZE];
    char N_result[MAX_NUMBER_SIZE];
    int primeiro = 0;

    do {

        scanf("%c", &ignored_char);
        getchar();
        safeFgets(N, MAX_NUMBER_SIZE);

        if ( ignored_char == '0' && N[0] == '0' ) {
            printf("\n");
            break;
        } else if (primeiro != 0) {
            printf("\n");
        }

        processString(N, strlen(N), ignored_char, N_result);

        for (int i = 0; i < strlen(N_result); i++) {
            printf("%c", N_result[i]);
        }
        primeiro += 1;

    } while ( 1 );


    return(0);
}



/*
 * safeFgets:
 * Lê uma linha da entrada padrão usando fgets e remove a quebra de linha, se presente.
 * Se a leitura falhar, garante que a string seja inicializada como vazia.
 */
void safeFgets(char *str, int size) {
    if (fgets(str, size, stdin) == NULL) {
        str[0] = '\0';   // Garante que a string fique vazia caso fgets falhe
        return;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    } else {
        /* Se a linha lida ocupou todo o buffer e não contém '\n',
           é provável que haja caracteres sobrando, então limpamos o buffer. */
        clearBuffer();
    }
}


/*
 * clearBuffer:
 * Limpa o buffer de entrada consumindo todos os caracteres até o '\n' ou EOF.
 */
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void processString(char str[], int size_string, char ignored_char, char str_result[]) {
    
    int flag_left_zero = 1;
    int flag_has_zero = 0;
    int str_result_index = 0;

    for (int i = 0; i < size_string; i++) {
        if (str[i] == '0' && flag_left_zero == 1) {
            flag_has_zero += 1;
        } else if (str[i] != ignored_char) {
            str_result[str_result_index] = str[i];
            str_result_index += 1;
            flag_left_zero -= 1;
        } 
    }

    if (flag_has_zero > 0 && flag_left_zero == 1) {
        str_result[0] = '0';
        str_result[1] = '\0';

    } else if (str_result_index == 0) {
        str_result[0] = '0';
        str_result[1] = '\0';
    }
    else {
        str_result[str_result_index] = '\0';
    }   

    
}