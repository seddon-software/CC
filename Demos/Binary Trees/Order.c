/*******************************************************************

		order.c

*******************************************************************/

#include "Trees.h"

void inOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    inOrder (ptr->left);
    printf ("%3i \n", ptr->id);
    inOrder (ptr->right);
}

void preOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    printf ("%3i \n", ptr->id);
    preOrder (ptr->left);
    preOrder (ptr->right);
}

void postOrder (NODE *ptr)
{
    if (ptr == NULL) return;
   
    postOrder (ptr->left);
    postOrder (ptr->right);
    printf ("freeing node %3i \n", ptr->id);
    free (ptr);
}
