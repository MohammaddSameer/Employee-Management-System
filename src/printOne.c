#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne)
{
    //Declare variables
    int counter = 1;
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
        //If user inputed position equals the position of current employee
        if(counter == whichOne)
        {
            //Print employee information
            printf("\nEmployee id: %d", currentEmployee->empId);
            printf("\nFirst Name: %s", currentEmployee->fname);
            printf("\nLast Name: %s", currentEmployee->lname);
            printf("\nDependents [%d]: ", currentEmployee->numDependents);

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
        }

        counter++; //Increment counter to keep track of employee positon in linked list
        currentEmployee = currentEmployee->nextEmployee; //Set current employee to next employee
    }


}
