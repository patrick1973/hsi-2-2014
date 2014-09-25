#include <stdio.h>
#include <stdlib.h>
#define BITS_PER_BYTE 8
#define NR_BITS_IN_TYPE(type) (BITS_PER_BYTE * sizeof(type))

unsigned int MakeBitmask(unsigned int width, unsigned int shift);
unsigned int CountOnes(unsigned int value);
void printbits(unsigned char v);

int main()
{
   printf("het resultaat is %d\n",MakeBitmask(0,0));
    // printbits(MakeBitmask(3,0));
   //  CountOnes(0x5a5a5a5a);

//    unsigned int i = 0;
//    for (i = 0; i < 32; i++)
//    {
//         printf("het resultaat is %d\n",CountOnes(MakeBitmask(i, 0)));
//    }
    return 0;
}

void printbits(unsigned char v)
 {
  int i; // for C89 compatability
  for(i = 7; i >= 0; i--) putchar('0' + ((v >> i) & 1));
}

unsigned int MakeBitmask(unsigned int width, unsigned int shift)
/* pre : -
 * post: a bitmask with a given width and a given shift is generated (so w=5 and s=1 gives 00111110)
 */
{
    unsigned int mask = 0xffffffff;
    unsigned int temp = 0;

    // TODO: implement
    if (width > 0 )
    {
        temp = mask >>( NR_BITS_IN_TYPE(unsigned int)-width);
        return temp<< shift;
    }
    else
    {
        return 0;
    }


}

unsigned int CountOnes(unsigned int value)
/* pre : -
 * post: the number of bits with value 1 is counted and returned
 */
{
    // TODO: implement
//    int i;
//    int oneCounter=0;
//
//    unsigned int shift;
//    for (i=NR_BITS_IN_TYPE(unsigned int);i>0;i--)
//    {
//        shift =  value>> i;
//        if (shift &1)
//        {
//            oneCounter++;
//        }
//    }
//    printf("Gevonden : %d",oneCounter);
//    return oneCounter;
    int oneCounter=0;
    for ( oneCounter=0; value !=0; oneCounter++)
    {
        value &= value-1;
    }
    return oneCounter;
}

