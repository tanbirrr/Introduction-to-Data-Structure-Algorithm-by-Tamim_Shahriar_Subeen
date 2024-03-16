#include <stdio.h>

void max_heapify(int heap[], int heap_size, int index);

void print_heap(int heap[], int heap_size) {
    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

int main() {
    int heap_size = 9;
    int heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2}; 
    print_heap(heap, heap_size);
    max_heapify(heap, heap_size, 3); 
    print_heap(heap, heap_size);

    return 0;
}

void max_heapify(int heap[], int heap_size, int index) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int largest = index;

    if (left <= heap_size && heap[left] > heap[index]) {
        largest = left;
    }

    if (right <= heap_size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        // Swap heap[index] and heap[largest]
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // Recursively heapify the affected subtree
        max_heapify(heap, heap_size, largest);
    }
}
