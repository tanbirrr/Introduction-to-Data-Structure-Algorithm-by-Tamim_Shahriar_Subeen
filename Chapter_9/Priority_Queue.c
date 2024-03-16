#include <stdio.h>

#define parent(i) ((i) / 2)

int insert_node(int heap[], int heap_size, int node);

void print_heap(int heap[], int heap_size) {
    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

int main() {
    int heap_size = 9;
    int heap[10] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};

    printf("Original heap:\n");
    print_heap(heap, heap_size);

    // Inserting a new node with value 20
    heap_size = insert_node(heap, heap_size, 20);

    printf("Heap after inserting 20:\n");
    print_heap(heap, heap_size);

    return 0;
}

int insert_node(int heap[], int heap_size, int node) {
    int i = heap_size + 1;
    heap_size += 1;
    heap[heap_size] = node;

    while (i > 1 && heap[i] > heap[parent(i)]) {
        int p = parent(i);
        // Swap heap[i] and heap[parent(i)]
        int temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;
        i = p;
    }

    return heap_size;
}
