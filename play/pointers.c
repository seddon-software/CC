#include <stdio.h>

void Swap(int* px, int* py) { // px is a copy of &x, py is a copy of &y
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main(void) {
    int x = 100;
    int y = 200;
    Swap(&x, &y);
}