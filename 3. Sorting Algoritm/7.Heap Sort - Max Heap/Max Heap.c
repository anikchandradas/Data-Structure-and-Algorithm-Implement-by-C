//A program for Max Heap

#include <stdio.h>

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

int parent(int i) {
    return i/2;
}

int is_max_heap(int H[], int heap_size) {
    int i, p;

    for(i = heap_size; i > 1; i--) {
        p = parent(i);
        if(H[p] < H[i]) {
            return 0;
        }
    }
    return 1;
}

void max_heapify(int heap[], int heap_size, int i) {
    int l, r, t, largest;
    l = left(i);
    r = right(i);

    if(l <= heap_size && heap[l] > heap[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest]) {
        largest = r;
    }

    if(largest != i) {
        t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        max_heapify(heap, heap_size, largest);
    }
}

void build_max_heap(int heap[], int heap_size) {
    int i;
    for(i = heap_size/2; i >= 1; i--) {
        max_heapify(heap, heap_size, i);
    }
}

void print_heap(int heap[], int heap_size) {
    int i;
    for(i = 1; i <= heap_size; i++) {
        printf("%d  ", heap[i]);
    }
    printf("\n\n");
}

int main()
{
    int flag, heap_size = 9;
    int  heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};

    flag = is_max_heap(heap, heap_size);
    if(flag == 1) {
        printf("This is a max heap\n");
    }
    else{
        printf("Not a Max heap\n\n");
    }

    print_heap(heap, heap_size);

    build_max_heap(heap, heap_size);

    print_heap(heap, heap_size);

    flag = is_max_heap(heap, heap_size);
    if(flag == 1) {
        printf("This is a max heap\n");
    }
    else{
        printf("Not a Max heap\n");
    }

    return 0;
}
