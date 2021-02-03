/*******************************************************************

		main.c

*******************************************************************/

#include "Trees.h"
NODE *rootPtr;




int main(void)
{
    plantTree(45);
    displayTree(rootPtr);
    growTree (12);
    displayTree(rootPtr);
    growTree (29);
    displayTree(rootPtr);
    growTree ( 6);
    displayTree(rootPtr);
    growTree (34);
    displayTree(rootPtr);
    growTree (79);
    displayTree(rootPtr);
    growTree (71);
    displayTree(rootPtr);
    growTree (66);
    displayTree(rootPtr);
    growTree (20);
    displayTree(rootPtr);
    growTree (18);
    displayTree(rootPtr);
    growTree (23);
    displayTree(rootPtr);
    growTree (31);
    displayTree(rootPtr);
	// search for next node (in order) with Left pointer free and use it to replace Node 12.
    deleteNode(12);
    displayTree(rootPtr);
    printTree   ();      getchar();
    saveTree    ();      getchar();
    destroyTree ();
    return 0;
}

 
