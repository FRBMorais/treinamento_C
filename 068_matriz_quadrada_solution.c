/* 
    Programmer: Felipe Rosa 
    Date: 13/05
*/

void printMatrix(int);
int maior(int, int);
int distance(int, int, int);


int main() {

    int n;

    while( scanf("%d", &n) == 1 && n != 0 ) {
        printMatrix(n);
        printf("\n");
    }

    return 0;
}


void printMatrix(int n){

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(j != n - 1) {
                printf("%3d ", distance(i, j, n));
            } else {
                printf("%3d\n", distance(i, j, n));
            }
        }
    }
}   

/* retorna o maior entre dois numeros */
int menor(int a, int b) {
    if(a <= b) {
        return a;
    } 
    return b;
}

/* retorna a distancia ate a borda */
int distance(int x, int y, int n) {
    
    int x_1 = n - x;
    int x_2 = x + 1;
    int x_res = menor(x_1, x_2);
    int y_1 = n - y;
    int y_2 = y + 1;
    int y_res = menor(y_1, y_2);
    return menor(x_res, y_res);
}