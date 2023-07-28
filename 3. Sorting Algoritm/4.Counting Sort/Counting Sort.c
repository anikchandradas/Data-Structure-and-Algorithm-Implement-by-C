// Counting Sort

#include <stdio.h>

void count_sort(int A[], int n){

    int i, x, k;
    int count[11]; // index of count should be the maximum number of the array

    for(i = 0; i < 11; i++){
        count[i] = 0;
    }

    for(i = 0; i < n; i++){
        x = A[i];
        count[x] = count[x] + 1;
    }

    /*
    for(i = 0; i < 11; i++){
        printf("index : %d, value : %d\n", i, count[i]);
    }
    */

    for(i = 0; i < 11; i++){
        for(k = count[i]; k > 0; k--){
            printf("%d ", i);
        }
    }
}

int main(){
    int  n = 12;

    int A[] = {3, 4, 1, 6, 2, 4, 9, 7, 8, 4, 2, 1};

    count_sort(A, n);

    return 0;
}
