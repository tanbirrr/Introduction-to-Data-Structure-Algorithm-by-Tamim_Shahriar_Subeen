//complexity O(n)
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new Node
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to add a left child to a Node
void add_left_child(Node *parent, Node *child) {
    parent->left = child;
}

// Function to add a right child to a Node
void add_right_child(Node *parent, Node *child) {
    parent->right = child;
}

Node *create_tree() {
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_node(8);
    add_right_child(nine, eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);

    return two; // Return the root of the tree
}

int main() {
    Node *root = create_tree();
    printf("%d\n", root->data);
    


    return 0;
}
