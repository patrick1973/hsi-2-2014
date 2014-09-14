#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "integer_file.h"

#define MY_FILE "integer_file.txt"

static bool WithMenu = true;
static int GetInt (const char* Message)
{
    char    Line[80];
    int     Value;

    if (WithMenu == true)
    {
        printf ("%s", Message);
    }
    if (fgets (Line, sizeof(Line), stdin) == NULL)
    {
        fprintf (stderr, "ERROR in fgets()\n");
    }
    sscanf (Line, "%d", &Value);

    return Value;
}
int main(int argc, char** argv)
{
    // TODO: implement
	 int     Choice = 0;
	 bool   Quit = false;
	 char bestandNaam[80];
	 int Value1=0;
	 int Value2=0;
	 FILE *fileptr = NULL;
	 
	 while(!Quit)
	 {
		if(WithMenu)
		{
		          printf ("\nMENU\n"
                "===========================\n"
                "[0] print welcome message\n"
                "[1] create file\n"
                "[2] Delete file\n"
				"[3] Search at pos\n"
				"[9] quit\n");
		}
		Choice = GetInt("choice: ");
		switch(Choice)
		{
			case 0:
						printf("Welcome at My file stuff\n");
						break;
			case 1:
						printf("geef een bestands naam : ");
						fgets(bestandNaam, sizeof(bestandNaam), stdin);
						Value1 = GetInt("Geef waarde voor min waarde: ");
						Value2 = GetInt("Geef waarde voor max waarde: ");
						create_file(bestandNaam, Value2, Value1);
						break;
			case 2:
						delete_file(bestandNaam);
						break;
			case 3:
						printf("geef een bestands naam : ");
						Value1 = GetInt("Geef waarde voor regelnummer: ");
						fgets(bestandNaam, sizeof(bestandNaam), stdin);
						fileptr = fopen(bestandNaam, "r");
						printf("Waarde is: %d\n",read_value(fileptr, Value1));
			case 9:
						Quit = true;
						break;
			default:
					printf ("invalid choice: %d\n", Choice);
		}			break;			
	}

    return 0;
}
