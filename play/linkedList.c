#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node* next;
} Node;

Node* pHead = NULL;

void insert(int id) {
    Node* ptr = pHead;
    while(ptr != NULL) {
        ptr = ptr->next; 
    }
    Node* p = (Node*) malloc(sizeof(Node));
    p->id = id;
    p->next = NULL;
    ptr = p;
    ptr = pHead;
    while(ptr->next != NULL) {
        ptr = ptr->next; 
    }
    ptr->next = p;
    if(pHead == NULL) pHead = ptr;
}

int main() {
    insert(88);
    insert(99);
}