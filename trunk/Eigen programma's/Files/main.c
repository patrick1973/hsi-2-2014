#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    int high = 3999;
    int low = 3000;
    int getallenReeks[1000];
	int i =0;
	int j=0;

    fp = fopen("testInts.txt", "w");

	for (i = low; i<=high;i++)
	{
		getallenReeks[j] = i;
		fprintf(fp,"%d\n",getallenReeks[j]); // met fprintf kan je rechtreeks in de filepointer printen.
		j++;
	}
	fclose(fp);
	return 0;
}
