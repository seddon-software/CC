/*********************************************************************/
/*                                                                   */
/*                          PrintDatabase.C                                */
/*                                                                   */
/*      Print complete database on screen                            */
/*                                                                   */
/*********************************************************************/

#include <unistd.h>
#include "PrintDatabase.h"

FILE*  databasePtr;
int    recordCount;
Record buffer;

/*********************************************************************/


int main (void)
{
	chdir("Database");
    OpenDatabaseFile();
    HowManyRecords();
    PrintRecords();
    CloseFile();
}

/*********************************************************************/

void PrintRecords (void)
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

    printf ("%-16s %-16s %-8s \n\n", "FirstName",
                                     "LastName",
                                     "PhoneNumber");
}

/*********************************************************************/

void PrintEachRecord (void)
{
    int size;

    size = sizeof (buffer);
    fread (&buffer, size, 1, databasePtr);
    printf ("%-16s %-16s %-8s \n", buffer.FirstName,
                                   buffer.LastName,
                                   buffer.PhoneNumber);
}

/*********************************************************************/

void PauseAtEndOfPage (int line)
{
    if ((line % 20) == 0) scanf("%*[^\n]%*c");
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

void HowManyRecords()
{
    fscanf (databasePtr, "%4i", &recordCount);
}

/*********************************************************************/

void CloseFile (void)
{
    fclose (databasePtr);
}

