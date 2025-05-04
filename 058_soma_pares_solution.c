/* 
    Programmer: Felipe Rosa 
    Date: 03/04
*/


int main() {

    int init, output;

    scanf("%d", &init);

    if(init == 0) {
        return 0;
    }

    do {
        if (init & 1) {
            init++;
        }
        output = (init + init + 2 * (5 - 1)) * ((float)5 / 2) ;
        printf("%d\n", output);
        scanf("%d", &init);
    
    } while (init != 0);
}