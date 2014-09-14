#include <stdlib.h>
#include "integer_file.h"

void create_file(char* filename, int high, int low)
/* pre : filename contains a valid c string
 * post: a new file is created with name filename. The file contains integers,
 *       starting from high and counting down to low.
 *       thus create_file("test.txt", 3999, 3000) will result in a text file that contains 1000 integers
 *       starting at 3999 and counting down to 3000
 */
{
    // TODO: implement
	int getallenReeks[1000];  	// maak een lege array aan van 1001 elementen
	FILE *fp =NULL;					// maak een nieuwe file ponter aan
	int indexer_i=0;
	int indexer_K=0;
	
	fp = fopen(filename, "w");
	if ((high - low) < 1000)
	{
		if (fp == NULL)
		{
			printf("Error opening or creating file\n");
		}
		else
		{
			for (indexer_i = high; indexer_i>=low;indexer_i--)
			{	
				getallenReeks[indexer_K]=indexer_i;
				fprintf(fp,"%d\n",getallenReeks[indexer_K]);
				indexer_K++;
			}
			fclose(fp);
		}
	}
}

void delete_file(char* filename)
/* pre : filename contains a valid c string
 * post: file is removed from disk
 */
{
    // TODO: implement
	int status=	remove(filename);
	if (status != 0 )
	{
		printf("delete failed\n");
	}
}

int read_value(FILE* fileptr, int pos)
/* pre : -
 * post: the value on position pos is read from the correct location in the already opened file
 *       if fileptr is NULL, -1 is returned.
 */
{
	// TODO: implement
	// let op pos is regel nummer in het bestand dus niet de pointer positie.
	// elke regel is 6 bytes. 4 bytes voor het getal + \n en \r
	
	char buffer[6];
	int lineNummerInBytes = (pos-1)* sizeof(buffer); // reken de pos uit het test programma om naar wekelijke pos in de file
		
	if (fileptr == NULL)
	{
		return -1;
	}
	else
	{
		fseek(fileptr,lineNummerInBytes,SEEK_SET);		/* zet de file pointer op positie gerekend van af het begin van de file */
	
		fread(&buffer,sizeof(char),6,fileptr);
		//printf("\n\n\nWat zit er in de buffer? %c%c%c%c\t regelnummer: %d \n\n\n\n",buffer[0],buffer[1],buffer[2],buffer[3],pos);
		int uitkomst = atoi(buffer);
		
		return uitkomst;
		
	}
}
