/*******************************************************************

		LinkedList.h

*******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[32];
    int salary;
} DATA;

typedef struct Node
{
    DATA* pData;
    struct Node *next;
} NODE;

extern NODE head;
