#include <stdio.h>

void g(int (*x)[2]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%i ", x[i][j]);
        }
    }
    printf("\n");
}

void f(int x[][2]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%i ", x[i][j]);
        }
    }
    printf("\n");
}

int main(void) {
    int a[3][2] = {{10,11}, {20,21}, {30,31}};
    f(a);
    g(a);
}