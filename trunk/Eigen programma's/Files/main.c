#include <stdio.h>


int main(void)
{
    FILE *fp;
    int high = 3999;
    int low = 3000;
    int getallenReeks[1000];
	int i =0;
	int j=0;

    fp = fopen("testInts.txt", "w");

    fprintf(fp,"Integers printen door Patrick\n");
	for (i = low; i<=high;i++)
	{
		getallenReeks[j] = i;
		fprintf(fp,"%d\n",getallenReeks[j]); // met fprintf kan je rechtreeks in de filepointer printen.
		j++;
	}
	fclose(fp);
	return 0;
}
