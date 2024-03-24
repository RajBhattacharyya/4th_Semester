#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the prefix array for the pattern
void compute_prefix(char *pattern, int m, int *prefix) {
    int len = 0;
    prefix[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform pattern search using KMP algorithm
void search(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);
    
    int *prefix = (int *)malloc(sizeof(int) * m);
    compute_prefix(pattern, m, prefix);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = prefix[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }
    free(prefix);
}

int main() {
    char text[] = "AAABAACAADAAABAA";
    char pattern[] = "AAB";
    search(pattern, text);
    return 0;
}
