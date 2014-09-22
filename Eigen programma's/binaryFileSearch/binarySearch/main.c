#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
    int     StudentNumber;
    char    Surname[25];
    int     StudyCredits;
} STUDENT;

int BinarySearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
    int Result = 0;
	int totalElements =0;
	int first=0, last=0, middel;
	int gevonden =99;
	bool succes = false;


    // TODO: implement
	FILE *fp = NULL;

	fp = fopen(FileName, "rb" );
	if (fp !=NULL && StudentPtr != NULL)
	{
		fseek(fp,0,SEEK_END);						// zet de file pointer naar het einde van de file
		totalElements = ftell(fp)/sizeof(STUDENT);	// bepaal hoeveel elementen (studenten) er in de file staan.
		last = totalElements-1;	                    // last bevat de positie van het laatste element. -1 omdat we beginen te tellen vanaf 0
		middel = (last - first) / 2;				// dus bij oneven getallen naar beneden. 7- 0 / 2 = 3
		rewind(fp);                                 // filepointer terug naar het begin
		while(first <= last && succes == false)
		{
			printf("actuele positie van het midden is %d\n",middel);
			fseek(fp, middel*sizeof(STUDENT),SEEK_SET); // zet de file pointer naar het middelste element.
			fread(StudentPtr,sizeof(STUDENT),1,fp); // deze functie hoogt de file pointer 1 op na het lezen. daar om moet in onderstaande regel -1 staan.
			printf("actuele positie van de file pointer is %ld en daar staat studentnummer: %d nummer wat we zoeken is %d\n",(ftell(fp)/sizeof(STUDENT)-1),StudentPtr->StudentNumber, Number);
			if ( Number < StudentPtr->StudentNumber) // als het gezochte nummer kleiner is dan het gevonde midde nummer
			{
			    printf("Te zoeken nummer dit in het linkerdeel \n");
				gevonden = 1;
				last = middel -1; //het huidige midden is algecontroleerd dus last wordt 1 lager
				middel = (last - first) / 2;
				printf(" last = %d, first = %d het nieuwe midden is : %d\n",last,first,middel);
				succes = false;
			}
			else if (Number > StudentPtr->StudentNumber )
            {
                printf("Te zoeken nummer dit in het rechter deel \n");
				gevonden = -1;
				last = totalElements-1;
				first = middel +1;
				middel = ((last-first)/2)+(ftell(fp)/sizeof(STUDENT));
				printf(" last = %d, first = %d het nieuwe midden is : %d\n",last,first,middel);
				succes = false;
			}
			else
            {
                printf("Gevonden\n");
				gevonden = 0;
				succes = true;
			}
			getchar();  // tijdelijk voor de test "press enter"
		}

	}
    return Result;
}


int main()
{
    STUDENT student;
    BinarySearchStudentsFile ("students.dat", 10, &student);
    return 0;
}
