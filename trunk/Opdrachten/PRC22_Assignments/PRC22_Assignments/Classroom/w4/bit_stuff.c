#include <limits.h>
#include "bit_stuff.h"

#define BITS_PER_BYTE 8
#define NR_BITS_IN_TYPE(type) (BITS_PER_BYTE * sizeof(type))

unsigned int MakeBitmask(unsigned int width, unsigned int shift)
/* pre : -
 * post: a bitmask with a given width and a given shift is generated (so w=5 and s=1 gives 00111110)
 */
{
    // TODO: implement
    unsigned int mask = 0xffffffff;                             //zet het masker op allemaal 1
    unsigned int temp = 0;

    if (width > 0 )                                             //als er geen bits gevraagd wordt hoe je ook niets te doen.
    {
        temp = mask >>( NR_BITS_IN_TYPE(unsigned int)-width);   //schuif naar rechts alle eenen - het gewenste aantal
        return temp<< shift;                                    //verschuif het gevraagde aantal.
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
    //methode 1
    int i=0;
    int oneCounter=0;
    unsigned int shift;
    for (i=NR_BITS_IN_TYPE(unsigned int);i>0;i--)
    {
        shift =  value>> i;
        if (shift &1)
        {
            oneCounter++;
        }
    }
    return oneCounter;
}
