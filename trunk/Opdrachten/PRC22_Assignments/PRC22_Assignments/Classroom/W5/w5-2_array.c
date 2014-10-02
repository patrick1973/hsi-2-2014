#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array_of_int[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int copy_array_of_int[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int *pointerToArray=NULL;	
	
	pointerToArray = array_of_int; // nu wijst de pointer naar het eerste element van de array
	
	int i=0;
	for (i=200; i<=290;i += 10)
	{
		*pointerToArray=i;
		pointerToArray++;
	}
	
	int p=0;
	pointerToArray = array_of_int; // laat de pointer opnieuw wijzen om op het eerste element uit te komen
	for (p=0; p <10; p++)
	{
		copy_array_of_int[p] = *pointerToArray;
		printf(" inhoud van array_of_int[%d] = (%d) en de inhoud van copy[%d] = (%d)\n",p,array_of_int[p],p,copy_array_of_int[p]);
		pointerToArray++;
	} 
	
	return 0;
}
