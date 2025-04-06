/* 
    Programmer: Felipe Rosa 
    Date: 06/04
*/

int min_array(int array[], int len_array) {
    
    int minimo = array[0];
    
    for (int i = 0; i < len_array; i++) {
        if (array[i] < minimo) {
            minimo = array[i];
        }
    }

    return minimo;
}


int main() {
   int n;

   scanf("%d", &n);  /* tamanho esperado da entrada*/
   int *arr = (int*) malloc(n*sizeof(int)); 

   for(int i = 0; i < n; i++) { /* le o input*/
       scanf("%d", &arr[i]);
   }
   
   if (n == 0) {
       printf("Array vazio. Nenhum valor fornecido.");
   } else {
       printf("Menor valor: %d\n", min_array(arr, n));
   }
   
   free(arr);

   return(0);
}


