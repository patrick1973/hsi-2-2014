#include <stdio.h>


int getallenReeks[] = {10,11,12,13,14,15,16,17,18,19,110,111,112,113,114,115,116,117,118,119};		// defineer een array.
int i = 0; // indexer voor achteruit tellen
int j = 0; // indexer voor vooruit tellen.
int *pointer = NULL;

int main(void)
{
	int aantalElementen = sizeof(getallenReeks)/sizeof(getallenReeks[0]);		// bepaal hoeveel elementen er in de array zitten. deel de grote van de totale array door de grote van 1 element
	
	// laat de pointer naar het laatste element van de array wijzen.totaal aantal element is 20 maar laatste element is 19 daarom -1
	pointer = &getallenReeks[aantalElementen-1];
	printf("\n\neerst orginele reeks\n ");
	for(j=0; j<aantalElementen;j++)
	{
		printf("%d ",getallenReeks[j]);	// print de prginele getallen reeks
	}
	printf("\n\n");
	printf("Nu de omgekeerde reeks\n");
	
	for (i=0; i<aantalElementen; i++)	// maak een for loop met het aantal elementen.
	{
		printf("%d ",*pointer);			// print de inhoud van de variable waar de pointer naar toe wijst.
		pointer--;						// doordat de pointer en de array van het zelfde type zijn kan dit. tel achtrer uit. dus print van laatste naar eerste
	}
	printf("\n\n");
	return 0;
}
