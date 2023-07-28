// C program for Priority Queue

#include <stdio.h>

 int heap_size = 9;

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

int parent(int i) {
    return i/2;
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

int extract_max(int heap[], int heap_size) {

    int max_item = heap[1];
    heap[1] = heap[heap_size];
    heap_size -= 1;
    //printf("in extract function: %d\n", heap_size);

    build_max_heap(heap, heap_size);

    return max_item;
}

int insert_node(int heap[], int heap_size, int node) {

    int i, p, t;
    heap_size += 1;
    heap[heap_size] = node;
    //i = heap_size;

    while(i > 1 && heap[i] > heap[parent(i)]) {
        p = parent(i);

        t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

        i = p;
    }
    return heap_size;
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

    int  heap[50] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};

    print_heap(heap, heap_size);
    extract_max(heap, heap_size);

    print_heap(heap, heap_size);
    extract_max(heap, heap_size);

    print_heap(heap, heap_size);

    //insert_node(int heap[], int heap_size, int node)

    //insert_node(heap, heap_size, 33);

    //print_heap(heap, heap_size);

    return 0;
}
//program not completed, need to modify
