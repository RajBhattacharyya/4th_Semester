#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to preprocess the text (convert to lowercase and remove punctuation)
void preprocess_text(char *text) {
    int i, j = 0;
    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            text[j++] = tolower(text[i]);
        } else if (isspace(text[i])) {
            text[j++] = ' ';
        }
    }
    text[j] = '\0';
}

// Function to calculate similarity score
double calculate_similarity(char *text1, char *text2) {
    preprocess_text(text1);
    preprocess_text(text2);
    
    char *word1 = strtok(text1, " ");
    int total_words1 = 0, total_matches = 0;
    while (word1 != NULL) {
        total_words1++;
        char *word2 = strtok(text2, " ");
        while (word2 != NULL) {
            if (strcmp(word1, word2) == 0) {
                total_matches++;
                break;
            }
            word2 = strtok(NULL, " ");
        }
        word1 = strtok(NULL, " ");
    }

    int total_words2 = 0;
    char *word = strtok(text2, " ");
    while (word != NULL) {
        total_words2++;
        word = strtok(NULL, " ");
    }

    return (double) total_matches / (total_words1 > total_words2 ? total_words1 : total_words2);
}

int main() {
    char text1[] = "This is a sample text for testing the plagiarism checker.";
    char text2[] = "A plagiarism checker is used to detect similarities between texts.";

    double similarity_score = calculate_similarity(text1, text2);
    printf("Similarity Score: %.2f\n", similarity_score);

    return 0;
}
