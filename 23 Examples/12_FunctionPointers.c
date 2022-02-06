#include <stdio.h>

void (*button[3])(void);   // button is array of 3 (because of precedence table) of pointers to functions of (void) returning void


void PaintItBlack(void)
{
    printf("Black \n");
}

void PaintItWhite(void)
{
    printf("White \n");
}

void SwapButtons(void)
{
    void (*temp)(void);

	temp      = button[0];
	button[0] = button[2];
	button[2] = temp;
}

void PressLeftButton(void)
{
    (*button[0])();
}

void PressRightButton(void)
{
    (*button[2])();
}

int main(void)
{
    button[0] = &PaintItBlack;
    button[1] = &SwapButtons;
    button[2] = &PaintItWhite;

	PressLeftButton();
	PressRightButton();

    SwapButtons();

	PressLeftButton();
	PressRightButton();
}
