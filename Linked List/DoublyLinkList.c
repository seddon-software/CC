/*******************************************************************

		LinkList.c

*******************************************************************/

#include "DoublyLinkList.h"

NODE head;
NODE tail;

void setupList()
{
	head.id = -1;
	head.next = &tail;
	head.prev = NULL;
	tail.id = -1;
	tail.next = NULL;
	tail.prev = &head;
}

void TraverseForward()
{
	printf("Traversing forwards ...\n");
	NODE* ptr = &head;
	ptr = ptr->next;
	while(ptr->next)
	{
		printf("%i\n", ptr->id);
		ptr = ptr->next;
	}
}

void TraverseBackward()
{
	printf("Traversing backwards ...\n");
	NODE* ptr = &tail;
	ptr = ptr->prev;
	while(ptr->prev)
	{
		printf("%i\n", ptr->id);
		ptr = ptr->prev;
	}
}

void addNode(int id)
{
	/* configure new node */
	NODE* ptr = (NODE*) malloc(sizeof(NODE));
	ptr->id = id;
	ptr->next = &tail;
	ptr->prev = tail.prev;

	/* adjust adjacent nodes */
	tail.prev->next = ptr;
	tail.prev = ptr;
}

/*
 addNodeAtHead
 removeNodeAtHead
 removeNodeAtTail
 */
int main(void)
{
	setupList();
	addNode(20);
	addNode(15);
	addNode(17);
	addNode(31);
	addNode(44);
	TraverseForward();
	TraverseBackward();
}
