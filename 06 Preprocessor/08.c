#include <stdio.h>

#define G(p, n, f) #p #n #f

int main() {
    char* s = G(%,10,s);
    printf("%s\n", "%" "10" "s");
    printf("%s\n", s);
    printf(s, "Hello");
}