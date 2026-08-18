#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
    char mobileNumber[15];
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudentRecord()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("Maximum student records reached!\n");
        return;
    }

    printf("Adding a new student record...\n");
    printf("Enter student name: ");
    scanf("%s", students[studentCount].name);
    printf("Enter student roll number: ");
    scanf("%d", &students[studentCount].rollNumber);
    printf("Enter student marks: ");
    scanf("%f", &students[studentCount].marks);
    printf("Enter student mobile number: ");
    scanf("%s", students[studentCount].mobileNumber);

    studentCount++;
    printf("Student record added successfully!\n");
}

void searchStudentRecord(int choice)
{
    if (studentCount == 0)
    {
        printf("No students in the system!\n");
        return;
    }

    int found = 0;

    switch (choice)
    {
    case 1:
    {
        printf("Enter name to search: ");
        char searchName[50];
        scanf("%s", searchName);
        printf("Searching by name...\n");
        for (int i = 0; i < studentCount; i++)
        {
            if (strcmp(students[i].name, searchName) == 0)
            {
                printf("Found: Roll: %d, Name: %s, Marks: %.2f, Mobile: %s\n",
                       students[i].rollNumber, students[i].name,
                       students[i].marks, students[i].mobileNumber);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    case 2:
    {
        printf("Enter roll number to search: ");
        int searchRoll;
        scanf("%d", &searchRoll);
        printf("Searching by Roll Number...\n");
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].rollNumber == searchRoll)
            {
                printf("Found: Roll: %d, Name: %s, Marks: %.2f, Mobile: %s\n",
                       students[i].rollNumber, students[i].name,
                       students[i].marks, students[i].mobileNumber);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    case 3:
    {
        printf("Enter marks to search: ");
        float searchMarks;
        scanf("%f", &searchMarks);
        printf("Searching by Marks...\n");
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].marks == searchMarks)
            {
                printf("Found: Roll: %d, Name: %s, Marks: %.2f, Mobile: %s\n",
                       students[i].rollNumber, students[i].name,
                       students[i].marks, students[i].mobileNumber);
                found = 1;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    case 4:
    {
        printf("Enter mobile number to search: ");
        char searchMobile[15];
        scanf("%s", searchMobile);
        printf("Searching by Mobile Number...\n");
        for (int i = 0; i < studentCount; i++)
        {
            if (strcmp(students[i].mobileNumber, searchMobile) == 0)
            {
                printf("Found: Roll: %d, Name: %s, Marks: %.2f, Mobile: %s\n",
                       students[i].rollNumber, students[i].name,
                       students[i].marks, students[i].mobileNumber);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("Student not found!\n");
        break;
    }
    default:
        printf("Invalid search choice!\n");
    }
}

void editStudentRecord()
{
    if (studentCount == 0)
    {
        printf("\nNo students in the system!\n");
        return;
    }

    printf("        ALL STUDENTS INFORMATION        \n");

    printf("%-15s %-20s %-10s %-15s\n", "Roll Number", "Name", "Marks", "Mobile");
    printf("----------------------------------------\n");

    for (int i = 0; i < studentCount; i++)
    {
        printf("%-15d %-20s %-10.2f %-15s\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks,
               students[i].mobileNumber);
    }

    printf("Total Students: %d\n", studentCount);
}

void deleteStudentRecord()
{
    printf("Deleting a student record...\n");
    printf("Enter roll number of student to delete: ");
    int rollToDelete;
    scanf("%d", &rollToDelete);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNumber == rollToDelete)
        {
            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main()
{
    int choice;
    while (1)
    {

        printf("Total number of students: %d\n", studentCount);
        printf("1. Add Student Record\n");
        printf("2. Search Student Record\n");
        printf("3. View All Students\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudentRecord();
            break;
        case 2:
            printf("\nEnter method to search student record:\n");
            printf("1. Search by Name\n");
            printf("2. Search by Roll Number\n");
            printf("3. Search by Marks\n");
            printf("4. Search by Mobile Number\n");
            printf("Enter your choice: ");
            int searchChoice;
            if (scanf("%d", &searchChoice) != 1)
            {
                printf("Invalid input!\n");
                clearInputBuffer();
                break;
            }
            clearInputBuffer();
            searchStudentRecord(searchChoice);
            break;
        case 3:
            editStudentRecord();
            break;
        case 4:
            deleteStudentRecord();
            break;
        case 5:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}