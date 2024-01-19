// Binary Search in C

#include<stdio.h>
#include<stdlib.h>

int bin_search(int arr[], int left, int right, int target)
{
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(arr[mid] == target)
            return mid;
        
        else if(arr[mid] > target)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;

    }
    return -1;
}

int main(){
    int arr[10] = {3,6,9,12,15,18,21,24,27,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 6;
    int left = 0, right = size - 1;
    int res = bin_search(arr,left,right, target);
    printf("The target element is at %d", res);
    if(res != -1)
        printf("The target element is at index %d\n", res);
    else
        printf("The target element is not in the array\n");
}
