 #include "parameter.h"
 #include <stdio.h>
 
 
 void SwapValues (int *a, int *b)
 {
	int temp=0; 
	temp = *a;
	*a = *b;
	*b = temp;	
 }
 
 void SwapAddresses(int **a, int **b)
 {
	int  *temp =NULL; // let op NULL zit in stdio.h daar om deze wel includen
	temp = *a;
	*a =  *b;
	*b  = temp;
 }
 
 int GetSumReturn(int Arr[], int n)
 {
	int temp=0;
	int i = 0;
	if ( n <= 0 )
	{
		return 0;
	}
	else
	{
		for(i=0; i< n; i++)
		{
			temp += Arr[i];
		}
	return temp;
	}
 }
 
 void GetSumParameter (int *Arr,int n, int *Sum)
 {
	int temp=0;
	int i = 0;
	if ( n <= 0 )
	{
		*Sum = 0;
	}
	else
	{
		for(i=0; i< n; i++)
		{
			temp += Arr[i];
		}
	*Sum= temp;
	}
 }
 
 char *Dutch (int i)
 {
	static char *Translation [] ={"nul", "een", "twee", "drie", "vier", "vijf", "zes", "zeven", "acht", "negen", "tien"  };
	if ((i>=0) && (i<=11))
	{
		return (Translation [i]);
	}
	else
	{
		return "Geen idee";
	}
 }
 
 void Translate(char *Language(int Index),int Arr[], int n, char **Translations)
 {
	int i = 0;
	for (i= 0; i<n; i++)
	{
		Translations[i] = Language(Arr[i]);
	}
 }