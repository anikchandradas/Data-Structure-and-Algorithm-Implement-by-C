#include <stdio.h>
#include <stdlib.h>

int left(int i) {
    return (2*i);
}

int right(int i) {
    return (2*i)+1;
}

int parent(int i) {
    return (i/2);
}

int is_max_heap(int H[], int heap_size) {
    int i, p;

    for(i = heap_size; i > 1; i--) {
        p = parent(i);
        //printf("i = %d, p = %d\tH[i] = %d, H[p] = %d\n", i, p, H[i], H[p]);

        if(H[p] < H[i]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int heap_size = 9;
    int H[] = {0, 19, 7, 17, 3, 5, 12, 10, 1, 2};
    int func;
    func = is_max_heap(H, heap_size);
    if(func == 1) {
        printf("Max Heap.\n");
    }
    else {
        printf("Not A Max Heap.\n");
    }
    return 0;
}
