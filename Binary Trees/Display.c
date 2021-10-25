/*******************************************************************

		Display.c

*******************************************************************/

#include "Trees.h"


int ids[32];

NODE* getId(int n, NODE* p)
{
	if(n == 1) return p;

	p = getId(n/2, p);
	if(n > 1)
	{
		if(n % 2 == 0)
		{
			if(p) p = p->left;
		}
		else
		{
			if(p) p = p->right;			
		}
	}
	return p;
}

void Print(const char* s, int repeats)
{
	for(int i = 0; i < repeats; i++)
	{
		printf("%s", s);
	}
	fflush(stdout);
}

void displayIds(int n)
{
	for(int i = n; i < 2*n; i++)
	{
		Print(" ", 32/n-1);
		if(ids[i] == 0)
		    printf("  ");
		else
			printf("%2i", ids[i]);
		Print(" ", 32/n-1);
	}
	printf("\n");
}

void displayTrunk(int n)
{
	for(int i = n; i < 2*n; i++)
	{
		Print(" ", 32/n-1);
		printf("%s", " |");
		Print(" ", 32/n-1);
	}
	printf("\n");
}

void displayBranches(int n)
{
	for(int i = n; i < 2*n; i++)
	{
		if(i == n) Print(" ", 16/n);
		Print("-", 32/n);
		Print(" ", 32/n);
	}
	printf("\n");
}
void displayLevel(int n)
{
	displayIds(n);
	displayTrunk(n);
	displayBranches(n);
}

void displayAllLevels()
{
	displayLevel(1);
	displayLevel(2);
	displayLevel(4);
	displayLevel(8);
	displayIds(16);
    printf("\n");
}

void hitKeyToContinue()
{
	getchar();
}

void displayListOfNodes()
{
	printf("Nodes: ");
	int size = sizeof(nodes)/sizeof(int);
	for(int i = 0; i < size; i++)
	{
		if(nodes[i] != 0) printf("%i ", nodes[i]);
	}
	printf("\nhit a key to continue");
}

void displayTree(NODE* p)
{
	system("clear");
	for(int i = 1; i < 32; i++)
	{
		NODE* ptr = getId(i, rootPtr);
		if(ptr) 
		    ids[i] = ptr->id;
		else
			ids[i] = 0;
	}
	displayAllLevels();
	displayListOfNodes();
	hitKeyToContinue();
}
