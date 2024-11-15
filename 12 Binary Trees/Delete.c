/*******************************************************************

		delete.c

*******************************************************************/

#include "Trees.h"


void deleteNode(int id)
{
    /* this routine assumes that the node to be deleted does have
       a left and right subtree
    */
    NODE* target;
    NODE* parent;
    NODE* child;

    target = findNode(id, rootPtr);
    parent = findSuccessorNode(target);
    overwriteNode(target, parent);
    child = adjustPointers(parent);
    freeMemory(child);
}

/******************************************************************/

NODE* findNode(int id, NODE* current)
{
    /* this routine assumes that the node represented by id exists */

    if (current->id == id) return current;
    if (current->id >  id) return findNode(id, current->left);
    if (current->id <  id) return findNode(id, current->right);
    return NULL;
}

/******************************************************************/

NODE* findSuccessorNode(NODE* target)
{
    NODE* oldParent = target;
    NODE* parent;

    parent = goRight(oldParent);

    while(parent->left != NULL)
    {
        oldParent = parent;
        parent = goLeft(parent);
    }

    return oldParent;
}

/******************************************************************/

NODE* goRight(NODE* parent)
{
    return parent->right;
}

/******************************************************************/

NODE* goLeft(NODE* parent)
{
    return parent->left;
}

/******************************************************************/

void overwriteNode(NODE* target, NODE* parent)
{
    NODE* child = goLeft(parent);
    target->id = child->id;
}

/******************************************************************/

NODE* adjustPointers(NODE* parent)
{
    NODE* child = goLeft(parent);
    parent->left = child->right;
    return child;
}

/******************************************************************/

void freeMemory(NODE* theNode)
{
    free(theNode);
}


