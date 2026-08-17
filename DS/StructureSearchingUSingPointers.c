#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct Students
{
    int rollNo;
    char Name[30];
};

int main()
{
    struct Students *ptr;
    int noOfStudents;
    printf("Enter the number of students: ");
    scanf("%d", &noOfStudents);

    ptr = (struct Students *)malloc(noOfStudents * sizeof(struct Students));
    for (int i = 0; i < noOfStudents; ++i)
    {
        printf("Enter Roll No. and Name.:\n");
        scanf("%d %s", &(ptr + i)->rollNo, (ptr + i)->Name);
    }

    printf("Displaying Information of students:\n");
    for (int i = 0; i < noOfStudents; ++i)
    {
        printf("%d\t%s\n", (ptr + i)->rollNo, (ptr + i)->Name);
    }

    int sno;
    unsigned char flag = 0;
    printf("Enter student Roll number to search :");
    scanf("%d", &sno);

    for (int i = 0; i < noOfStudents; i++)
    {
        if (ptr[i].rollNo == sno)
        {
            flag = 1;
            printf("FOUND!! NAME OF %d is %s", sno, (ptr + i)->Name);
            break;
        }
    }
    if (0 == flag)
    {
        printf("\nSorry !!! Record not found with student Roll number : %d\n", sno);
    }

    free(ptr);

    return 0;
}
