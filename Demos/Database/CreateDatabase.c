/*********************************************************************/
/*                                                                   */
/*                          CreateDatabase.C                               */
/*                                                                   */
/*       Create database file from text file.                        */
/*                                                                   */
/*********************************************************************/

#include <unistd.h>
#include "CreateDatabase.h"

/*********************************************************************/

FILE*  databasePtr;
FILE*  textFilePtr;
Record buffer;
int    recordCount = 0;

/*********************************************************************/

int main (void)
{
	chdir("Database");
    CreateDatabaseFile();
    OpenPhoneNumbersFile();
    CopyDataToDatabase();
    CloseFiles();
}

/*********************************************************************/

void CreateDatabaseFile (void)
{
    databasePtr = fopen (DATABASE, "w+b");
    if (databasePtr == NULL)
    {
        puts ("Can't create database");
        exit (1);
    }
}

/*********************************************************************/

void OpenPhoneNumbersFile (void)
{
    textFilePtr = fopen (TEXTFILE, "r");
    if (textFilePtr == NULL)
    {
        puts ("Can't open test data");
        exit (1);
    }
}
/*********************************************************************/

void CopyDataToDatabase (void)
{
    int status;

    WriteDummyHeader();

    while(1)
    {
        status = GetRecord();
        if (status == END) break;
        PutRecord();
    }

    WriteRealHeader();
}

/*********************************************************************/

void WriteDummyHeader (void)
{
    fprintf (databasePtr, "%4i", recordCount);
}

/*********************************************************************/

void WriteRealHeader (void)
{
    fseek (databasePtr, 0, SEEK_SET);
    fprintf (databasePtr, "%4i", recordCount);
}

/*********************************************************************/

int GetRecord(void)
{
    int status;

    status = fscanf (textFilePtr, "%s %s %s", buffer.FirstName,
                          buffer.LastName,
                          buffer.PhoneNumber);
    if (status != 3)
        return END;
    else
    {
        recordCount++;
        return OK;
    }
}

/*********************************************************************/

void PutRecord(void)
{
    int size;

    size = sizeof (buffer);
    fwrite (&buffer, size, 1, databasePtr);
}

/*********************************************************************/

void CloseFiles (void)
{
    fclose (databasePtr);
    fclose (textFilePtr);
}

