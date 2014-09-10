#include <stdio.h>

// cat: koppel files versie 1
main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE*,FILE*);
	
	if (argc==1) // geen args; kopieer standaard invoer
	{
		filecopy(stdin, stdout);
	}
	else
	{
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL)
			{
				printf("cat:niet te openen %s\n",*argv);
				return 1;
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
	}
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
