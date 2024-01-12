#include <stdio.h>

void main() {
    int arr[10] = {1,3,4,5,6,7,9,10,12,13};
    int n;
    printf("Enter the sum: ");
    scanf("%d", &n);
    int i = 0;
    int j = (sizeof(arr)/sizeof(arr[0])) - 1;
    while (i<=j) {
        if(n>(arr[i] + arr[j]))
            i++;
        else if (n==(arr[i] + arr[j])) {
            printf("%d %d", arr[i], arr[j]);
            break;
        } else if (n<(arr[i] + arr[j]))
            j--;
    }
}