#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int     StudentNumber;
    char    Surname[25];
    int     StudyCredits;
} STUDENT;

int ReadElement(FILE* FilePtr, int ElementNr, STUDENT* StudentPtr);

int main()
{
    FILE *fp = NULL;                    //maak de file pointer aan.
    STUDENT st;

    char ch;                            //defineer variable ch
    fp = fopen("Patrick.txt" , "w");    // open een bestand in write mode
    while (( ch=getchar()) != EOF)       // leef van het toetsen board zolang EOF niet bereikt is (EOF = ^z)
    {
        fputc(ch,fp);                   // wat je ingetypt hebt gelijkt in de file stoppen
    }

    printf("Total characters = %ld",ftell(fp)); // print de positie van de filepointer op dit moment.
    fclose(fp);

    fp = fopen("Patrick.txt" , "r");    // open een bestand in read mode in de buffer
    int resultaat = ReadElement(fp,0,&st);
    printf("%d",resultaat);

//    fseek(fp,5,SEEK_SET); // zoek in fp van begin positie byte 5L dus eigenlijk van links naar rechts \n\r ook mee tellen
//    //fseek(fp,-5L,SEEK_END);// zoek in fp van end positie 5 bytes naar links
//    printf("\n\nthe location at FP = %c\n",getc(fp));
//    rewind(fp); // ga terug naar de begin positie.
//    printf("\n\nthe location at FP = %c\n",getc(fp));
//    fclose(fp);

    return 0;
}

int ReadElement(FILE* FilePtr, int ElementNr, STUDENT* StudentPtr)
{
    int Result = 0;

	// TODO: implement
	//controleer of de file pointers NULL is. zo ja dan retourneer -1;
	if (FilePtr == NULL)
	{
		Result =  -1;
	}
	else
	{
		rewind(FilePtr);
		fseek(FilePtr,ElementNr,SEEK_SET);
		// fread(StudentPtr,sizeof(STUDENT),1,FilePtr);
		// if (StudentPtr->StudentNumber==0)
		// {
		// return 1;
		// }
		// else
		// {
		Result = 0;
	}

	return Result;
}
