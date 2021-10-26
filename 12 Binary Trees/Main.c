/*******************************************************************

		main.c

*******************************************************************/

#include "Trees.h"
NODE *rootPtr;


int nodes[] = {45,  12, 29, 6, 75, 34, 79, 77, 11, 2, 71, 66, 5, 20, 76, 86, 18, 78, 23, 31, 88, 9, 74, 67};

int main(void)
{
	system("clear");
    printf("create tree and add several nodes\n");
    displayListOfNodes();
    hitKeyToContinue();
    plantTree(nodes[0]);
    int size = sizeof(nodes)/sizeof(int);
    for(int i = 1; i < size; i++)
    {
        if(nodes[i] != 0) growTree(nodes[i]);
    }
	// search for next node (in order) with Left pointer free and use it to replace Node 12.
    printf("delete Node 12 (replace with the next node in-order)\n");
    deleteNode(12);
    hitKeyToContinue();
    displayTree(rootPtr);
    printf("print tree (in-order)\n");
    printTree();      
    hitKeyToContinue();
    printf("save tree (pre-order)\n"); 
    saveTree();      
    hitKeyToContinue();
    printf("destroy tree (post-order), freeing nodes ...\n");
    destroyTree();
    printf("\n");
    return 0;
}

 
