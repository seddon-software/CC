#include <stdio.h>

#define MAX_EVENTS 16

void switch_on(char* system, int t)
{
    printf("switching on %s at t=%i\n", system, t);
}

void switch_off(char* system, int t)
{
    printf("switching off %s at t=%i\n", system, t);
}

void service(char* system, int t)
{
    printf("servicing %s at t=%i\n", system, t);
}

typedef struct {
    void (*fp)(char*, int);
    char* s;
} TimerController;

int main()
{
	TimerController	tc[MAX_EVENTS] = {};

	tc[4]  = (TimerController) { &switch_on, "boiler A" };
	tc[8]  = (TimerController) { &switch_off, "boiler A" };
	tc[10] = (TimerController) { &service, "boiler A" };
	tc[2]  = (TimerController) { &switch_on, "boiler B" };
	tc[3]  = (TimerController) { &switch_off, "boiler B" };
	tc[7]  = (TimerController) { &switch_on, "boiler B" };
	tc[8]  = (TimerController) { &switch_off, "boiler B" };
	tc[11] = (TimerController) { &service, "boiler B" };

    for(int t = 0; t < 16; t++)
    {
        TimerController c = tc[t];
        if(tc[t].fp) {
            c.fp(tc[t].s, t);
        }
    }
/*
	cout << "start of simulation";
	while(controller.tick());
	cout << endl << "end of simulation" << endl;

	return 0;
*/
}

