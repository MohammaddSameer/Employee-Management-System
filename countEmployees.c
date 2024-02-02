#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL)
{
    //Declare variables
    int counter = 0;
    struct employee* currentEmployee = headLL;

    //Return 0 is linked list is empty
    if(currentEmployee == NULL)
    {
        return 0;
    }

    //Iterate over linked list and add 1 to counter to track number of employees
    while(currentEmployee != NULL)
    {
        counter++;
        currentEmployee = currentEmployee->nextEmployee;
    }

    return counter;
}
