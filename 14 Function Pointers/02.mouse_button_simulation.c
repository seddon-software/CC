#include <stdio.h>

void message1()
{
    printf("HotKey 1\n");
}
void message2()
{
    printf("HotKey 2\n");
}
void message3()
{
    printf("HotKey 3\n");
}

typedef struct Button
{
    const char* name;
    void (*callback)(void);
} Button;

void bind(Button* b, void (*callback)(void))
{
    b->callback = callback;
}

void press(Button* b)
{
    printf("%s\t", b->name);
    b->callback();
}

int main(void)
{
    Button left = {.name="LEFT"};
    Button middle = {.name="MIDDLE"};
    Button right = {.name="RIGHT"};

    bind(&left, message1);
    bind(&right, message2);
    bind(&middle, message3);

    press(&left);
    press(&middle);
    press(&right);
    
    bind(&left, message3);
    bind(&right, message1);
    bind(&middle, message2);

    press(&left);
    press(&middle);
    press(&right);
}
