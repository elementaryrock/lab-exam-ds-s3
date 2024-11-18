#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *leftChild;
    int value;
    struct Node *rightChild;
};

void insert(struct Node *currentNode) {
    int leftValue, rightValue;
    struct Node *leftNode = NULL, *rightNode = NULL;

    printf("Enter left child of %d (0 for no child): ", currentNode->value);
    scanf("%d", &leftValue);
    printf("Enter right child of %d (0 for no child): ", currentNode->value);
    scanf("%d", &rightValue);

    if (leftValue == 0) {
        currentNode->leftChild = NULL;
    } else {
        leftNode = malloc(sizeof(struct Node));
        leftNode->value = leftValue;
        currentNode->leftChild = leftNode;
        insert(leftNode);
    }

    if (rightValue == 0) {
        currentNode->rightChild = NULL;
    } else {
        rightNode = malloc(sizeof(struct Node));
        rightNode->value = rightValue;
        currentNode->rightChild = rightNode;
        insert(rightNode);
    }
}

void preorderTraversal(struct Node *currentNode) {
    if (currentNode != NULL) {
        printf("%d ", currentNode->value);
        preorderTraversal(currentNode->leftChild);
        preorderTraversal(currentNode->rightChild);
    }
}

void inorderTraversal(struct Node *currentNode) {
    if (currentNode != NULL) {
        inorderTraversal(currentNode->leftChild);
        printf("%d ", currentNode->value);
        inorderTraversal(currentNode->rightChild);
    }
}

void postorderTraversal(struct Node *currentNode) {
    if (currentNode != NULL) {
        postorderTraversal(currentNode->leftChild);
        postorderTraversal(currentNode->rightChild);
        printf("%d ", currentNode->value);
    }
}

int main() {
    struct Node *root = NULL, *tempNode = NULL;

    printf("Enter root node value: ");
    tempNode = malloc(sizeof(struct Node));
    scanf("%d", &tempNode->value);
    root = tempNode;

    insert(root);

    // Print all traversals
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}