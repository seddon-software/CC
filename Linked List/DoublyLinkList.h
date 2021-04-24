/*******************************************************************

		LinkedList.h

*******************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;
extern NODE head;
extern NODE tail;
