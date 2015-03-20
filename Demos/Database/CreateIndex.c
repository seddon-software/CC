/*********************************************************************/
/*                                                                   */
/*                          CreateIndex.C                               */
/*                                                                   */
/*      Create index file for database.                              */
/*                                                                   */
/*********************************************************************/

#include <unistd.h>
#include "CreateIndex.h"

FILE*       databasePtr;
FILE*       indexFilePtr;
int         recordCount;
long        offset;
Record      buffer;
IndexRecord indexBuffer;

/*********************************************************************/

int main (void)
{
	chdir("Database");
    OpenDatabaseFile();
    CreateIndexFile();
    HowManyRecords();
    WriteIndexRecords();
    CloseFiles();
}

/*********************************************************************/

void WriteIndexRecords (void)
{
    int i;

    WriteHeader();

    for (i = 0; i < recordCount; i++)
    {
        GetRecord();
        CreateIndexRecord();
        PutRecord();
    }
}

/*********************************************************************/

void WriteHeader (void)
{
    fprintf (indexFilePtr, "%4i", recordCount);
}

/*********************************************************************/

void GetRecord (void)
{
    int size;

    size = sizeof (buffer);
    offset = ftell (databasePtr);
    fread (&buffer, size, 1, databasePtr);
}

/*********************************************************************/

void CreateIndexRecord (void)
{
    indexBuffer.Offset = offset;
    strcpy (indexBuffer.KeyField, buffer.LastName);
}

/*********************************************************************/

void PutRecord (void)
{
    int size;

    size = sizeof (indexBuffer);
    fwrite (&indexBuffer, size, 1, indexFilePtr);
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

void CreateIndexFile (void)
{
    indexFilePtr = fopen (INDEXFILE, "w+b");
    if (indexFilePtr == NULL)
    {
        puts ("Can't create index file");
        exit (1);
    }
}

/*********************************************************************/

void HowManyRecords(void)
{
    fscanf (databasePtr, "%4i", &recordCount);
}

/*********************************************************************/

void CloseFiles (void)
{
    fclose (databasePtr);
    fclose (indexFilePtr);
}


