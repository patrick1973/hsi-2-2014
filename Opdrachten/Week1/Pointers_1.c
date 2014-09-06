#include <stdio.h>

main()
{
	int Getal;
	int *pointer1 = NULL;
	int *pointer2 = NULL;
	
	pointer1 = &Getal;
	pointer2 = &Getal;
	
	*pointer1 = 5;
	
	printf("Pointer 2 = %d\n",*pointer2);
	
}