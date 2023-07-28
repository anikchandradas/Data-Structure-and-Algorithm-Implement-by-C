//Bubble Sort Program

#include <stdio.h>

/*
    bubble_sort function receives parameters as follows:-
    A - array
    n - size of the array
*/

void bubble_sort(int A[], int n) {
    int i, j, k, temp;

    for(i = 0; i < n; i++){
        for(j = 0; j < n-i-1; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int n = 5;
    int A[] = {10, 5, 2, 8, 7};

    printf("Before Bubble Sort: ");
    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }
    printf("\n\nAfter Bubble Sort: ");

    bubble_sort(A, n);

    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }

    return 0;
}

