#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>


#include "file.h"
#include "resource_detector.h"


/*
 * Normally I'd make ReadElement() and WriteElement() static, as they are only needed
 * inside this file and exposing them to the outside world is a risk.
 * For this exercise I've decided to make these functions public, so they can be properly
 * tested using unit tests. So you can make sure these functions are properly implemented
 */
int ReadElement(FILE* FilePtr, int ElementNr, STUDENT* StudentPtr)
{
	int Result = 0;
	STUDENT student = {0, "", 0}; 
	
	// TODO: implement
	//controleer of de file pointers NULL is. zo ja dan retourneer -1;
	if (FilePtr != NULL && StudentPtr != NULL)
	{
		{	
			rewind(FilePtr);
			//door loop het bestand. fseek berekend iedere keer de nieuwe posite vanaf start.
			fseek(FilePtr,(ElementNr*sizeof(STUDENT)),SEEK_SET);
			if (fread(&student,sizeof(STUDENT),1,FilePtr)!=0) // lees elke keer 1 record in. indien fread 0 retourneerd is er geen data meer.
			{
				*StudentPtr = student; // update pointer pas als er iets gevonden is.
				Result = 1;
			}
			else
			{
				Result = 0;
			}
		}
	}		
	else
	{
		Result = -1;
	}
	return Result;
}

int WriteElement(FILE* FilePtr, int ElementNr, const STUDENT* StudentPtr)
// vervang bestaande student
{
    int Result = 0;

    // TODO: implement

	if (FilePtr != NULL && StudentPtr != NULL)
	{
            fseek(FilePtr,ElementNr*sizeof(STUDENT),SEEK_SET);
            fwrite(StudentPtr,1,sizeof(STUDENT),FilePtr);
            Result = 0; 
    }
	else
	{
		Result = -1;
	}
    return Result;
}

int ComputeAverageStudyResults (char* FileName, double* Average)
{
	int Result = 0;

	// TODO: implement
	double sumResults=0;
	double recordCounter=0;
	STUDENT student ={0, "", 0} ;
	FILE *fp = NULL;
	fp = fopen(FileName, "rb");

	if (fp !=NULL && Average!=NULL)
	{
		while(fread(&student,sizeof(STUDENT),1,fp) !=0)
		{
			sumResults +=  student.StudyCredits;
			recordCounter++;
		}
		if (recordCounter > 0 )	// voorkom dat er door 0 gedeelt wordt.
		{
			*Average = sumResults / recordCounter;
		}
		else
		{
			*Average=0;		// indien er toch door 0 wordt gedeeld zet dan get gemiddelde op 0. (unit test)
		}
		Result = 0;
	}
	else
	{
		Result = -1;
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	return Result;
}


int
LinearSearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
	int Result = -1;
	STUDENT student = {0, "'", 0};
	int nummer=0;
	bool gevonden = false;
	
	// TODO: implement
	
	FILE *fp= NULL;
	fp = fopen(FileName, "rb");
	if (fp != NULL && StudentPtr != NULL)
	{
		while(( ReadElement(fp,nummer++,&student) ==1) && gevonden == false)
		{
			if(student.StudentNumber == Number) 
			{
				*StudentPtr = student;
				gevonden = true;
				Result = 0;
				
			}
		}
		
	}
	else
    {
        Result = -1; // error tijdens het openen
    }
	if (fp != NULL)
	{
		fclose(fp);
	}
	return Result;
}

