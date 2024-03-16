#include<stdio.h>
#include<string.h>

// Function to merge two subarrays
void merge(int a[], int left, int mid, int right) {
    int i;
    int index_a, index_l, index_r;
    int size_left, size_right;
    size_left = mid - left + 1;
    size_right = right - mid;

    int L[size_left], R[size_right];
    for (i = 0; i < size_left; i++) {
        L[i] = a[left + i];
    }
    for (i = 0; i < size_right; i++) {
        R[i] = a[mid + 1 + i];
    }
    index_l = 0;
    index_r = 0;
    for (index_a = left; index_l < size_left && index_r < size_right; index_a++) {
        if (L[index_l] < R[index_r]) {
            a[index_a] = L[index_l];
            index_l += 1;
        }
        else {
            a[index_a] = R[index_r];
            index_r += 1;
        }
    }
    while (index_l < size_left) {
        a[index_a] = L[index_l];
        index_l += 1;
        index_a += 1;
    }
    while (index_r < size_right) {
        a[index_a] = R[index_r];
        index_r += 1;
        index_a += 1;
    }
}

// Merge sort function
void merge_sort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int i, n = 8;
    int A[] = {1, 5, 6, 3, 5, 8, 7, 2};
    merge_sort(A, 0, n - 1); // Corrected the range from 0 to n-1
    for (i = 0; i < n; i++) { // Changed the condition to i < n
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
