#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node with a given key into BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

// Function to perform inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for a key in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    int keys[] = {5, 3, 8, 2, 4, 7, 10};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into BST
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    // Search for key 7
    struct Node* node = search(root, 7);
    printf("Search path: ");
    while (node != NULL) {
        printf("%d ", node->data);
        if (node->data < 7)
            node = node->right;
        else if (node->data > 7)
            node = node->left;
        else
            break;
    }
    printf("\n");

    return 0;
}
