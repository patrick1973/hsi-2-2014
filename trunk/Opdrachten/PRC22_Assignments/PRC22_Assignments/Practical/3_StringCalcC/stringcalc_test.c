/* auteur : F.J. Hurkmans
 * datum  : November 4th 2013
 * code   : Ansi C
 * versie : 1
 */

#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "stringcalc.h"
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

static void test_NoValue(void)
{
    TEST_ASSERT_EQUAL(0,Add(""));
}

static void test_Normalvalues(void)
{
    TEST_ASSERT_EQUAL(3, Add("1,2"));
}
static void test_Singlevalues(void)
{
     TEST_ASSERT_EQUAL(7, Add("7"));
}
static void test_Negativevalues(void)
{
    //TEST_ASSERT_EQUAL(-99, Add("6--4")); // om een negtief nummer te detecteren als - ook een scheidings teken is.
}

static void test_betweenValues(void)
{
    int value;
    char getal1[5] = {0};
    char getal2[5] = {0};
    // check voor alle getallen uit de test lijst
    for ( value = 1001; value <=1111; value++)
    {
         sprintf(getal1,"%d",value);            // converteer de int naar een string
         sprintf(getal2,"%d",value);

         strcat(getal1,",");                    // plak de comma er achter
         strcat(getal1,getal2);                 // plak het zelfde getal er nog eens achter.
         TEST_ASSERT_EQUAL(-99, Add(getal1));   // en kijk of het nieuw gevormde getal -99 terug geeft. getal1 is hier bijv. "1001,1001"
         TEST_ASSERT_EQUAL(-99,Add(getal2));    // controleer of een enkel getal ook het zelfde resultaat heeft.

    }
    // check nog even de uiterste
    TEST_ASSERT_EQUAL(-99, Add("1001,1111"));
}

static void test_strangeSeparatorChars(void)
{
    TEST_ASSERT_EQUAL(3, Add("1#2"));
    TEST_ASSERT_EQUAL(3, Add("1&2"));
    TEST_ASSERT_EQUAL(3, Add("1~2"));
}

static void test_severalStrangeSeparatorChars(void)
{
    TEST_ASSERT_EQUAL(3, Add("1#$$2"));
    TEST_ASSERT_EQUAL(3, Add("1&@%2"));
    TEST_ASSERT_EQUAL(3, Add("1~^(2"));
    TEST_ASSERT_EQUAL(10,Add("5plus5"));

}
int main (int argc, char * argv[])
{
    UnityBegin();

     MY_RUN_TEST(test_NoValue);
     MY_RUN_TEST(test_Normalvalues);
     MY_RUN_TEST(test_Singlevalues);
     MY_RUN_TEST(test_Negativevalues);
     MY_RUN_TEST(test_betweenValues);
     MY_RUN_TEST(test_strangeSeparatorChars);
     MY_RUN_TEST(test_severalStrangeSeparatorChars);

    return UnityEnd();
}
