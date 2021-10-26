#include <stdio.h>

// typedefs

typedef struct {
    char name[8];
    double limit;
} Observer;

typedef struct {
    Observer* list[3];        
    int last;
} Registry;

typedef struct {
    Registry* pRegistry;
} TemperatureMonitor;



// functions
void Register(Registry* pRegistry, Observer* pObserver)
{
    int last = pRegistry->last++;
    pRegistry->list[last] = pObserver;
}

void observerCallback(Observer* pObserver, double temperature)
{
    printf("%s observes temperature (%4.1lf) > %4.1lf\n", pObserver->name, temperature, pObserver->limit);
}

void notifyAll(Registry* pRegistry, double temperature)
{
    for(int i = 0; i < pRegistry->last; i++)
    {
        Observer* pObserver = pRegistry->list[i];
        if(temperature > pObserver->limit) {
            observerCallback(pObserver, temperature);
        }
    }
}

void setTemperature(TemperatureMonitor* pPublisher, double temperature)
{
    Registry* pRegistry = pPublisher->pRegistry;
    notifyAll(pRegistry, temperature);
}

int main()
{
    Registry registry = {};
	TemperatureMonitor publisher = { &registry };
	Observer john = (Observer) { "John", 20.0 };
	Observer susan = (Observer) { "Susan", 23.0 };
	Observer peter = (Observer) { "Peter", 26.0 };

    Register(&registry, &john);
    Register(&registry, &susan);
    Register(&registry, &peter);

	double temperatures[7] = { 18.0, 21.0, 24.5, 27.3, 26.2, 22.5, 26.7 };
	for(int i = 0; i < 7; i++)
	{
		setTemperature(&publisher, temperatures[i]);
	}
}

