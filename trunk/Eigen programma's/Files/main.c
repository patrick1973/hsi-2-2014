#include <stdio.h>


int main(void)
{
    FILE *fp;
    int high = 3999;
    int low = 3000;
    int getallenReeks[1000];
	int i =0;
	int j=0;
	char buffer[20];

    fp = fopen("testInts.txt", "w+");

    fprintf(fp,"Integers printen door Patrick\n");
	for (i = high; i>=low;i--)
	{
		getallenReeks[j] = i;
		fprintf(fp,"%d\n",getallenReeks[j]); // met fprintf kan je rechtreeks in de filepointer printen.
		j++;
	}

    fseek(fp,40,SEEK_SET);
    fread(buffer,8,sizeof(getallenReeks[0]) ,fp);
	printf("resultaat is %s\n",buffer);
	fclose(fp);
	return 0;
}


