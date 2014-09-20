#include <stdio.h>

typedef struct
{
    int     StudentNumber;
    char    Surname[25];
    int     StudyCredits;
} STUDENT;

void pointer ( FILE *fp, STUDENT *st )
{
	rewind(fp);
	st->StudentNumber=5;
}
int main(void)
{
	STUDENT st;
	FILE *fp=NULL;
	
	fp= fopen("patrick.txt", "w");
	pointer(fp,&st);
	printf("studentnummer is %d",st.StudentNumber);
	fclose(fp);
}