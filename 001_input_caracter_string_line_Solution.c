/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/


#include <stdio.h>
#include <string.h>


int main() 
{
    
    char caracter;
    char s[100];
    char sen[100];
    
    scanf("%c", &caracter);
    scanf("%s", s); /*  it accepts string only until it finds the first space */
    scanf(" %[^\n]%*c", sen); /* stands for taking input until a newline isn't encountered */
     
    printf("%c\n", caracter);
    printf("%s\n", s);
    printf("%s\n", sen); 
    
    return 0;
}

