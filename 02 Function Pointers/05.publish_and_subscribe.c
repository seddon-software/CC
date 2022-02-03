#include <stdio.h>

/*  
 *  A typical application of callbacks is in the software pattern Pub/Sub (publish and subscribe).
 *  The pattern has a publisher (in our case a TemperaturMonitor) and a number of Observers.  The   
 *  publisher notifies interested parties when an event occurs using a callback.  Typically all the 
 *  observers register with the publisher with an optional condition (in our case the observer 
 *  wants to be notified when the temperature has reached a threshold).
 */

#define NUMBER_OF_OBSERVERS 3
#define NUMBER_OF_TEMPERATURES 6

typedef struct Observer
{
    char *name;
    double threshold;
    void (*callback)(struct Observer, double);
} Observer;

Observer observers[NUMBER_OF_OBSERVERS];

void callback_1(struct Observer observer, double temperature) 
{ 
    printf("%s notes temperature %5.1lf is above %5.1lf\n", observer.name, temperature, observer.threshold); 
}

void callback_2(struct Observer observer, double temperature)
{ 
    printf("WARNING: %s notes temperature %5.1lf is above %5.1lf\n", observer.name, temperature, observer.threshold); 
}

void callback_3(struct Observer observer, double temperature)
{ 
    printf("CRITICAL: %s notes temperature %5.1lf is above %5.1lf\n", observer.name, temperature, observer.threshold); 
}


void Register(Observer observer)
{
    for(int i = 0; i < NUMBER_OF_OBSERVERS; i++)
    {
        if(observers[i].name == 0)
        { 
            observers[i] = observer;
            break;
        }
    }
}

int main(void)
{
	Observer observer1 = {.name = "Observer_1", .threshold = 22.0, .callback = callback_1};
	Observer observer2 = {.name = "Observer_2", .threshold = 25.0, .callback = callback_2};
	Observer observer3 = {.name = "Observer_3", .threshold = 27.0, .callback = callback_3};
	Register(observer1);
	Register(observer2);
	Register(observer3);

    // publisher code
	double temperatures[NUMBER_OF_TEMPERATURES] = { 18.0, 21.0, 24.5, 27.3, 26.2, 23.5 };
	for(int i = 0; i < NUMBER_OF_TEMPERATURES; i++)
	{
        double temperature = temperatures[i];
        for(int k = 0; k < NUMBER_OF_OBSERVERS; k++)
        {
            Observer observer = observers[k];
            if(temperature > observer.threshold)
            { 
                observer.callback(observer, temperature);
            }
        }
	}
}

