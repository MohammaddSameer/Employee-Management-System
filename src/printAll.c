#include "../include/headerA3.h"

void printAll (struct employee * headLL)
{
    //Declare variables
    int i = 0;
    struct employee* currentEmployee = headLL;

    //Print message if linked list is empty
    if(currentEmployee == NULL)
    {
        printf("Linked list is empty.");
        return;
    }

    //Iterate through linked list
    while(currentEmployee != NULL)
    {
        i++; //Increment employee number

        //Print employee information
        printf("\n\nEmployee # %d", i);
        printf("\n      Employee id: %d", currentEmployee->empId);
        printf("\n      First Name: %s", currentEmployee->fname);
        printf("\n      Last Name: %s", currentEmployee->lname);
        printf("\n      Dependents [%d]: ", currentEmployee->numDependents);

        //For loop prints each dependent with or without a comma
        for(int j = 0; j < currentEmployee->numDependents; j++)
        {
            if(j+1 == currentEmployee->numDependents)
            {
                printf("%s", currentEmployee->dependents[j]);

            }
            else
            {
                printf("%s, ", currentEmployee->dependents[j]);
            }
        }

        currentEmployee = currentEmployee->nextEmployee; //Set current employee to next employee

    }

    printf("\n\nCurrently, there are %d employees.", i);

}
