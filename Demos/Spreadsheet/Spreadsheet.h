/************************************************************************

    File:           Spreadsheet.H

    Purpose:        Simplistic 2-D spreadsheet program

    Author:         Chris Seddon

************************************************************************/

#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* definitions *************/
enum { EMPTY = 0, FILLED = 1, MAX = 9, CHAR_WIDTH = 6 };

struct cell
{
    char        name[CHAR_WIDTH+1];
    short       row;
    short       col;
    struct cell *next;
    struct cell *prev;
};

typedef struct cell  Cell;
typedef struct cell* CellPtr;

int GetNextChar(void);


#endif
