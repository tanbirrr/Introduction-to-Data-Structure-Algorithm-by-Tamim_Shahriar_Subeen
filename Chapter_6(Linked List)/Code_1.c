#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data, Node* next) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

Node* prepend(Node* head, int data) {
    Node* newNode = create_node(data, head);
    return newNode;
}

Node* append(Node* head, int data) {
    if (head == NULL) {
        return create_node(data, NULL);
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = create_node(data, NULL);
    return head;
}

void print_linked_list(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Node* n1;
    Node* head;
    n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);
    head = prepend(head, 20);
    print_linked_list(head);
    head = append(head, 30);
    print_linked_list(head);

    return 0;
}
