#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal of the BST
void in_order(Node* root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

// Function to search for a node in the BST
Node* bst_search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return bst_search(root->left, key);
    }

    return bst_search(root->right, key);
}

// Function to find the minimum value node in a subtree
Node* find_min_node(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node* bst_delete(Node* root, Node* node) {
    if (root == NULL) {
        return root;
    }

    if (node->data < root->data) {
        root->left = bst_delete(root->left, node);
    } else if (node->data > root->data) {
        root->right = bst_delete(root->right, node);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, temp);
    }

    return root;
}

int main() {
    Node *root = NULL;
    // Inserting nodes into the BST
    root = insert_node(root, 5);
    insert_node(root, 1);
    insert_node(root, 10);

    Node *node;

    printf("BST:\n");
    in_order(root);
    printf("\n");

    node = bst_search(root, 1);
    if (node != NULL) {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    } else {
        printf("Node not found!\n");
    }

    node = bst_search(root, 5);
    if (node != NULL) {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    } else {
        printf("Node not found!\n");
    }

    node = bst_search(root, 10);
    if (node != NULL) {
        printf("Will delete %d\n", node->data);
        root = bst_delete(root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    } else {
        printf("Node not found!\n");
    }

    return 0;
}
