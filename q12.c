#include <stdio.h>
#include <limits.h>

// Function to find the minimum cost of multiplying the chain of matrices
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    // Cost is 0 when multiplying one matrix
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

// Function to print the optimal parenthesizing expression
void printOptimalParenthesis(int i, int j, int n, int *bracket) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    printOptimalParenthesis(i, *((bracket + i * n) + j), n, bracket);
    printOptimalParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket);
    printf(")");
}

// Main function
int main() {
    int p[] = {10, 20, 30, 40, 30}; // Matrix dimensions: p[i-1] x p[i]
    int n = sizeof(p) / sizeof(p[0]);
    int minCost;

    minCost = matrixChainOrder(p, n);
    printf("Minimum cost of multiplication is %d\n", minCost);

    // For printing the optimal parenthesizing expression
    int bracket[n][n];
    printf("Optimal Parenthesizing Expression: ");
    printOptimalParenthesis(1, n - 1, n, (int *)bracket);
    printf("\n");

    return 0;
}
