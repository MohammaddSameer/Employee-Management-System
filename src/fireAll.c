#include "../include/headerA3.h"

void fireAll(a3Emp **headLL)
{
    //Declare variables
    struct employee *currentEmployee = *headLL;
    struct employee *temp;

    //Print message if linked list is empty
    if(currentEmployee == NULL)
    {
        printf("Linked list is empty.");
        return;
    }

    //Loop runs when linked list is not empty
    while (currentEmployee != NULL)
    {
        temp = currentEmployee->nextEmployee; //Set next employee in temp variable

        for(int i = 0; i < currentEmployee->numDependents; i++)
        {
            free(currentEmployee->dependents[i]); //Free each dependent
        }

        free(currentEmployee->dependents); //Free outside of dependents
        free(currentEmployee); //Free the whole struct
        currentEmployee = temp; //Store the next employee
    }
    printf("All fired. Linked list is now empty.");

    *headLL = NULL;
}