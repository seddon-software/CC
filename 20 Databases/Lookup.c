/*********************************************************************/
/*                                                                   */
/*                          LOOKUP.C                                 */
/*                                                                   */
/*      Perform queries on database using index file and             */
/*      database file                                                */
/*                                                                   */
/*********************************************************************/

#include <unistd.h>
#include "Lookup.h"

int          status = OK;
String       KeyField;
FILE*        databasePtr;
FILE*        indexFilePtr;
Record       buffer;
IndexRecord* indexPtr;
int          recordCount;
int          theIndex;

/*********************************************************************/

int main (void)
{
    system ("clear");
	chdir("Database");
    OpenDatabaseFile();
    OpenIndexFile();
    HowManyRecords();
    CopyIndexFileToTheHeap();

    do
    {
        AskForNameToLookup();
        DetermineOffset();
        ExtractRecord();
        PrintRecord();
        AskIfTimeToQuit();
    }
    while (status == OK);
}

/*********************************************************************/

void ExtractRecord (void)
{
    fseek (databasePtr, indexPtr[theIndex].Offset, SEEK_SET);
    fread (&buffer, sizeof (struct record), 1, databasePtr);
}

/*********************************************************************/

void HowManyRecords (void)
{
    fscanf (indexFilePtr, "%4i", &recordCount);
}

/*********************************************************************/

void DetermineOffset (void)
{
    for (theIndex = 0; theIndex < recordCount; theIndex++)
    {
        if (!strcmp (ToUpperCase(KeyField), ToUpperCase(indexPtr[theIndex].KeyField))) break;
    }
}

/*********************************************************************/

void PrintRecord (void)
{
    system ("clear");

    if (theIndex == recordCount)
        printf ("\n\trecord not found\n");
    else
    {
        printf ("\n%-16s %-16s %-8s \n", "FirstName",
                                         "LastName",
                                         "PhoneNumber");

        printf ("%-16s %-16s %-8s \n", buffer.FirstName,
                                       buffer.LastName,
                                       buffer.PhoneNumber);
    }
}

/*********************************************************************/

void OpenDatabaseFile (void)
{
    databasePtr = fopen (DATABASE, "rb");
    if (databasePtr == NULL)
    {
        puts ("Can't open database");
        exit (1);
    }
}

/*********************************************************************/

void OpenIndexFile (void)
{
    indexFilePtr = fopen (INDEXFILE, "rb");
    if (indexFilePtr == NULL)
    {
        puts ("Can't open index file");
        exit (1);
    }
}

/*********************************************************************/

void CopyIndexFileToTheHeap (void)
{
    int size;

    size = sizeof (IndexRecord);
    indexPtr = malloc (recordCount * size);
    if (indexPtr == NULL)
    {
        puts ("Can't load index file onto heap");
        exit (1);
    }

    fread (indexPtr, size, recordCount, indexFilePtr);
}

/*********************************************************************/

char* ToUpperCase(char* s)
{
	char* t = s;
	while(*s)
	{
		*s = toupper(*s);
		s++;
	}
	return t;
}
/*********************************************************************/

void AskForNameToLookup (void)
{
    printf ("\n\nEnter name: ");
    scanf ("%s%*c", KeyField);
}

/*********************************************************************/

void AskIfTimeToQuit (void)
{
    char c;

    while (1)
    {
        printf ("\n\nContinue (y/n)? ");
        scanf("%c%*[^\n]%*c", &c);
        c = tolower(c);

        if (c == 'y' || c == 'n') break;
    }

    if (c == 'n') status = END;
}
