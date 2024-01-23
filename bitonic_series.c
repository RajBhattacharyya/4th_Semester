#include <stdio.h>

int findBitonicPoint(int arr[], int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,3,5,7,9,12, 8, 6, 4,2,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int bitonicPoint = findBitonicPoint(arr, 0, n - 1);

    if (bitonicPoint != -1) {
        printf("Bitonic point found at index %d and value is %d", bitonicPoint, arr[bitonicPoint]);
    } else {
        printf("Bitonic point not found\n");
    }

    return 0;
}
