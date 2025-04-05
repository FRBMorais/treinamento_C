/* 
    Programmer: Felipe Rosa 
    Date: 05/04
*/


#include <stdio.h>


int main()
{   
    int int_1, 
        int_2;
    float float_1, 
          float_2;

	scanf("%d %d %f %f", &int_1, &int_2, &float_1, &float_2);

    printf("%d %d\n%.1f %.1f\n", int_1 + int_2, int_1 - int_2,
                                 float_1 + float_2, float_1 - float_2);
    
    return 0;
}