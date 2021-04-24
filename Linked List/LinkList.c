/*******************************************************************

		LinkList.c

*******************************************************************/

#include "LinkList.h"

NODE* headPtr;

void display() {
	NODE* ptr;
	ptr = headPtr;
	while(ptr->next) {
	    printf("%8s", ptr->pData->name);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = headPtr;
	while(ptr->next) {
	    printf("%8i", ptr->pData->salary);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = headPtr;
	while(ptr->next) {
	    printf("%-8s", "     ^");
		ptr = ptr->next;
	}
	printf("\n");
	ptr = headPtr;
	while(ptr->next) {
	    printf("%-8s", "     |");
		ptr = ptr->next;
	}
	printf("\n");
	ptr = headPtr;
	while(ptr->next) {
	    printf("%8s", "NODE");
		ptr = ptr->next;
	}
	printf("\n");	
}

void setupList() {
	// create a dummy entry at the head of the list (simplifies subsequent code)
	DATA* pData = (DATA*) malloc(sizeof(DATA));
	strcpy(pData->name, "--head--");
	pData->salary = -1;
	headPtr = (NODE*) malloc(sizeof(NODE));
	headPtr->pData = pData;
	headPtr->next = NULL;
}

DATA* createDataNode(const char* name, int salary) {
	DATA* pData = (DATA*) malloc(sizeof(DATA));
	strcpy(pData->name, name);
	pData->salary = salary;
	return pData;
}

void printData(DATA* pData) {
	printf("%-10s %5i\n", pData->name, pData->salary);
}

void traverseList() {
	printf("Traversing list ...\n");
	NODE* ptr = headPtr;
	while(ptr->next) {
		printData(ptr->pData);
		ptr = ptr->next;
	}
}


void addNode(DATA data) {
	/* configure new node */
	NODE* ptr = headPtr;
	while(ptr->next) {
		ptr = ptr->next;
	}
	NODE* pNode = (NODE*) malloc(sizeof(NODE));
    ptr->next = pNode;
	ptr->pData = createDataNode(data.name, data.salary);
	display();
	char ch;
	scanf("%c", &ch);
}

NODE* findNodeBefore(const char* name) {
	NODE* ptr = headPtr;
	NODE* previousPtr;
	while(ptr->next) {
		previousPtr = ptr;
		ptr = ptr->next;
		DATA* pData = ptr->pData;
		if(!strcmp(pData->name, name)) break;
	}
	return previousPtr;
}

void removeNode(const char* name) {
	NODE* beforePtr = findNodeBefore(name);
	NODE* toBeDeletedPtr = beforePtr->next;

	beforePtr->next = toBeDeletedPtr->next;
	free(toBeDeletedPtr);
}

int main(void) {
	DATA names[] = {{"John",  42000},
                    {"Peter", 21000},
                    {"Tom",   26000},
                    {"Ali",   40000},
                    {"Zoe",   45000},
                    {"Jane",  31000},
                    {"Sue",   36000},
                    {"Karda", 20000},
                    {"Bill",  47000}};
	setupList();
	int count = sizeof(names)/sizeof(DATA);
	for(int i = 0; i < count; i++) {
	    addNode(names[i]);
	}
	traverseList();
	printf("removing node for 'Sue'\n");
	removeNode("Sue");
	display();
	traverseList();
}
