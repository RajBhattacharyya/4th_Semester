def partition(arr, low, high):
    pivot = arr[high]  # Choosing the last element as the pivot
    i = low - 1  # Index of smaller element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def find_median(arr):
    arr.sort()
    median_index = len(arr) // 2
    median = arr[median_index]
    return median, median_index

def find_neighbors_of_median(arr):
    median, median_index = find_median(arr)
    partition(arr, 0, len(arr) - 1)
    left_neighbor = arr[median_index - 1] if median_index > 0 else None
    right_neighbor = arr[median_index + 1] if median_index < len(arr) - 1 else None
    return left_neighbor, median, right_neighbor

# Example usage:
array = [3, 1, 6, 2, 9, 8, 4, 5, 7]
left_neighbor, median, right_neighbor = find_neighbors_of_median(array)
print("Left Neighbor:", left_neighbor)
print("Median:", median)
print("Right Neighbor:", right_neighbor)
