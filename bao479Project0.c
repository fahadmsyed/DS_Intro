#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include "Project0.h"  //Include our own header file for the Employee struct.


int main()
{
	//1.  Open the file Project0.txt and read in the first line of the file to determine how many Employees we need for our array, and use malloc() to dynamically allocate an array of this size.
    FILE* fp;
    fp = fopen("Project0Input.txt", "r");
    char num_of_employees[8];
    int size;
    if (fgets(num_of_employees, 8, fp) != NULL){
        size = atoi(num_of_employees);
    }
    else{
        printf("Error: cannot read the file. \n");
    }
	
    struct Employee* arr = (struct Employee*)malloc(size * sizeof(struct Employee));
	//2.  Use a loop to read the Employee information from Project0.txt and write the information to the entries of your array.  Suggestion:  read a single line of the file using fgets() then use sscanf() to parse out the variables from the line.  
    int i = 0;
    char line[80];
    for (i = 0; i < size; ++i){
        if(fgets(line, 80, fp) != NULL){
            sscanf(line, "%s %d %lf", arr[i].name, &arr[i].id, &arr[i].hourly);
        }
    }
	
	//3.  Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) should be on a single line.  The name should be left justified in a column of width 10.  The IDs are each 6 digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 decimal places.
    for (i = 0; i < size; ++i){
        printf("%-10s ID:%d Hourly Rate: $ %0.2f \n", arr[i].name, arr[i].id, arr[i].hourly );
    }
    free(arr);
    fclose(fp);
	return 0;
}