#include <stdio.h>

#define N 3
#define M 4
int search2DArray(int matrix[][M], int target, int rows, int cols) {
    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int midElement = matrix[mid / cols][mid % cols];

        if (midElement == target) return 1; // Element found
        (midElement < target) ? (low = mid + 1) : (high = mid - 1);
    }

    return 0;
}

int main() {
    int matrix[N][M] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 3;

    printf("Element %d %s present in the 2D array.\n", target, 
           search2DArray(matrix, target, N, M) ? "is" : "is not");

    return 0;
}
