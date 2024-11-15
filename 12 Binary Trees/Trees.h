/*******************************************************************

		trees.h

*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    struct Node *left;
    struct Node *right;
};


typedef struct Node NODE;

void plantTree   (int id);
void growTree    (int id); 
NODE *searchTree (int id, NODE *ptr);
void attachNode  (int id, NODE *ptr);
void printTree   (void);
void destroyTree (void);
void saveTree    (void);

void inOrder     (NODE *ptr);
void preOrder    (NODE *ptr);
void postOrder   (NODE *ptr);

void  deleteNode(int id);
NODE* findNode(int id, NODE* current);
NODE* findSuccessorNode(NODE* target);
NODE* goRight(NODE* parent);
NODE* goLeft(NODE* parent);
void  overwriteNode(NODE* target, NODE* parent);
NODE* adjustPointers(NODE* parent);
void  freeMemory(NODE* theNode);

void hitKeyToContinue();
void displayTree(NODE* p);
void displayListOfNodes();
NODE* getId(int n, NODE* p);
void Print(const char* s, int repeats);
void displayLevel(int n);
void displayIds(int n);
void displayTrunk(int n);
void displayBranches(int n);
void displayAllLevels();

extern NODE *rootPtr;
extern int ids[32];
extern int nodes[32];