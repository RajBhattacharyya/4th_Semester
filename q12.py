import sys

def matrixChainOrder(p):
    n = len(p)
    m = [[0]*n for _ in range(n)]
    bracket = [[0]*n for _ in range(n)]

    for L in range(2, n):
        for i in range(1, n-L+1):
            j = i + L - 1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    bracket[i][j] = k

    return m[1][n-1], bracket

def printOptimalParenthesis(i, j, bracket):
    if i == j:
        print("A" + str(i), end='')
        return
    print("(", end='')
    printOptimalParenthesis(i, bracket[i][j], bracket)
    printOptimalParenthesis(bracket[i][j] + 1, j, bracket)
    print(")", end='')

# Main function
if __name__ == "__main__":
    p = [10, 20, 30, 40, 30]  # Matrix dimensions: p[i-1] x p[i]
    minCost, bracket = matrixChainOrder(p)
    print("Minimum cost of multiplication is", minCost)
    print("Optimal Parenthesizing Expression:", end=' ')
    printOptimalParenthesis(1, len(p) - 1, bracket)
    print()
