#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char string1[] = "Fontys Hogeschool ICT";
	char array[] = { ' ' };
	
	
	printf( "\n\nIn de string staat:->->  %s\n\n",string1);
	strcpy(array,string1);
	
	int i =0 ;
	for (i=0; i<strlen(array);i++ )
	{
		printf("wat er in de char array staat is %c\n",array[i]);
	}
	return 0;
}
