#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[16];
    int value;
} Pair;

typedef struct Node {
    Pair pair;
    struct Node* next;
} Node;

#define BINS 40

int getHash(const char* s) {

    int hash = 0;
    for(int i = 0; i < strlen(s); i++) {
        hash += s[i] * s[(i+3)%(strlen(s)-1)] * (i + 7); 
    }
    return hash % BINS;
}


void insert(Node* hashTable[], Pair pair) {
    Node* ptr = (Node*) malloc(sizeof(Node));
    strcpy(ptr->pair.key, pair.key);
    ptr->pair.value = pair.value;
    ptr->next = NULL;

    int hash = getHash(pair.key);
    Node* p = hashTable[hash]; 
    if(p == NULL) {
        hashTable[hash] = ptr;
    } else {
        while(p->next != NULL) p = p->next;
        p->next = ptr;
    }
}

void clearHashTable(Pair* hashTable[]) {
    for(int i = 0; i < BINS; i++) {
        hashTable[i] = NULL;
    }
}

void printHashTable(Node* hashTable[]) {
    for(int i = 0; i < BINS; i++) {
        Node* ptr = hashTable[i]; 
        while(ptr != NULL) {
            printf("bin=%i: key=%s, value=%i\n", i, ptr->pair.key, ptr->pair.value);
            ptr = ptr->next;
        }
    }
}
int main(void) {
    system("clear");
    Node* hashTable[BINS] = {NULL};
    Pair names[] = {{"John",  42000},
                    {"Jon",   21000},
                    {"Tom",   26000},
                    {"Ali",   40000},
                    {"Zoe",   45000},
                    {"Jane",  31000},
                    {"Sue",   36000},
                    {"Karda", 20000},
                    {"Bill",  47000}};
    int count = sizeof(names)/sizeof(Pair);
    for(int i = 0; i < count; i++) {
        insert(hashTable, names[i]);
    }
    printHashTable(hashTable);
}

