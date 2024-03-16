#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for key-value pairs
struct KeyValuePair {
    char *key;
    int value;
    struct KeyValuePair *next;
};

// Structure for hash table
struct HashTable {
    struct KeyValuePair *table[TABLE_SIZE];
};

// Hash function
int hash(char *key) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue += key[i];
    }
    return hashValue % TABLE_SIZE;
}

// Create a new key-value pair
struct KeyValuePair* createKeyValuePair(char *key, int value) {
    struct KeyValuePair *newPair = (struct KeyValuePair*) malloc(sizeof(struct KeyValuePair));
    if (newPair != NULL) {
        newPair->key = strdup(key);
        newPair->value = value;
        newPair->next = NULL;
    }
    return newPair;
}

// Insert key-value pair into the hash table
void insert(struct HashTable *hashTable, char *key, int value) {
    int index = hash(key);
    struct KeyValuePair *newPair = createKeyValuePair(key, value);
    if (newPair == NULL) {
        fprintf(stderr, "Failed to allocate memory for key-value pair.\n");
        return;
    }
    // Collision handling: chaining
    if (hashTable->table[index] != NULL) {
        struct KeyValuePair *temp = hashTable->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPair;
    } else {
        hashTable->table[index] = newPair;
    }
}

// Search for a key in the hash table
int search(struct HashTable *hashTable, char *key) {
    int index = hash(key);
    struct KeyValuePair *temp = hashTable->table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

int main() {
    struct HashTable hashTable;
    // Initialize all pointers to NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable.table[i] = NULL;
    }

    // Inserting some key-value pairs
    insert(&hashTable, "apple", 10);
    insert(&hashTable, "banana", 20);
    insert(&hashTable, "cherry", 30);

    // Searching for values
    printf("Value for key 'apple': %d\n", search(&hashTable, "apple"));
    printf("Value for key 'banana': %d\n", search(&hashTable, "banana"));
    printf("Value for key 'cherry': %d\n", search(&hashTable, "cherry"));
    printf("Value for key 'grape': %d\n", search(&hashTable, "grape")); // This key does not exist

    return 0;
}
