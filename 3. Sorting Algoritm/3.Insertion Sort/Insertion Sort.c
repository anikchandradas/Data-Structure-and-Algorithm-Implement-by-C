// Insertion Sort Program

#include <stdio.h>

/*
    insertion_sort function receives parameters as follows:-
    A - array
    n - size of the array
*/

void insertion_sort(int A[], int n){
    int i, j, item;

    for(i = 1; i < n; i++){
        item = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > item) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = item;
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

    insertion_sort(A, n);

    printf("After Sorting: ");
    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }

    return 0;
}

