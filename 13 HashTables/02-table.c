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

#define FORMAT(p, n, f) #p #n #f
#define BINS 30
#define DISPLAY_BINS 16

void display(Node* hashTable[]) {
    system("clear");
    const char* format = FORMAT(%, 10, s);

	for(int i = 0; i < DISPLAY_BINS; i++)
    {
        Node* ptr = hashTable[i];
        if(ptr)
    	    printf(FORMAT(%, 10, i), i);
        else
    	    printf(format, " ");
    }
    printf("\n");
	for(int i = 0; i < DISPLAY_BINS; i++)
    {
        Node* ptr = hashTable[i];
        if(ptr)
    	    printf(format, "|");
        else
    	    printf(format, " ");
    }
    printf("\n");
	for(int i = 0; i < DISPLAY_BINS; i++)
    {
        Node* ptr = hashTable[i];
        if(ptr)
    	    printf(format, "|");
        else
    	    printf(format, " ");
    }
    printf("\n");
	for(int i = 0; i < DISPLAY_BINS; i++)
    {
        Node* ptr = hashTable[i];
        if(ptr)
    	    printf(format, "~");
        else
    	    printf(format, " ");
    }
    printf("\n");
	for(int i = 0; i < DISPLAY_BINS; i++)
    {
        Node* ptr = hashTable[i];
        if(ptr)
        {
            printf(FORMAT(%, 7, s) ",", ptr->pair.key);
    	    printf(FORMAT(%, 2, i) "K", ptr->pair.value/1000);
        }
        else
        {
            printf(format, " ");
        }
    }
	printf("\n");	
}


int getHash(const char* s) {

    int hash = 0;
    for(int i = 0; i < strlen(s); i++) {
        hash += s[i] * s[i] * (i + 7); 
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
        display(hashTable);
    }
    printHashTable(hashTable);
}

