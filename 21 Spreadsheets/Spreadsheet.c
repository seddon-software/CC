/************************************************************************

    File:           Spreadsheet.C

    Purpose:        Simplistic 2-D spreadsheet program

    Author:         Chris Seddon

************************************************************************/

#include "Spreadsheet.h"

/********* function prototypes **************/

void Refresh(void);
int  GetUserChoice(void);
void Insert(void);
void Delete(void);
void GetData(void);
void SelectInsertionPoint(void);
void ModifyName(void);
void AllocateHeapSpace(void);
void FillInCellDeatails(void);

/********** global declarations *************/

CellPtr ptr, ptr1, ptr2;
Cell    head = { "HEAD", 0,     0,     NULL, NULL };
Cell    tail = { "TAIL", MAX+1, MAX+1, NULL, NULL };

int  row, col;
int  index1, index2;
char name[CHAR_WIDTH+1];



/********** main routine ***********************************************/

int main(void)
{
    int choice;

    head.next = &tail;
    tail.prev = &head;

    do
    {
        Refresh();
        choice = GetUserChoice();

        switch (choice)
        {
            case 0:  puts(""); break;
            case 1:  Insert(); break;
            case 2:  Delete(); break;
            default: puts(" ...invalid option");
                     GetNextChar();
        }
    }
    while(choice);
}

/***********************************************************************/

void Insert(void)
{
    GetData();
    SelectInsertionPoint();

/* if pointers are equal then cell is already occupied */
/* otherwise ptr1 is just after insertion point        */
/*       and ptr2 is just before insertion point       */

/* case 1: pointers equal no heap space required */

    if(index1 == index2) ModifyName();

/* case 2: pointers unequal - allocate heap space */

    if(index1 != index2) 
    {
        AllocateHeapSpace();
        FillInCellDeatails();
    }
}

/***********************************************************************/

void Delete(void)
{
    int     row, col, matches;
    int     index, index1, index2;
    CellPtr ptr1, ptr2;

    printf("\n\nEnter row col: ");
    matches = scanf("%i %i%*[^\n]%*c", &row, &col);

    while(matches != 2 || row > MAX || row <= 0 || col > MAX || col <= 0)
    {
        puts(" ... invalid data - try again");
        scanf("%*[^\n]%*c");  /* discard input */
        printf("\n\nEnter row col: ");
        matches = scanf("%i %i%*[^\n]%*c", &row, &col);
    }

/* point at either end of list */

    ptr1 = &head;
    ptr2 = &tail;

    index1 = ptr1->row * MAX + ptr1->col;
    index2 = ptr2->row * MAX + ptr2->col;

/* move pointers along list to deletion point */

    index = row * MAX + col;

    while(index1 < index)
    {
        ptr1 = ptr1->next;                         /* bump pointer */
        index1 = ptr1->row * MAX + ptr1->col;      /* update index */
    }

    while(index2 > index)
    {
        ptr2 = ptr2->prev;                         /* bump pointer */
        index2 = ptr2->row * MAX + ptr2->col;      /* update index */
    }

/* if pointers are equal then cell is on the heap and  */
/* must be freed, otherwise cell is not on the heap    */

/* case 1: pointers equal - free heap space */

    if(index1 == index2)
    {
        ptr = ptr1;         /* ptr now points at unwanted cell */
        ptr1 = ptr->prev;   /* ptr1 is before deletion point   */
        ptr2 = ptr->next;   /* ptr2 is after deletion point    */
        ptr1->next = ptr2;
        ptr2->prev = ptr1;
        free(ptr);
    }

/* case 2: pointers unequal - cell already empty (do nothing) */

}

/***********************************************************************/

int GetUserChoice(void)
{
    int choice;
    printf("                         \n"
           "Enter Choice: 0 = exit   \n"
           "              1 = insert \n"
           "              2 = delete : ");

    choice = GetNextChar() - '0';
    while (choice < 0 || choice > 2)
    {
        puts(" ... invalid choice - try again");
        scanf("%*[^\n]%*c");  /* discard input */
        choice = GetNextChar() - '0';
    }

    return choice;
}


/***********************************************************************/

int GetNextChar()
{
	int c;
	while((c = getchar()) == '\n');			/* skip newlines */
	return c;
}
/***********************************************************************/

void Refresh(void)
{
    CellPtr ptr;
    int     i, cell, row, col;
    char    str[CHAR_WIDTH+1];

    system("clear");
    printf("\n\n%40s\n\n      ", "2 DIMENSION SPREADSHEET");

    for(i = 1; i <= MAX; i++)
    {
        sprintf(str,"(%i)",i);
        printf("%7s",str);
    }
    puts("");

    ptr = head.next;

    for(row = 1; row <= MAX; row++)
    {
        sprintf(str, "\n(%d)", row);
        printf("%-9s|", str);

        for(col = 1; col <= MAX; col++)
        {
            if(ptr == NULL)
            cell = EMPTY;        /* no more FILLED cells left */
            else
            if(ptr->row == row && ptr->col == col)
                cell = FILLED;
            else
                cell = EMPTY;

            if(cell == EMPTY )
                printf("      |");
            else
            {
            printf("%-6s|",ptr->name);
            ptr = ptr->next;
            }
        }
    }
}

/***********************************************************************/

void GetData()
{
    int matches;
    while(1)
    {
        printf("\n\nEnter row col name: ");
    	/* if the user types in too many characters, discard he excess */
        matches = scanf("%i %i %6s%*[^\n]%*c", &row, &col, name);

        if(matches != 3 || row > MAX || row <= 0 || col > MAX || col <= 0)
        {
            puts(" ... invalid data - try again");
            scanf("%*[^\n]%*c");  /* discard input */
        }
        else
            break;
    }
}

/***********************************************************************/

void SelectInsertionPoint()
{
    int index;
    
/* point at either end of list */
    
    ptr1 = &head;
    ptr2 = &tail;

    index1 = ptr1->row * MAX + ptr1->col;
    index2 = ptr2->row * MAX + ptr2->col;

/* move pointers along list to insertion point */

    index = row * MAX + col;

    while(index1 < index)
    {
        ptr1 = ptr1->next;                         /* bump pointer */
        index1 = ptr1->row * MAX + ptr1->col;      /* update index */
    }

    while(index2 > index)
    {
        ptr2 = ptr2->prev;                         /* bump pointer */
        index2 = ptr2->row * MAX + ptr2->col;      /* update index */
    }
}

/***********************************************************************/

void ModifyName(void)
{
    strcpy(ptr1->name, name);
}

/***********************************************************************/

void AllocateHeapSpace(void)
{
    ptr = malloc(sizeof(Cell));
    if(ptr == NULL)
    {
        puts("*** Memory Allocation Error ***");
        exit(1);
    }
}    

/***********************************************************************/

void FillInCellDeatails(void)
{
    strcpy(ptr->name, name);
    ptr->row = row;
    ptr->col = col;
    ptr->next = ptr1;
    ptr->prev = ptr2;
    ptr2->next = ptr;
    ptr1->prev = ptr;
}
