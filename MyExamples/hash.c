#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BINS 4

typedef struct Employee
{
	char name[16];
	int salary;
} Employee;

typedef struct Cell
{
	Employee employee;
	struct Cell* next;
} Cell;

typedef struct Hash
{
	Cell* bin[NUMBER_OF_BINS];
} Hash;

int hashFunction(char* s)
{
	return (s[1] * s[3]) % NUMBER_OF_BINS;
}

Cell* createCell(Cell* next, Employee e)
{
	Cell* newCell = malloc(sizeof(Cell));
	newCell->employee = e;
	newCell->next = next;
	return newCell;
}

void add(Hash* hash, Employee e)
{
	// create a new cell and insert it at the front of the linked list
	int n;
	Cell* base;
	n = hashFunction(e.name);
	base = hash->bin[n];
	Cell* newCell = malloc(sizeof(Cell));
	newCell->employee = e;
	newCell->next = base;
	hash->bin[n] = newCell;
}

Hash* createHash()
{
	// put dummy Cells in each bin
	int i;
	Cell* pCell;
	Hash* hash = malloc(sizeof(Hash));
	for(i = 0; i < NUMBER_OF_BINS; i++)
	{
		hash->bin[i] = malloc(sizeof(Cell));
		pCell = hash->bin[i];
		pCell->employee.name[0] = 0; // empty string
		pCell->employee.salary = -1;
		pCell->next = NULL;
	}
	return hash;
}

void debug(Hash* h)
{
	int i;
	Cell* pCell;
	// clean up cells
	for(i = 0; i < NUMBER_OF_BINS; i++)
	{
		pCell = h->bin[i];
		while(pCell->employee.salary != -1)
		{
			printf("%i: [%s,%i]\n", i, pCell->employee.name, pCell->employee.salary);
			pCell = pCell->next;
		}
	}
}

void clean(Hash* h)
{
	int i;
	Cell *current, *next;
	for(i = 0; i < NUMBER_OF_BINS; i++)
	{
		current = h->bin[i];
		while(current->employee.salary != -1)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(current);
	}
	// clean up hash
	free(h);
}

int main()
{
	Hash* salary = createHash();
	Employee john = { "John", 43000 };
	Employee bill = { "Bill", 32000 };
	Employee joan = { "Joan", 47000 };
	Employee suzy = { "Suzy", 52000 };
	Employee adil = { "Adil", 41500 };
	Employee tony = { "Tony", 33500 };
	Employee mary = { "Mary", 53000 };
	Employee jack = { "Jack", 61000 };
	Employee anne = { "Anne", 57000 };
	add(salary, john);
	add(salary, bill);
	add(salary, joan);
	add(salary, suzy);
	add(salary, adil);
	add(salary, tony);
	add(salary, mary);
	add(salary, jack);
	add(salary, anne);
	debug(salary);
	clean(salary);
	// check for memory leaks:
	//		valgrind --leak-check=yes hash
}

