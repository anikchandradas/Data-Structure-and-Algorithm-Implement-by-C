// A program for Binary Search Algorithm

#include <stdio.h>

/*
Binary search function receives parameters as follows:-
    A - sorted array (where values are sorted in Ascending to Descending order)
    n - length of the array
    x - search item
*/

int binary_search(int A[], int n, int x){
    int left, right, mid;
    left = 0;
    right = n - 1;

    while(left <= right) {
        mid = (left + right) / 2;

        if(A[mid] == x){
            return mid; // item found
        }

        if(A[mid] < x){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // item not found
}


int main() {
    int n=10, x = 70, s;
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    s = binary_search(A, n, x);

    if(s == -1){
        printf("Item not found.\n");
    }
    else{
        printf("Item found at index : %d\n", s);
    }
    return 0;
 }

