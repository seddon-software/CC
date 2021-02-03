/*******************************************************************

		main.c

*******************************************************************/

#include "Trees.h"
NODE *rootPtr;




int main(void)
{
    printf("create tree and add several nodes\n");
    hitKeyToContinue();
    plantTree(45);
    growTree (12);
    growTree (29);
    growTree ( 6);
    growTree (34);
    growTree (79);
    growTree (71);
    growTree (66);
    growTree (20);
    growTree (18);
    growTree (23);
    growTree (31);
	// search for next node (in order) with Left pointer free and use it to replace Node 12.
    printf("delete Node 12\n");
    deleteNode(12);
    hitKeyToContinue();
    displayTree(rootPtr);
    printf("print tree\n");
    printTree();      
    hitKeyToContinue();
    printf("save tree\n"); 
    saveTree();      
    hitKeyToContinue();
    printf("destroy tree\n"); 
    destroyTree();
    return 0;
}

 
