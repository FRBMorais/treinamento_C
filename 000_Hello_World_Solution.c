/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/


#include <stdio.h>


int main() 
{
	
    char s[100];
    scanf("%[^\n]%*c", &s);
  	
    printf("Hello, World!\n");
    printf("%s", s);   
    return 0;
}
