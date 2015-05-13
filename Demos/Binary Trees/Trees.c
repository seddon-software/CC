/*******************************************************************

		trees.c

*******************************************************************/

#include "Trees.h"

void printTree (void)
{
    printf ("\nPrinting tree ... \n");
    inOrder (rootPtr);
}

void destroyTree (void)
{
    printf ("\nDestroying tree ... \n");
    postOrder (rootPtr);
}

void saveTree (void)
{
    printf ("\nSaving tree ... \n");
    preOrder (rootPtr);
}

