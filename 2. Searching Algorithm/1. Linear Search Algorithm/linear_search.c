//A program for linear search algorithm.

#include <stdio.h>

/*
linear search function receives parameters as follows:-
    A - array
    n - length of the array
    x - search item
*/

 int linear_search(int A[], int n, int x) {
    int i;

    for(i = 0; i < n; i++){
        if(A[i] == x){
            return i; // item found in the array at index i
        }
    }

    i=-1; //item not found in the array
    return i;
 }

 int main() {
    int n=10, x = 70, s;
    int A[] = {40, 10, 30, 70, 20, 50, 80, 60, 100, 90};

    s = linear_search(A, n, x);

    if(s == -1){
        printf("Item not found.\n");
    }
    else{
        printf("Item found at index : %d\n", s);
    }
    return 0;
 }
