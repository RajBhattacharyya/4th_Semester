def find_bitonic_point(arr):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = low + (high) // 2
        if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
            return mid
        elif arr[mid] > arr[mid - 1]:
            low = mid + 1
        else:
            high = mid - 1

    return -1 

arr = [1,3,5,7,9,12, 8, 6, 4,2,0]
bitonic_point = find_bitonic_point(arr)

if bitonic_point != -1:
    print(f"Bitonic point is at index {bitonic_point} with value {arr[bitonic_point]}")
else:
    print("Bitonic point not found")
