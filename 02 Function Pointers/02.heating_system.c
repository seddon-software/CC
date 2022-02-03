////////////////////////////////////////////////////////////
//
//		Command Pattern
//
////////////////////////////////////////////////////////////

// Original example developed by Kevlin Henney (https://kevlinhenney.medium.com/)

/*
 *  The Command pattern is designed to decouple a request for an operation from its execution.  An operation
 *  is defined in terms of an object bound to a method; a separate class is used to record this information.
 *
 *  In this example, the load_event method records several operations (function pointer) in a vector along 
 *  with the times when the callback is to be made.  The fire_events method decides whether or not to 
 *  execute the request.
 *
 *  If a system is to model several different events then the simplest approach is to define a separate 
 *  class for each event.  Of course the class should implement the Command interface.  
 * 
 *  This example defines two events: turn_off and turn_on a heating system.  These events are modelled 
 *  by the HeatingOff and HeatingOn classes respectively.
 *
 *  The main program creates the event objects and a Timer object is used to record the events and 
 *  timings.  The simulation sets off the timer and events are fired at various times.
 */

#include <stdio.h>
typedef struct HeatingSystem
{
	const char* name;
} HeatingSystem;

typedef struct Event
{
    void (*callback)(HeatingSystem* target);
    HeatingSystem* target;
	int time;
} Event;

void on(HeatingSystem* target) 
{ 
    printf("turn on %s\t", target->name); 
}
void off(HeatingSystem* target) 
{  
    printf("turn off %s\t", target->name); 
}
void service(HeatingSystem* target) 
{  
    printf("service %s\t", target->name); 
}

int main()
{
	HeatingSystem systemA = {.name = "A"};
    HeatingSystem systemB = {.name = "B"};
	Event	controller[] = {
	    {.callback = off,     .target=&systemA, .time =  4},
	    {.callback = on,      .target=&systemA, .time =  5},
        {.callback = off,     .target=&systemA, .time =  8},
	    {.callback = service, .target=&systemA, .time = 10},
	    {.callback = on,      .target=&systemA, .time =  2},
	    {.callback = off,     .target=&systemB, .time =  7},
	    {.callback = on,      .target=&systemB, .time =  3},
	    {.callback = off,     .target=&systemB, .time =  8},
	    {.callback = service, .target=&systemB, .time = 11}
    };
    int numberOfControllers = sizeof(controller)/sizeof(Event);

	printf("start of simulation\n");
    for(int t = 1; t <= 12; t++)
    {
        printf("%i: ", t);
        for(int i = 0; i < numberOfControllers; i++)
        {
            Event tc = controller[i];
            if(tc.time == t)
            {
                tc.callback(tc.target);
            }
        }
        printf("\n");
    }
    printf("end of simulation\n");
}

