/**********************************************************************

    File:           SEARCH.C

    Description:    This routine searches an unsorted hand of "cards"
		            for the 3 of spades (the key card).  The program
		            illustrates how to use the routines:

			qsort           : to sort the hand
			bsearch         : to locate the key card

**********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct card
{
    char suit;
    int  index;
};

typedef struct card CARD;
typedef int (*CARD_FUNCTION)   (const CARD *keyCard, const CARD *card);
typedef int (*COMPARE_FUNCTION)(const void *elem1,   const void *elem2);

int cmpCards(const CARD *keyCard, const CARD *card);
int getRank(const CARD *card);
void printCard(const CARD* pCard);


int main(void)
{
    COMPARE_FUNCTION fcmp;

    CARD *cardPtr;
    CARD s3      =   { 's', 3  };
    CARD hand[8] = { { 's', 12 },
		             { 's', 10 },
		             { 'c', 7  },
		             { 'h', 9  },
		             { 'd', 6  },
		             { 's', 3  },
		             { 'd', 11 },
		             { 'd', 14 } };

    fcmp = (COMPARE_FUNCTION) cmpCards;
    qsort( hand, 8, sizeof( CARD), fcmp);
    cardPtr = bsearch( &s3, hand, 8, sizeof( CARD), fcmp);
    printCard(cardPtr);
}

int cmpCards(const CARD *keyCard,const CARD *card)
{
    int keyRank, cardRank, result;

    keyRank  = getRank(keyCard);
    cardRank = getRank(card);

    if( keyRank >  cardRank) result = +1;
    if( keyRank == cardRank) result =  0;
    if( keyRank <  cardRank) result = -1;
    return result;
}

int getRank(const CARD *card)
{
    int rank;

    switch( card->suit)
    {
	    case 'c': rank = 0;  break;
	    case 'd': rank = 13; break;
	    case 'h': rank = 26; break;
	    case 's': rank = 39; break;
    }

    rank = rank + card->index - 1;

    return rank;
}

void printCard(const CARD* p)
{
	printf("%i %c\n", p->index, p->suit);
}
