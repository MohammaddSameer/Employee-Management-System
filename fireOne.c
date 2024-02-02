#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne)
{
    //Declare variables
    int counter = 1;
    int numEmp;
    struct employee *currentEmployee = *headLL;
    struct employee *prevEmployee = NULL;

    if(currentEmployee == NULL)
    {
        printf("Linked list is empty.");
        return;
    }

    //Iterate through linked list
    while(currentEmployee != NULL)
    {
        if(counter == whichOne) //If the current employee is the one to be removed
        {
            printf("\nEmployee [Id: %d] fired.", currentEmployee->empId);
            numEmp = countEmployees(*headLL);
            printf("\nThere are now %d employees", numEmp-1);

            //Update previous and next employee nodes to remove current employee
            if(prevEmployee == NULL)
            {
                *headLL = currentEmployee->nextEmployee;
            }
            else
            {
                prevEmployee->nextEmployee = currentEmployee->nextEmployee;
            }
            
            for(int i = 0; i < currentEmployee->numDependents; i++)
            {
                free(currentEmployee->dependents[i]); //Free dependents
            }
            free(currentEmployee->dependents); //Free outside
            free(currentEmployee); //Free the whole struct
            return;
        }

        prevEmployee = currentEmployee; //Set current employee to previous employee
        currentEmployee = currentEmployee->nextEmployee; //Set current employee to next employee
        counter++; //Increment counter to keep track of employee in the list
        
    }




}
