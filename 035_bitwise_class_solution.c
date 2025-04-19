/* 
    Programmer: Felipe Rosa 
    Date: 17/04 - 18/04
*/


#include <stdio.h>
#include <stdbool.h>


int extract_msb(int n) {
    /*
    1. Write a function that takes an integer as an argument and returns the MSB (most
    significant bit) as a new integer. For example, extract_msb(10) should return 1
    (binary: 1010).
    */

    int resposta;
    int last_digit;
    
    while( n > 0) {
        last_digit = n & -n;
        n = n ^ last_digit;
        if (n > 0) {
            resposta = n;
        }
    }
}

int extract_msb_verificar_nth(int n, int x) {

    /* 1. Write a function that takes an integer (4 bits) as an argument and returns the MSB
    (most significant bit) as a new integer. For example, extract_msb(10) should return 1
    (binary: 1010). */
    
    int new_value = n & ~(1 << (x - 1));

    if (new_value == n) { /* se o numero continua igual, quer dizer que era zero*/
        return(0);
    } else {
        return(1);
    }
}

int extract_lsb(int n) {
    /*
    2. Create a function that takes an integer (4 bits) as an argument and returns the LSB
    (least significant bit) as a new integer. For example, extract_lsb(10) should return 0
    (binary: 1010).
    */
    return (n << 3) & 0xF;

}

int isolate_msb(int number_b2, int n) {
    /*3. Write a function that takes an integer (4 bits) and a value n as arguments and returns a
    new integer with the n most significant bits isolated. For example, isolate_msb(10,2)
    should return 2 (binary: 10). */
    /*  tratamento limites */

    if(n < 0) {
        return (0); 
    } else if (n > 4) {
        return number_b2 & 0xF;
    }
    return number_b2 >> (4 - n);
}

int isolate_lsb(int number_b2, int n) {
    /* 4. Create a function that takes an integer (4 bits) and a value n as arguments and returns
    a new integer with the n least significant bits isolated. For example,
    isolate_lsb(10,2) should return 2 (binary: 10). */
    
    int mascara = 0;

    for(int i = 0; i < n; i++) { /* 0000011111 com 1 n vezes, fazendo and, eliminamos a parte a esquerda*/
        mascara = mascara | (1 << i);
    }

    return number_b2 & mascara;
}

int invert_bits(int n) {
    /*
    7. Write a function that takes a non-negative integer (4 bits) and returns the number with
    all bits inverted. For example, invert_bits(5) should return 10 (binary: 1010).
    */
    int mask4 = 0;
    int numero_bits = 4;

    for(int i = 0; i < numero_bits; i++) { /* 0000011111 com 1 n vezes, fazendo and, eliminamos a parte a esquerda*/
        mask4 = mask4 | (1 << i);
    }
    return (~n) & mask4;
}

int isolate_nibble_ms(int n){
    /* 8. Write a function that takes a non-negative integer (8 bits) and returns the most
    significant nibble (the 4 leftmost bits) as a new integer. For example,
    isolate_nibble_ms(240) should return 15 (binary: 1111).
    A nibble represents half of a byte, i.e. a nibble is composed of 4 consecutive bits.*/

    return n >> 4;
}


int isPowerOfTwo(unsigned int n) {
    /*
    11. Use bitwise operators to check if an integer is a power of 2.
    */

    /* explicacao, uma potencia de dois, tem apenas 1 bit positivo 
       8 -> 1000, quando subtraimos 1, invertemos todos ->n
       7 -> 0111,

       fazendo 8 & 7 - n & (n - 1), se retornar 0, eh pq eh potencia de 2, por isso !(n & (n - 1))

       mas se o numero ja for 0, teriamos um problema, por isso o inicio n && (alguma coisa),
       ja verifica se o n eh diferente de 0
    */
    return n && !(n & (n - 1)); 
}


int count_bits_1(int n) {
    /* 17. Write a function that takes a non-negative integer and returns the number of 1 bits in
    its binary representation. For example, count_bits_1(5) should return 2 (binary: 101).*/
    if (n == 0) {
        return 0;
    }

    int count = 0;

    while (n != 0) {
        n = n & (n - 1); /* extract the right-most set bit */
        count += 1;
    }

    return count;
}


int is_even(int n) {
    /* 18. Use bitwise operators to check whether an integer is even or odd. */
    /* par */
    return !(n & 1);
}

int is_odd(int n) {
    /* impar */
    return (n & 1);
}


int convert_decimal(char string_input[]) {
    /*
    22. Create a function that takes a 2’s complement integer (4 bits) as an argument and
    returns its equivalent decimal representation. 
    For example, convert_decimal(0b1011) should return 5 (decimal).
    */

    int saida_inteiro = 0;
    int pos;
    if(string_input[0] != '0' || string_input[1] != 'b') {
        return -1;
    }

    for(int i = 2; i < 6; i++) {
        if(string_input[i] == '1') {
            pos = (5 - i);
            saida_inteiro = saida_inteiro | (1 << pos);
        } 
    }

    return saida_inteiro;
}


int doubleInteger(int n) {
    /* 34. Write a function that uses the left bit shift operator (<<) to double an integer. */
    return n << 1;
}


int halfInteger(int n) {
    /* 34. Write a function that uses the left bit shift operator (<<) to double an integer. */
    
    /* 
    
    aqui temos uma divisao inteira, uma vez vez 
    que nao temos como retornar 0.5 em inteiro 
    
    */

    return n >> 1;
}

int main() {

    printf("%d\n", extract_msb(10)); /* expected 8*/
    printf("%d\n", extract_msb_verificar_nth(10, 4));  /* expected 1 */
    printf("%d\n", extract_lsb(10)); /* expected 0*/
    printf("%d\n", isolate_msb(10, 2));  /* expected 2 */
    printf("%d\n", isolate_lsb(10, 2));  /* expected 2 */
    printf("%d\n", invert_bits(5));  /* expected 10 */
    printf("%d\n", isolate_nibble_ms(240));  /* expected 15 */
    printf("%d\n", isPowerOfTwo(8));  /* expected 1 */
    printf("%d\n", count_bits_1(5));  /* expected 2 */
    printf("%d\n", is_odd(5));  /* expected 1 */
    printf("%d\n", is_odd(4));  /* expected 0 */
    printf("%d\n", is_even(5));  /* expected 0 */
    printf("%d\n", is_even(4));  /* expected 1 */
    
    printf("%d\n", convert_decimal("0b1011"));  /* expected 11 */

    printf("%d\n", doubleInteger(0));  /* expected 0 */
    printf("%d\n", doubleInteger(1));  /* expected 2 */
    printf("%d\n", doubleInteger(11));  /* expected 22 */
    printf("%d\n", doubleInteger(30));  /* expected 60 */

    printf("%d\n", halfInteger(0));  /* expected 0 */
    printf("%d\n", halfInteger(1));  /* expected 0 */
    printf("%d\n", halfInteger(11));  /* expected 5 */
    printf("%d\n", halfInteger(30));  /* expected 15 */
    return(0);

}