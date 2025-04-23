/*
FONTE: PES04 - UFPE - EMBRAER
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
5. Write a function that takes an integer (4 bits) 
and a boolean value (true or false) as
arguments and returns the original number 
with the MSB set according to the boolean value.
*/

int flipt_msb(int n, bool flag) {
    if(flag) {
        n  ^= (1 << 3);
    }
    
    return n;
}


/*
6. Create a function that takes an integer (4 bits) 
and a boolean value (true or false)
as arguments and returns the original 
number with the LSB set according to the boolean
value.
*/

int flipt_lsb(int n, bool flag) {
    if(flag) {
        n ^= 1;
    }
    return n;
}


/*
16. Write a function that takes an integer (32 bits) 
and returns the total sum of 1 bits in all
the bytes.
*/

int count_1_in_int32(int n) {

    int count = 0;

    while(n != 0) {
        n = n & (n-1);
        count++;
    }

    return count;
}


/*
19. Write functions to turn 
a specific bit on and off in an integer.
*/

int turn_nth(int n, int position, int flag) {
    
    if (flag) {
        n = n | (1 << position);
    } else {
        n = n & ~(1 << position);
    }

    return n;
}


/*
20.1. Write functions to extract and insert 
bit subfields of an integer.
EXTRACT */

int bit_subfilds_extract() {
    
}


/*
20.2. Write functions to extract and insert 
bit subfields of an integer.
INSERT */

int bit_subfilds_insert() {
    
}


/*
26. Write a function that uses the AND operator 
and a binary mask to extract and return
the 4 most significant bits of an integer. */

int most_significative_4() {
    
}


/*
28. Write a function that uses the AND operator 
and a binary mask to check whether the
most significant bit of an integer is set 
and returns true if it is or false otherwise. */

int most_significative_4() {
    
}


int main() {

    /* question 5 */
    int n_1 = 10;  /* 1010 */
    printf("Original number -> %d\n", n_1);                // Expected: Original number -> 10
    printf("flip_nth -> %d\n", flipt_msb(n_1, true));     // Expected: flip_nth -> 2
    printf("flip_nth -> %d\n", flipt_msb(n_1, false));    // Expected: flip_nth -> 10


    /* question 6 */
    int n_2 = 7;   /* 0111 */
    printf("Original number -> %d\n", n_2);               // Expected: Original number -> 7
    printf("flip_nth -> %d\n", flipt_lsb(n_2, true));     // Expected: flip_nth -> 6
    printf("flip_nth -> %d\n", flipt_lsb(n_2, false));    // Expected: flip_nth -> 7


    /* question 16 */
    int n_3 = 0;   /* 00000000000000000000000000000000 */
    printf("Input -> %d, count_1_in_int32 -> %d\n",
           n_3, count_1_in_int32(n_3));                  // Expected: Input -> 0, count_1_in_int32 -> 0

    int n_4 = 7;   /* 00000000000000000000000000000111 */
    printf("Input -> %d, count_1_in_int32 -> %d\n",
           n_4, count_1_in_int32(n_4));                  // Expected: Input -> 7, count_1_in_int32 -> 3

    int n_5 = 1023;/* 00000000000000000000001111111111 */
    printf("Input -> %d, count_1_in_int32 -> %d\n",
           n_5, count_1_in_int32(n_5));                  // Expected: Input -> 1023, count_1_in_int32 -> 10

    int n_6 = -1;  /* 11111111111111111111111111111111 */
    printf("Input -> %d, count_1_in_int32 -> %d\n",
           n_6, count_1_in_int32(n_6));                  // Expected: Input -> -1, count_1_in_int32 -> 32
    

    /* question 19 */

    printf("%d turn on 2 -> %d\n", n_1, turn_nth(n_1, 2, 1));  /* expected - 14 */
    printf("%d turn off 1 -> %d\n", n_2, turn_nth(n_2, 1, 0));  /* expected - 5 */
    
    return 0;
}