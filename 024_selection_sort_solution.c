#include <stdio.h>


void selection_sort(int array[], int length) {

    int inter_ord_nord = 0;
    int min;
    int indice_min;
    int temp;
    for(int i = 0; i < length - 1; i++) {
        min = array[i];
        indice_min = i;
        for(int j = i + 1; j < length; j++) {
            if(array[j] < min) {
                min = array[j];
                indice_min = j;
            }
        }
        
        temp = array[i];
        array[i] = array[indice_min];
        array[indice_min] = temp;
    }
}



int main() {

    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
}
    int length_array = n;

    selection_sort(array, length_array);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    return(0);
}