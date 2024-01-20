#Binary Search on matrix

def search_2d_array(matrix, target):
    mat_2D = [element for row in matrix for element in row]
    low, high = 0, len(mat_2D) - 1

    while low <= high:
        mid = (low + high) // 2
        mid_element = mat_2D[mid]

        if mid_element == target: return True
        low, high = (mid + 1, high) if mid_element < target else (low, mid - 1)

    return False

matrix = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]

target = 99

print(f"Element {target} {'is' if search_2d_array(matrix, target) else 'is not'} present in the 2D array.")
