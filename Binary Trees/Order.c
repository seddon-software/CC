/*******************************************************************

		order.c

*******************************************************************/

#include "Trees.h"

void inOrder (NODE *ptr)
{
    if (ptr == NULL) return;
    printf("");
    fflush(stdout);
    inOrder (ptr->left);
    printf ("%3i \n", ptr->id);
    printf("");
    fflush(stdout);
    inOrder (ptr->right);
}

void preOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    printf ("%3i \n", ptr->id);
    printf("");
    fflush(stdout);
    preOrder (ptr->left);
    printf("");
    fflush(stdout);
    preOrder (ptr->right);
    printf("");
    fflush(stdout);

}

void postOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    postOrder (ptr->left);
    postOrder (ptr->right);
    printf ("freeing node %3i \n", ptr->id);
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

