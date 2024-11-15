/*******************************************************************

		search.c

*******************************************************************/

#include "Trees.h"


NODE *searchTree (int id, NODE *ptr)
{                 
    if (id > ptr->id && ptr->right != NULL)
        ptr = searchTree (id, ptr->right);
       
    if (id < ptr->id && ptr->left  != NULL)
        ptr = searchTree (id, ptr->left);
    
    return ptr;
}

void attachNode (int  id, NODE *parentPtr)
{
    NODE *childPtr;

    childPtr = (NODE *) malloc (sizeof (NODE));

    childPtr->id    = id;
    childPtr->left  = NULL;
    childPtr->right = NULL;

    if (id > parentPtr->id) parentPtr->right = childPtr;
    if (id < parentPtr->id) parentPtr->left  = childPtr;
}

