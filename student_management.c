#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float attendance;
};
struct Student students[100];
int n = 0;

// For Add Student
void addStudent()
{
    printf("Enter Name: ");
    scanf(" %[^\n]", students[n].name);

    printf("Enter Roll Number: ");
    scanf("%d", &students[n].roll);

    printf("Enter Attendance: ");
    scanf("%f", &students[n].attendance);

    n++;

    printf("Student added successfully!\n");
};

// For Display Students
void displayStudents()
{
    int i;

    if (n == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }
    printf("=======================");
    printf("\n   STUDENT RECORD  \n");
    printf("=======================");    
    for (i = 0; i < n; i++)
    {
       printf("\nName: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Attendance : %.2f%%\n", students[i].attendance);
    }
}

// For Search Student
void searchStudent()
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++)
    {
        if (students[i].roll == roll)
        {
            printf("\nStudent Found!\n");
           printf("\nName: %s\n", students[i].name);
            printf("Roll Number : %d\n", students[i].roll);
            printf("Attendance  : %.2f%%\n", students[i].attendance);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

// ForDelete Student
void deleteStudent()
{
    int roll, i, j;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++)
    {
        if (students[i].roll == roll)
        {
            for (j = i; j < n - 1; j++)
            {
                students[j] = students[j + 1];
            }

            n--;

            printf("\nStudent deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found.\n");
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("     STUDENT ATTENDANCE SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
} 