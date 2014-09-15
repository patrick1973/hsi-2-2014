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
	// waarom wordt het eerste element nooit gevonden
	FILE *fp= NULL;
	fp = fopen(FileName, "rb");
	if (!fp)
	{
		Result = -1; // error tijdens het openen
	}
	else
	{
		//fread(StudentPtr,sizeof(STUDENT),1,fp);
		do
		{
			if (StudentPtr->StudentNumber != Number)
			{
				printf("Niet gevonden\n");
				Result = -1;
			}
			else
			{
				printf("Gevonden\n");
				Result = 0;
				fclose(fp);
				return Result;
			}
			fread(StudentPtr,sizeof(STUDENT),1,fp);
		} while(!feof(fp));
	}
	fclose(fp);
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
    // voeg het nieuwe record toe
    // nog maken dat de ingevoerde gegevens nog gecontroleerd wordt of het nummer al voor komt in de file
	FILE *fp=NULL;
	fp = fopen(FileName, "ab");
	fwrite(StudentPtr,1,sizeof(STUDENT),fp);
	fclose(fp);


    // Sorteer de file
    sort();
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
void sort()
    /* Bubbler sort
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

    for (Idx1 = 0; Idx1 < fileSize; Idx1 += StructureSize) // limit bij houden.
    {
        for (Idx2 = 0; Idx2 < fileSize - StructureSize; Idx2 += StructureSize)
        {
            fread(&Index, StructureSize, 1, binaryFilePointer);
            fread(&IndexTemp, StructureSize, 1, binaryFilePointer);

            if (Index.StudentNumber > IndexTemp.StudentNumber)
            {
                fseek(binaryFilePointer, -(StructureSize * 2), SEEK_CUR); // pointer 2 elementen terug van huidig pos
                fwrite(&IndexTemp, StructureSize, 1, binaryFilePointer);
                fwrite(&Index, StructureSize, 1, binaryFilePointer);
                fseek(binaryFilePointer, -StructureSize, SEEK_CUR);
            }
             else
            {
                fseek(binaryFilePointer, -StructureSize, SEEK_CUR);
            }
        }
        rewind(binaryFilePointer);
    }
    fclose(binaryFilePointer);
}




