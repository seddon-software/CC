/*******************************************************************

		create.c

*******************************************************************/

#include "Trees.h"

void plantTree (int id)
{
    rootPtr = (NODE *) malloc (sizeof (NODE));

    rootPtr->id    = id;
    rootPtr->left  = NULL;
    rootPtr->right = NULL;

    displayTree(rootPtr);
}

void growTree(int id)
{
    NODE *parentPtr;

    parentPtr = searchTree (id, rootPtr);
    attachNode (id, parentPtr);

    displayTree(rootPtr);
}

