/* 
    Programmer: Felipe Rosa 
    Date: 29/04
*/

int main() {

    int parameter = 0;
    
    int inter = 0;
    int gremio = 0;
    int empates = 0;

    int int_gols;
    int grem_gols;

    do {

        scanf("%d %d", &int_gols, &grem_gols);

        if(int_gols == grem_gols) {
            empates++;
        } else if(int_gols > grem_gols) {
            inter++;
        } else {
            gremio++;
        }

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &parameter);
        

    } while (parameter != 2);

    printf("%d grenais\n", inter + gremio + empates);
    printf("Inter:%d\n", inter);
    printf("Gremio:%d\n", gremio);
    printf("Empates:%d\n", empates);

    if(inter > gremio) {
        printf("Inter venceu mais\n");
    } else if(gremio > inter) {
        printf("Gremio venceu mais\n");
    }
        

    return 0;
}