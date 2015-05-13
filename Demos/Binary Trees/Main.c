/*******************************************************************

		main.c

*******************************************************************/

#include "Trees.h"

NODE *rootPtr;

int main(void)
{
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
	 growTree (19);
	 growTree (23);

	 deleteNode(12);

	 printTree   ();      getchar();
	 saveTree    ();      getchar();
	 destroyTree ();
	 return 0;
}

 
