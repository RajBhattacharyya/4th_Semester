def add_matrices(A, B):
    n = len(A)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]

def subtract_matrices(A, B):
    n = len(A)
    return [[A[i][j] - B[i][j] for j in range(n)] for i in range(n)]

def strassen(A, B):
    n = len(A)

    if n == 1:
        return [[A[0][0] * B[0][0]]]

    # Divide matrices into submatrices
    A11 = [[A[i][j] for j in range(n//2)] for i in range(n//2)]
    A12 = [[A[i][j] for j in range(n//2, n)] for i in range(n//2)]
    A21 = [[A[i][j] for j in range(n//2)] for i in range(n//2, n)]
    A22 = [[A[i][j] for j in range(n//2, n)] for i in range(n//2)]

    B11 = [[B[i][j] for j in range(n//2)] for i in range(n//2)]
    B12 = [[B[i][j] for j in range(n//2, n)] for i in range(n//2)]
    B21 = [[B[i][j] for j in range(n//2)] for i in range(n//2, n)]
    B22 = [[B[i][j] for j in range(n//2, n)] for i in range(n//2)]

    # Calculate M1 to M7
    M1 = strassen(add_matrices(A11, A22), add_matrices(B11, B22))
    M2 = strassen(add_matrices(A21, A22), B11)
    M3 = strassen(A11, subtract_matrices(B12, B22))
    M4 = strassen(A22, subtract_matrices(B21, B11))
    M5 = strassen(add_matrices(A11, A12), B22)
    M6 = strassen(subtract_matrices(A21, A11), add_matrices(B11, B12))
    M7 = strassen(subtract_matrices(A12, A22), add_matrices(B21, B22))

    # Calculate submatrices C11, C12, C21, C22
    C11 = add_matrices(subtract_matrices(add_matrices(M1, M4), M5), M7)
    C12 = add_matrices(M3, M5)
    C21 = add_matrices(M2, M4)
    C22 = add_matrices(subtract_matrices(add_matrices(M1, M3), M2), M6)

    # Combine submatrices into result matrix
    C = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n//2):
        for j in range(n//2):
            C[i][j] = C11[i][j]
            C[i][j + n//2] = C12[i][j]
            C[i + n//2][j] = C21[i][j]
            C[i + n//2][j + n//2] = C22[i][j]

    return C

# Example usage
A = [[1, 2, 3, 4],
     [5, 6, 7, 8],
     [9, 10, 11, 12],
     [13, 14, 15, 16]]

B = [[17, 18, 19, 20],
     [21, 22, 23, 24],
     [25, 26, 27, 28],
     [29, 30, 31, 32]]

result = strassen(A, B)
for row in result:
    print(row)
