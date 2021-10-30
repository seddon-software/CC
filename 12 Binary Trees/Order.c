/*******************************************************************

		order.c

*******************************************************************/

#include "Trees.h"

void inOrder (NODE *ptr)
{
    if (ptr == NULL) return;
    fflush(stdout);
    inOrder (ptr->left);
    printf ("%3i .", ptr->id);
    fflush(stdout);
    inOrder (ptr->right);
}

void preOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    printf ("%3i .", ptr->id);
    fflush(stdout);
    preOrder (ptr->left);
    fflush(stdout);
    preOrder (ptr->right);
    fflush(stdout);

}

void postOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    postOrder (ptr->left);
    postOrder (ptr->right);
    printf ("%3i .", ptr->id);
    free (ptr);
}

void printTree()
{
    inOrder(rootPtr);
}
void saveTree()
{
    preOrder(rootPtr);
}
void destroyTree()
{
    postOrder(rootPtr);
}

