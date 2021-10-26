/*********************************************************************/
/*                                                                   */
/*                          PrintIndex.C                                */
/*                                                                   */
/*      Print complete index file to screen.                         */
/*                                                                   */
/*********************************************************************/

#include <unistd.h>
#include "PrintIndex.h"

FILE*       indexFilePtr;
int         recordCount;
IndexRecord indexBuffer;

/*********************************************************************/


int main (void)
{
	chdir("Database");
    OpenIndexFile();
    HowManyRecords();
    PrintIndexRecords();
    CloseFile();
}

/*********************************************************************/

void PrintIndexRecords (void)
{
    int i;

    PrintHeadings();

    for (i = 1; i <= recordCount; i++)
    {
        PrintEachRecord();
        PauseAtEndOfPage(i);
    }
}

/*********************************************************************/

void PrintHeadings (void)
{
    system ("clear");

    printf ("%-16s %s \n\n", "LastName", "Offset");
}

/*********************************************************************/

void PrintEachRecord (void)
{
    int size;

    size = sizeof (indexBuffer);
    fread (&indexBuffer, size, 1, indexFilePtr);
    printf ("%-16s %li \n", indexBuffer.KeyField,
                            indexBuffer.Offset);
}

/*********************************************************************/

void PauseAtEndOfPage (int line)
{
    if ((line % 20) == 0) scanf("%*[^\n]%*c");
}

/*********************************************************************/

void OpenIndexFile (void)

{
    indexFilePtr = fopen (INDEXFILE, "rb");
    if (indexFilePtr == NULL)
    {
        puts ("Can't open database");
        exit (1);
    }
}

/*********************************************************************/

void HowManyRecords()
{
    fscanf (indexFilePtr, "%4i", &recordCount);
}

/*********************************************************************/

void CloseFile (void)
{
    fclose (indexFilePtr);
}

