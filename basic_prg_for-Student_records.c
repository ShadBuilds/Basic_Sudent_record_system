#include <stdio.h>
#include <string.h>
#define m 100
struct student
{
    int roll;
    char dob[100];
    char name[100];
    int id;
    int mobile;
};
struct student students[m];
int student_count = 0;

void add_student();
void update_student();
void delete_student();
void print_student();
void search_student();

void update_student1(int index);
void update_student2(int index);
void update_student3(int index);
void update_student4(int index);


void main ()
{
    int choice;
    do
    {
        printf("\n--- Basic Student Record  System ---\n");
        printf("--- 1- Add Student ---\n");
        printf("--- 2- Delete Student ---\n");
        printf("--- 3- Update Student ---\n");
        printf("--- 4- Print All Students ---\n");
        printf("--- 5- Close ---\n");
        printf("--- 6- Print Specifc Student ---\n");
        printf("--- Select Your Choice ( Numbers like 1 means add student ) ---\n");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            update_student();
            break;
        case 4:
            print_student();
            break;
        case 5:
            printf("Closing.....");
            break;
        case 6:
            search_student();
            break;
        default:
            printf("Invalid Choice Try Again");
        }
    }
    while( choice !=6);

}


void add_student()
{
    if (student_count == m)
    {
        printf("No More Space to add more student this program is only design for storing 100 student data....\n");
        return;
    }

    struct student s;
    printf("Enter Roll no. - - \n");
    scanf("%d", &s.roll);
    getchar();
    printf("Enter DOB Format (DD/MM/YYYY). - - \n");
    fgets(s.dob, 100, stdin);
    s.dob[strcspn(s.dob, "\n")] = '\0';
    printf("Enter Name. - - \n");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter School id. - - \n");
    scanf("%d", &s.id);

    students[student_count++] = s;
    printf("Stored Succesfully\n");
}

void update_student()
{
    int choice2;
    int id = 0;
    printf("Enter School id to Search For the Student for Modification ");
    scanf("%d", &id);

    for (int i=0; i<student_count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nWhat you want to Update\n");
            printf("-- 1- Name of the student\n");
            printf("-- 2- Dob of the student\n");
            printf("-- 3- Mobile of the student\n");
            printf("-- 4- School id of the student\n");
            printf("--  Select Your Choice ");
            scanf("%d", &choice2);
            getchar();



            switch (choice2)
            {
            case 1:
                update_student1(i);
                break;
            case 2:
                update_student2(i);
                break;
            case 3:
                update_student3(i);
                break;
            case 4:
                update_student4(i);
                break;
            default:
                printf("Invalid Choice Try Again\n");
            }
            return;

        }
    }
    printf("Student Not Found\n");
}

void update_student1(int index)
{

    printf("Enter New Name ");
    getchar();
    fgets(students[index].name, 100, stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';
    printf("Modification successful!\n");

}

void update_student2(int index)
{
    printf("Enter New Dob ");
    fgets(students[index].dob, 100, stdin);
    students[index].dob[strcspn(students[index].dob, "\n")] = '\0';
    printf("Modification successful!\n");

}

void update_student3(int index)
{
    printf("Enter New Mobile number ");
    scanf("%d", &students[index].mobile);
    printf("Modification successful!\n");

}
void update_student4(int index)
{
    printf("Enter New Mobile number ");
    scanf("%d", &students[index].id);
    printf("Modification successful!\n");

}


void search_student()
{
    int id3, found =0;
    printf("Enter School id to Print details of the Student ");
    scanf("%d", &id3);

    for (int i=0; i<student_count; i++)
    {

        if(students[i].id == id3)
        {
            found = 1;

            printf("Roll No-- %d\n", students[i].roll);
            printf("Name-- %s\n", students[i].name);
            printf("DOB-- %s\n", students[i].dob);
            printf("Mobile No-- %d\n", students[i].mobile);
            printf("School ID-- %d\n", students[i].id);
            printf("-------------------------\n");

        }
    }
}




void delete_student()
{
    int id2, found =0;
    printf("Enter School id to Search for the Student ");
    scanf("%d", &id2);

    for (int i=0; i<student_count; i++)
    {

        if(students[i].id == id2)
        {
            found = 1;

            printf("Roll No-- %d\n", students[i].roll);
            printf("Name-- %s\n", students[i].name);
            printf("DOB-- %s\n", students[i].dob);
            printf("Mobile No-- %d\n", students[i].mobile);
            printf("School ID-- %d\n", students[i].id);
            printf("-------------------------\n");

            for (int j = i; j < student_count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            return;
        }

    }
    if (!found)
    {
        printf("Student Not found \n");
    }
}

void print_student()
{
    if (student_count == 0)
    {
        printf("No students found!\n");
        return;
    }


    printf("\n----- Student Records -----\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("Roll No-- %d\n", students[i].roll);
        printf("Name-- %s\n", students[i].name);
        printf("DOB-- %s\n", students[i].dob);
        printf("Mobile No-- %d\n", students[i].mobile);
        printf("School ID-- %d\n", students[i].id);
        printf("-------------------------\n");
    }

}




















