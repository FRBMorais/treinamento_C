/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    char numberNames[][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

    for(int i = a; i <= b; i++) {
        if(i <= 9) {
            printf("%s\n", numberNames[i - 1]);
        } else if(i & 1){
            printf("odd\n");
        } else {
            printf("even\n");
        }
    }

    return 0;
}

