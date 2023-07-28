//A program for selection sort

#include <stdio.h>

/*
    slection_sort function receives parameters as follows:-
    A - array
    n - size of the array
*/

void slection_sort(int A[], int n) {
    int i, j, k, index_min, temp;

    for(i = 0; i < n-1; i++){
        index_min = i;

        for(j = i+1; j < n; j++){
            if(A[j] < A[index_min]){
                index_min = j;
            }
        }
        if(index_min != i){
            temp = A[i];
            A[i] = A[index_min];
            A[index_min] = temp;
        }
    }
}

int main(){
    int n = 5;
    int A[] = {10, 5, 2, 8, 7};

   printf("Before Sorting: ");
    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }
    printf("\n");

    slection_sort(A, n);

    printf("After Sorting: ");
    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }

    return 0;
}
