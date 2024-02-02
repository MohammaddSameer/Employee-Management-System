#include "../include/headerA3.h"


int lookOnId (struct employee * headLL, int whichEmpId)
{
    //Declare variables
    int position = 1;
    struct employee* currentEmployee = headLL;

    //Return -1 i linked list is empty
    if(currentEmployee == NULL)
    {
        return -1;
    }

    //Iterate through linked list
    while(currentEmployee != NULL)
    {
        //Return position of linked list if user input is same as userId
        if(currentEmployee->empId == whichEmpId)
        {
            return position;
        }
        position++; //Increment postion to keep track of employee
        currentEmployee = currentEmployee->nextEmployee; //Set current employee to next employee
    }

    return -1;

}