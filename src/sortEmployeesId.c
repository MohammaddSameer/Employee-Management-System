#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL)
{
    //Declare variables
    struct employee* currentEmployee = headLL;
    int numEmp = countEmployees(headLL);
    int temp;
    int returnPosition;
    int * sortId;
    sortId = malloc(sizeof(int) * numEmp); //Make numEmp number of memory blocks for sortId array

    //Print message if linked list is empty
    if(currentEmployee == NULL)
    {
        printf("List is unable to be sorted");
        return;
    }

    //Storing employee ID values into an array to sort later on
    for(int i = 0; i < numEmp; i++)
    {
        sortId[i] = currentEmployee->empId;
        currentEmployee = currentEmployee->nextEmployee;
    }

    //Bubble sort algorithm to sort employee ID numbers in ascending order
    for(int i = 0; i < numEmp - 1; i++)
    {
        for(int j = 0; j < numEmp - i - 1; j++)
        {
            if(sortId[j] > sortId[j+1])
            {
                temp = sortId[j];
                sortId[j] = sortId[j+1];
                sortId[j+1] = temp;
            }
        }
    }

    //Print employees by their ID's in ascending order
    for(int i = 0; i < numEmp; i++)
    {
        returnPosition = lookOnId(headLL, sortId[i]);
        printOne(headLL, returnPosition);
        printf("\n");             
    }

    free(sortId); 


}
