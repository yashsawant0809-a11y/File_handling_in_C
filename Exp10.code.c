#include<stdio.h>
struct Student
{
int rollNo;
char name[50];
float marks;
};
int main()
{
FILE *fp;
struct Student s;
int choice;
do
{
printf("\n--- STUDENT DATABASE ---\n");
printf("1. Add Student\n");

printf("2. Display Students\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
fp = fopen("students.txt", "a");
if (fp == NULL)
{
printf("Unable to open file.\n");
break;
}
printf("Enter Roll Number: ");
scanf("%d", &s.rollNo);
printf("Enter Name: ");
scanf("%49s", s.name);
printf("Enter Marks: ");
scanf("%f", &s.marks);
fprintf(fp, "%d %s %.2f\n",
s.rollNo, s.name, s.marks);
fclose(fp);
printf("Record saved successfully.\n");
break;
case 2:
fp = fopen("students.txt", "r");
if (fp == NULL)
{
printf("No records found.\n");
break;
}
printf("\n--- STUDENT RECORDS ---\n");
while (fscanf(fp, "%d %49s %f",
&s.rollNo, s.name, &s.marks) == 3)
{
printf("\nRoll No : %d", s.rollNo);
printf("\nName : %s", s.name);
printf("\nMarks : %.2f\n", s.marks);
}
fclose(fp);
break;
case 3:
printf("Program terminated.\n");
break;

default:
printf("Invalid choice.\n");
}
} while (choice != 3);
return 0;
}
