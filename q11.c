#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void find_neighbors_of_median(int arr[], int size) {
    // Sort the array
    quick_sort(arr, 0, size - 1);

    // Find the median index
    int median_index = size / 2;
    int median = arr[median_index];

    // Find the neighbors of the median
    int left_neighbor = (median_index > 0) ? arr[median_index - 1] : -1;
    int right_neighbor = (median_index < size - 1) ? arr[median_index + 1] : -1;

    printf("Left Neighbor: %d\n", left_neighbor);
    printf("Median: %d\n", median);
    printf("Right Neighbor: %d\n", right_neighbor);
}

int main() {
    int arr[] = {3, 1, 6, 2, 9, 8, 4, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_neighbors_of_median(arr, size);

    return 0;
}
