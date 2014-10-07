#include "stringcalc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int Add(char* numbers)
{
    int Sum = 0;
    bool invalidNumber = false;
    int leftValue=0,rightValue=0,counter;
    char eersteNummer[20] = {0};
    char tweedeNummer[20] = {0};
    char *pointerLeftValue = &eersteNummer[0];
    char *pointerRightValue = &tweedeNummer[0];


    // bepaal het linker nummer, lees zolang je nummers ziet
    while ((*numbers > 0x2f) && (*numbers < 0x3a) && (*numbers != '\0'))
    {
        *pointerLeftValue++ = *numbers++;
    }

    // check niet nummers
    while ((*numbers <0x30 || (*numbers > 0x39)) && (*numbers != '\0'))
    {
         numbers++;
    }


    // bepaal het rechter getal;
    while (*numbers != '\0')
    {
        *pointerRightValue++ = *numbers++;
    }

    // zet de strings om naar ints en tel alles bij elkaar op.
    leftValue = atoi(eersteNummer);
    rightValue= atoi(tweedeNummer);

    for (counter = 1001; counter <= 1111; counter++)
    {
        if ((leftValue == counter) || (rightValue == counter) || (leftValue <0) || (rightValue <0))
        {
            invalidNumber = true;
            Sum = -99;
        }
    }
    // controleer of het getal negatief is uitgaande dat 0 positief is.
    if ((leftValue >=0) && (rightValue >=0) && (invalidNumber == false))
    {
        Sum = leftValue + rightValue;
    }

    return Sum;
}
