#include <stdio.h>

void functie(int inputA, int inputB, int *sum, int *product);

main()
{
	int getalA = 5;
	int getalB = 3;
	int som;
	int product;
	
	functie(getalA,getalB,&som,&product);
	
	printf("Getal a=%d Getal b=%d som=%d product=%d\n",getalA,getalB,som,product);  
}

void functie(int inputA, int inputB, int *sum, int *product)
{
	*sum = inputA + inputB;
	*product = inputA * inputB;	
}