int
BinarySearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
	int Result = -1;
	int totalElements =0;
	int first=0, last=0, middel;
	bool succes = false;
	STUDENT student = { 0, "" , };

	// TODO: implement
	FILE *fp = NULL;
	fp = fopen(FileName, "rb" );
	if (fp !=NULL && StudentPtr != NULL)
	{
		fseek(fp,0,SEEK_END);									// zet de file pointer naar het einde van de file
		totalElements = ftell(fp)/sizeof(STUDENT);		// bepaal hoeveel elementen (studenten) er in de file staan.
		last = totalElements;	               			     		// last bevat de positie van het laatste element.
		middel = ((last - first) / 2);								// dus bij oneven getallen naar beneden. 7- 1 / 2 = 3
		rewind(fp);                                 					// filepointer terug naar het begin
		while(first <= last && succes==false)
		{
			fseek(fp, ((middel-1)*sizeof(STUDENT)),SEEK_SET); // zet de file pointer naar het middelste element.
			fread(&student,sizeof(STUDENT),1,fp);		
			
			if (  student.StudentNumber < Number )    		
			{
				first = middel + 1;	
			}
			else if (student.StudentNumber > Number)
			{
				last = middel - 1;
			}
			else
			{
				//* for debug*/  printf("Gevonden\n");
				*StudentPtr = student;
				Result = 0;
				succes = true;
			}
			middel = first + ((last - first) / 2);	
			
		}
	}
	
	if (fp != NULL)
	{
		fclose(fp);
	}
	return Result;
}

