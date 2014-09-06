#include <stdio.h>

// prototypes
int *optellen(int getalA, int getalB);
int *vermenigvuldigen ( int getalA, int getalB);
int bereken(int *calc(int , int ), int valueA, int valueB);

// main functie
int main(void)
{
	printf("\n\nuitkomst van de optel berekening is: %d\n\n", bereken(optellen,20,40));
	printf("uitkomst van de vermenigvuldig berekening is: %d\n\n", bereken(vermenigvuldigen,20,40));
	
	return 0;
	
}

// functies
int *optellen(int getalA, int getalB)
{
	int *pointer = NULL;
	int uitkomst = getalA + getalB;
	pointer = &uitkomst;
	return pointer;
}

int *vermenigvuldigen ( int getalA, int getalB)
{
	int *pointer = NULL;
	int uitkomst = getalA * getalB;
	pointer = &uitkomst;
	return pointer;
}
int bereken(int *calc(int , int ), int valueA, int valueB)
{
	return *calc(valueA,valueB);
}
