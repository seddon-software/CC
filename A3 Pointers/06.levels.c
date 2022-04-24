#include <stdio.h>

/*
 *
 *  Memory diagram:
 *         ┌─────────┐      ┌─────────┐     ┌─────────┐
 *      ppx│  &px    │───➤px│   &x    │───➤x│   100   │
 *         └─────────┘      └─────────┘     └─────────┘
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