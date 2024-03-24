import string

# Function to preprocess the text (convert to lowercase and remove punctuation)
def preprocess_text(text):
    text = text.lower()
    translator = str.maketrans('', '', string.punctuation)
    text = text.translate(translator)
    return text.split()

# Function to calculate similarity score
def calculate_similarity(text1, text2):
    words1 = preprocess_text(text1)
    words2 = preprocess_text(text2)
    
    total_words1 = len(words1)
    total_matches = 0
    for word1 in words1:
        for word2 in words2:
            if word1 == word2:
                total_matches += 1
                break
    
    total_words2 = len(words2)

    return total_matches / max(total_words1, total_words2)

# Main function
def main():
    text1 = "This is a sample text for testing the plagiarism checker."
    text2 = "A plagiarism checker is used to detect similarities between texts."

    similarity_score = calculate_similarity(text1, text2)
    print("Similarity Score:", similarity_score)

if __name__ == "__main__":
    main()
