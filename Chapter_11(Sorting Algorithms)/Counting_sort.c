#include <stdio.h>

void countingSort(int arr[], int n, int max) {
    int count[max + 1], output[n];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Store count of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modify count to store actual position
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int A[] = {3, 4, 1, 6, 2, 4, 9, 7, 8, 4, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int max = 9; // Assuming the maximum value in the array

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    countingSort(A, n, max);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
