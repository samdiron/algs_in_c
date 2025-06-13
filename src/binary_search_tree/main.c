#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


int main() {
    // Initialize the root node
    BSTNode_t* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 45);
    insertNode(root, 47);
    insertNode(root, 70);
    insertNode(root, 80);
    insertNode(root, 90);
    insertNode(root, 60);

    // Search for a node with key 60
    if (searchNode(root, 60) != NULL) {
        printf("60 found");
    }
    else {
        printf("60 not found");
    }

    printf("\n");

    // Perform post-order traversal
    postOreder(root);
    printf("\n");

    // Perform pre-order traversal
    preOrder(root);
    printf("\n");

    // Perform in-order traversal
    inOrder(root);
    printf("\n");

    BSTNode_t* temp = deleteNode(root, 40);
    printf("After Delete: \n");
    inOrder(root);

    BSTNode_t* min = findMIN(root);
    printf("min: %d \n", min->val);
    // Now we free allocated memory 
    freeNode(root);
    return 0;

};
