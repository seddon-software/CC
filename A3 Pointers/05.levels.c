#include <stdio.h>

/*
 *  About 20 years ago, C compilers reported errors with pointers in terms of "Levels of indirection".  Modern compilers don't use this concept any more, but, personally, I found the concept very useful.
 *
 *  The basic idea is that data is at level 0.  All pointers to data are at level 1, pointers to pointers at level 2 and so on.  Interestingly, the pointer declation defines the level by the number of stars in the declaration.  e.g.
 *      int*** q;
 * 
 *  defines a level 3 pointer.  The rules are that a level N pointer is only allowed to point at a level N-1 pointer.
 *   
 *  Memory diagram:
 *          int** ppx         int* px          int x
 *         ┌─────────┐      ┌─────────┐     ┌─────────┐
 *      ppx│  &px    │───➤px│   &x    │───➤x│   100   │
 *         └─────────┘      └─────────┘     └─────────┘
 *           Level 2           Level 1         Level 0
 */

int main(void)
{
    int x = 100;        // no *s, so Level 0
    int* px = &x;       // one *, so Level 1
    int** ppx = &px;    // two *s, so Level 2
        
    // Level 0
    printf("x     = %i\n", x);
    printf("*px   = %i\n", *px);
    printf("**ppx = %i\n", **ppx);
    
    // Level 1
    printf("&x    = %p\n", &x);     // & increases level by 1
    printf("px    = %p\n", px);     // &* cancels out, &*px is same as px
    printf("*ppx  = %p\n", *ppx);   // &* cancels out, &**ppx is same as *ppx
    
    // Level 2
    printf("&px   = %p\n", &px);    
    printf("ppx   = %p\n", ppx);    // &* cancels out, &*ppx is same as ppx
}