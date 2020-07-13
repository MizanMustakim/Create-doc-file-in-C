#include <stdio.h>
#include <stdlib.h>
#define DATA_LIMIT 1
struct student {
    int month, day, year;
    int student_id;
    char student_name[100];
    char location[100];
} s[10];
int main()
{
    int i;
    printf("Please enter the information:\n\n");

    FILE *filePointer; /*File pointer to hold reference to the file*/
    filePointer = fopen("student_id.doc", "w"); /*Create the file*/

    /*Checking the file status*/
    if (filePointer == NULL)
    {
        printf("Error! Please, check again.");
        exit(EXIT_FAILURE);
    }

    /*Storing Input to memory*/
    for (i = 0; i < DATA_LIMIT; i++)
    {
        printf("Enter today's date(yyyy mm dd): ");
        scanf("%d %d %d", &s[i].year, &s[i].month, &s[i].day);
        printf("Enter your name: ");
        scanf("%s", s[i].student_name);
        printf("Enter your student ID: ");
        scanf("%d", &s[i].student_id);
        printf("Enter the student's Nationality: ");
        scanf("%s", s[i].location);

        /*Storing Input to the file*/
        fprintf(filePointer,"Today's Date:          %d/%d/%d ", s[i].year, s[i].month, s[i].day);
        fprintf(filePointer,"\nStudent's Name:        %s", s[i].student_name);
        fprintf(filePointer,"\nStudent's ID:          %d", s[i].student_id);
        fprintf(filePointer,"\nStudent's Nationality: %s", s[i].location);
    }

    fclose(filePointer); /*Save the file*/
    return 0;
}
