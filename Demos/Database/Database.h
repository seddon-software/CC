#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*********************************************************************/

#define TEXTFILE  "PHONES.TXT"
#define DATABASE  "PHONES.DBX"
#define INDEXFILE "PHONES.INX"

enum { OK, END};

typedef char String[16];

struct record
{
    String FirstName;
    String LastName;
    String PhoneNumber;
};

struct indexRecord
{
    String KeyField;
    long Offset;
};

typedef struct record      Record;
typedef struct indexRecord IndexRecord;

/*********************************************************************/


