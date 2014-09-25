#include <stdio.h>
#include <stdlib.h>

void print (int lijstGetallen[],int lengte, int *terug)
{
    *terug = 0;
    int index = 0;
    for (index=0; index < lengte;index++)
    {
        printf("Waarde element %d = %d\n", index, lijstGetallen[index]);
        *terug = index;
    }
}
void printptr(void *drukaf(int[],int, int) )
{

}


int main(void)
{
    int     lijst[] = {13, 14, 6, 7, 10, 22, 1, 4};
    int     lengte = sizeof(lijst)/sizeof(lijst[0]);
    int     terug = 0;

    char    array[] = {13, 12, 6, 7, 10, 22, 1, 4};
    int     i = 0;
    int     k = 8;
    char    *p = &(array[4]);
    char    **q = &p;

    printf("Opgaven 1 \n\n");
    printf("Het adres van pointer P is %d en de waarde die in P staat is %d\n",p,*p);
    (*p)++;
    printf("na uit voeren van (*p)++; -->Het adres van pointer P is %d en de waarde die in P staat is %d\n",p,*p);
    i = sizeof(array);

    printf(" i = sizeof(array) het gevolg van deze instructie is dat de vrote van array wordt geprintgroote is %d\n", i);

    (*q)++;
    k = *p;

    printf("na uit voeren van (*q)++; -->Het adres van pointer q is %d en de waarde die in k staat is %d\n",q,k);

    printf("Opgaven 2 \n\n");
    printptr(print(lijst,lengte,&terug));


    void (*printptr)(int*,int, int*);
    printptr = print;
    printptr(lijst,lengte,&terug);

    return  0;
}

