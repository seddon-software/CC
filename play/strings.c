#include <stdio.h>

void printIt(char* x) {
    while(*x != '\0') {
        printf("%c", *x);
        fflush(stdout);
        x++;
    }
    printf("\n");
}

void StringCopy(char* t, char* s) {
    while(*s != '\0') {
        *t = *s;
        s++;
        t++;
    }
    *t = *s;
}

int main(void) {
    char s[] = "abcde";
    char t[10];
    StringCopy(t, s);   // t = s  // strcpy(t, s)
    s[0] = 'x';
    // t[0] = 'x';
    printIt(s);
    printIt(t);
}
