#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int     StudentNumber;
    char    Surname[25];
    int     StudyCredits;
} STUDENT;

void test(STUDENT *student)
{
    student->StudentNumber = 20;

}
int main()
{
    STUDENT st;
    test(&st);
    printf("Groote van de sturct is %d\n",st.StudentNumber);
    return 0;
}