int
AddStudentSortedToFile (char* FileName, STUDENT* StudentPtr)
{
	int Result = 0;
	// TODO: implement
	STUDENT tijdelijkeStruct = {0, "", 0} ;    	 // maak een tijdelijk struct aan om te kunnen vergeljken
	int gevonden = 99;
	FILE *fp=NULL;
	fp = fopen(FileName, "rb");                		 // open de file in read mode. Dit is alleen om te kijken of het lukt. want de liniar search retourneerd -1 bij error en niet gevonden
	if (fp != NULL && StudentPtr != NULL)     // indien het mogelijk is om de file te openen
	{
		fclose(fp);                             			// sluit de file weer, liniair search heeft zijn eigen close
		gevonden = LinearSearchStudentsFile(FileName,StudentPtr->StudentNumber, &tijdelijkeStruct);
	}
	else
	{
		Result =-1; // error
	}
	if ((gevonden==-1) || (gevonden == 99))
	{
		fp = fopen(FileName, "ab");
		if (fp != NULL && StudentPtr != NULL)
		{
			fwrite(StudentPtr,1,sizeof(STUDENT),fp);
			Result =1;
		}
		else
		{
			Result = -1;
		}
		// Sorteer de file
		sort();
	}
	else if (gevonden == 0)
	{
		Result = 0;
		//fclose(fp);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	return Result;
}


int
RemoveStudentFromFile (char* FileName, int StudentNumber)
{
	int Result = 0;
	
	// TODO: implement
	STUDENT student = {0, "", 0} ;
	FILE *fp= NULL;				// actuele file
	
	STUDENT *DynamischeArray;

	fp = fopen(FileName, "rb"); // open 1

	// kijk hoeveel studenten er in de file zitten.		
	fseek(fp,0,SEEK_END);														// laat de file pointer naar het einde van de file wijzen
	int sizeFp = ftell(fp);															// sla de grootte op van de file
	int aantalStudentInFpBefore = sizeFp / sizeof(STUDENT);	// reken het aanal studenten uit voor het verwijderen
	rewind(fp);																		// zet de pointer terug naar het begin van de file
	
	// nu we het aantal studenten in een file weten kunnen we een dynamische array aan maken
	// met calloc worde een array gemaakt en gevult met nullen. Gevaar van malloc is dat het geheugen gebied nog info bevat.
	DynamischeArray = (STUDENT*)calloc(aantalStudentInFpBefore, (sizeof(STUDENT)));
	
	if (fp != NULL)
	{
		int remainingStudentCounter=0;
		fread(&student,sizeof(STUDENT),1,fp);
		while(!feof(fp))
		{
			if (student.StudentNumber != StudentNumber && student.StudentNumber != 0)
			{ 
				DynamischeArray[remainingStudentCounter] = student;	
				remainingStudentCounter++;
			}
			fread(&student,sizeof(STUDENT),1,fp);
		}
		
		fclose(fp); //close 1
		// nu de array gevuld is met de nieuwe gegevens en er zijn studenten verwijderd is de array dus kleine geworden.
		// de array kan nu dus opnieuw worden ingesteld.
		DynamischeArray = (STUDENT*)realloc(DynamischeArray,  (remainingStudentCounter*sizeof(STUDENT)));
		
		//!!!!!!!size of werkt niet met een calloc gecreeerde array!!!!!!!!
		//aantalStudentInFpAfter = sizeof(DynamischeArray) / sizeof(DynamischeArray[0]);		// reken het aanal studenten uit
		fp = fopen(FileName, "wb"); // open 2
	
		// schrijf de gegevens uit de dynamische array naar de file.
		int k;
		for(k=0; k<(remainingStudentCounter);k++)
		{
			fwrite(&DynamischeArray[k],sizeof(STUDENT),1,fp);
		}
		free(DynamischeArray);
		fclose(fp); //close 2
		
		// indien de aantal elementen in de dynamische array gelijk zijn aan het aantal gevonden studenten in file, dan is er niets verwijderd
		if ( remainingStudentCounter == aantalStudentInFpBefore) 
		{
			Result = -1;
		}
		else		// verschilt ze wel dan is er een student verwijderd
		{
			Result = 0;
		}
	}
	else
	{
		Result = -1;
	}
	
	// indien ik het dynamische gebied will leeg maken komt er een error dat het al leeg is
	//	free(DynamischeArray);

	//printf ("Error free memory: %s\n",strerror(errno));

	 
	return Result;
}

void sort()
/* Bubble sort
	*   lees de eerste 2 records
	*   draai ze om indien nodig zodat de kleinste links staat.
	*   indien aan het einde dan staat het hoogste getal helemaal rechts.
	*   zet de limit er een terug en herhaal het process
	*   https://www.youtube.com/watch?v=JP5KkzdUEYI
	*/
{
	int StructureSize, Idx1, Idx2;                      // hulp variable
	FILE * binaryFilePointer;                           // file pointer naar het bestand
	binaryFilePointer = fopen("students.dat","rb+");    // open het bestand voor lezen en schrijven
	STUDENT Index, IndexTemp;                           // maak tijdelijke structs aan
	StructureSize = sizeof(Index);                      // leg vast hoe groot de struct is (bytes)
	fseek(binaryFilePointer, 0, SEEK_END);              // zet de file pointer naar het einde van de file
	int fileSize = ftell(binaryFilePointer);            // leg vast hoe groot de file is
	rewind(binaryFilePointer);                          // en zet de file pointer terug naar het begin van de file

	if (binaryFilePointer != NULL)
	{

		for (Idx1 = 0; Idx1 < fileSize; Idx1 += StructureSize) // limit bij houden.
		{
			for (Idx2 = 0; Idx2 < fileSize - StructureSize; Idx2 += StructureSize)
			{
				fread(&Index, StructureSize, 1, binaryFilePointer);
				fread(&IndexTemp, StructureSize, 1, binaryFilePointer);

				if (Index.StudentNumber > IndexTemp.StudentNumber) // indien het getal moet draaien
				{
					fseek(binaryFilePointer, -(StructureSize * 2), SEEK_CUR); // pointer 2 elementen terug van huidig pos
					fwrite(&IndexTemp, StructureSize, 1, binaryFilePointer);
					fwrite(&Index, StructureSize, 1, binaryFilePointer);
					fseek(binaryFilePointer, -StructureSize, SEEK_CUR);
				}
				else   // anders schrijf het gewoon weg.
				{
					fseek(binaryFilePointer, -StructureSize, SEEK_CUR);
				}
			}
			rewind(binaryFilePointer); // ga terug naar het begin van de file.
		}
	}
	else
	{
		printf("er is iets mis met de file pointer\n");
	}
	fclose(binaryFilePointer);
}




