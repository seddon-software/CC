/*
 *  An array of structures is defined in a similar way to built in data types.  Remember to include the struct keyword unless you 
 *  define an alias using a typedef.
 * 
 *  Recall that when an array is passed, we are really passing a pointer to the start of the array.  This also applies to an array 
 *  of structs, as in this example.
 */

#include <stdio.h>
#define SIZE 5

struct Card
{
  char suit;
  int index; 
};

void print_hand(struct Card hand[])
{
    printf("Hand = ");
    for(int i = 0; i < SIZE; i++)
    {
        printf("{%c,%i} ", hand[i].suit, hand[i].index);
    }
    printf("\n");
}

void initialise_by_postion()
{
    struct Card hand[SIZE] = {
        {'s',13},
        {'h',12},
        {'s', 4},
        {'d', 7},
        {'s', 1}
    };
    print_hand(hand);
}

void initialise_by_name()
{
    struct Card hand[SIZE] = {
        {.suit = 's', .index = 13},
        {.suit = 'h', .index = 12},
        {.suit = 's', .index =  4},
        {.suit = 'd', .index =  7},
        {.suit = 's', .index =  1}
    };
    print_hand(hand);
}

void modify_at_runtime()
{
    struct Card hand[SIZE];

    hand[0].suit = 's';  hand[0].index = 13;
    hand[1].suit = 'h';  hand[1].index = 12;
    hand[2].suit = 's';  hand[2].index = 4;
    hand[3].suit = 'd';  hand[3].index = 7;
    hand[4].suit = 's';  hand[4].index = 1;
    print_hand(hand);
}

int main(void)
{
    initialise_by_postion();
    initialise_by_name();
    modify_at_runtime();
}
