#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
	
	// TODO: implement
	//controleer of de file pointers NULL is. zo ja dan retourneer -1;
	if (FilePtr == NULL)
	{
		Result =  -1;
	}
	
	//door loop het bestand. fseek berekend iedere keer de neuwe posite vanaf start. 
	fseek(FilePtr,(ElementNr*sizeof(STUDENT)),SEEK_SET);
	if (fread(StudentPtr,sizeof(STUDENT),1,FilePtr)!=0) // lees elke keer 1 record in. indien fread 0 retourneerd is er geen data meer.
	{
		Result = 1;
	}
	else
	{
		Result = 0;
	}
	return Result;
}

int WriteElement(FILE* FilePtr, int ElementNr, const STUDENT* StudentPtr)
{
    int Result = 0;
    
    // TODO: implement

    return Result;
}

int
ComputeAverageStudyResults (char* FileName, double* Average)
{
	int Result = 0;

	// TODO: implement
	double sumResults=0;
	double recordCounter=0;
	STUDENT student;
	FILE *fp = NULL;
	fp = fopen(FileName, "rb");
	
	if (fp!=NULL)
	{
		while(fread(&student,sizeof(STUDENT),1,fp) !=0)
		{
			sumResults +=  student.StudyCredits;
			recordCounter++;
		}
		if (recordCounter > 0 )
		{
			*Average = sumResults / recordCounter;
			Result = 0;
		}
		else
		{
			Result = -1; // error if division by 0;
		}
	}
	else
	{
		Result = -1;
	}
	
	return Result;
}


int
LinearSearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
	int Result = 0;

	// TODO: implement
	// waar om kan ik student met nummer 1 niet vinden.
	FILE *fp= NULL;
	fp = fopen(FileName, "rb");
	if (fp != NULL)
	{
		while((fread(StudentPtr,sizeof(STUDENT),1,fp)) !=0)
		{
			if(StudentPtr->StudentNumber == Number)
			{
				Result = 0;	// nummer gevonden
			}
			else
			{
				Result = -1;	// nummer niet gevonden
			}
		}
	}
	else 
	{
		Result = -1;
	}
	return Result;
}

int
BinarySearchStudentsFile (char* FileName, int Number, STUDENT* StudentPtr)
{
    int Result = 0;

    // TODO: implement
    
    return Result;
}

int 
AddStudentSortedToFile (char* FileName, STUDENT* StudentPtr)
{
    int Result = 0;

    // TODO: implement
	FILE *fp=NULL;
	fp = fopen(FileName, "ab");
	fwrite(StudentPtr,1,sizeof(STUDENT),fp);
	fclose(fp);
    
    return Result;
}


int
RemoveStudentFromFile (char* FileName, int StudentNumber)
{
	int Result = 0;

	// TODO: implement
	//kijk welke nummers niet overeen komen en sla die op in een appart bestand.
	//zo filter je dus het record dat je wilt verwijderen er uit.
	//gooi het orginele bestand weg en hernoem het tijdelijke bestand naar het actuele bestand.
	STUDENT student = {0, "", 0} ;
	FILE *fp= NULL;				// actuele file
	FILE *fpTemp = NULL;		// tijdelijke file
	
	fp = fopen(FileName, "rb");
	fpTemp = fopen("tijdelijke.dat" , "wb");
	
	if (fp != NULL)
	{
		fread(&student,sizeof(STUDENT),1,fp);
		while(!feof(fp))
		{
			if (student.StudentNumber != StudentNumber)
			{
				fwrite(&student,1,sizeof(STUDENT),fpTemp);
			}
			fread(&student,sizeof(STUDENT),1,fp);
		}
		
	}
	
	int sizeFp = ftell(fp);
	int sizeFpTemp = ftell(fpTemp);
	
	printf("size fp %d\n",sizeFp);
	printf("size fpTemp %d\n",sizeFpTemp);	
	
	fclose(fp);
	fclose(fpTemp);
	
	remove("students.dat");
	rename("tijdelijke.dat","students.dat");
	
	if ( sizeFp == sizeFpTemp) // als de grote van beide bestanden gelijk zijn is er dus niets gewijzigd, waarschijnlijk onbekend nummer
	{
		Result = -1;
	}
	else		// verschilt de grote wel dan is er een record verwijderd.
	{
		Result = 0;
	}
	return Result;
}

