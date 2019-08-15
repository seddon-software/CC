#include <time.h>
#include <stdio.h>

void ElapsedTime(void)
{
    time_t    clockTicks;
    double   processorTimeUsed;

    clockTicks = clock();
	processorTimeUsed =  (double) clockTicks / CLOCKS_PER_SEC;
}

time_t   timeInSeconds;
struct tm dateAndTime;

void DateAndTime(void)
{
    timeInSeconds = time(NULL);
    dateAndTime = *localtime(&timeInSeconds);
}

char timeAsString[256];

void PrintDate(struct tm dateAndTime)
{
    strftime(timeAsString,
             256,
             "%A, %B %d %Y",
             &dateAndTime);
    printf("%s\n", timeAsString);
}

void CheckingDates(void)
{
	#define JAN    1 - 1
	#define FEB    2 - 1
	struct tm Feb28 = { 0, 0, 0, 28, FEB, 98, 0, 0, -1 };
	struct tm Feb29 = { 0, 0, 0, 29, FEB, 98, 0, 0, -1 };
	struct tm Feb99 = { 0, 0, 0, 29, FEB, 100, 0, 0, -1 };
    time_t secs;

	secs = mktime(&Feb28);
	PrintDate(Feb28);

	secs = mktime(&Feb29);
	PrintDate(Feb29);

	secs = mktime(&Feb99);
	PrintDate(Feb99);
}

int main(void)
{
    ElapsedTime();
	DateAndTime();
	CheckingDates();
}
