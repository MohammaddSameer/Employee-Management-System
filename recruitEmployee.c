#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL)
{
    //Declare variables
    struct employee *newEmployee = malloc(sizeof(struct employee)); //Allocate memory for employee
    struct employee *endEmployee = *headLL;
    char choice = 'y';
    int sum = 0;
    int fnameLength = 0;
    int lnameLength = 0;
    newEmployee->numDependents = 0;
    newEmployee->dependents = NULL;

    //Prompt user input for first name
    printf("\nEnter the first name of the employee: ");
    scanf("%s", newEmployee->fname);

    //Prompt user input for last name
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmployee->lname);

    //Loop runs as long as user's choice is 'y or "Y"
    while(choice == 'Y' || choice == 'y')
    {
        newEmployee->dependents = realloc(newEmployee->dependents, sizeof(char *) * (newEmployee->numDependents + 1)); //Add a block of memory
        newEmployee->dependents[newEmployee->numDependents] = (char*) malloc(sizeof(char) * MAX_LENGTH); //Allocate memroy for dependents

        //Prompt user input for dependents
        printf("\nEnter name of dependent# %d: ", newEmployee->numDependents + 1);
        scanf("%s", newEmployee->dependents[newEmployee->numDependents]);
        newEmployee->numDependents++; //Increment number of dependents

        //Prompts user if they want to add more dependents
        printf("Do you have any more dependents? (y/n) ");
        scanf(" %c", &choice);
    }

    printf("\nYou have %d dependents\n", newEmployee->numDependents);

    //Gets length of first and last name
    fnameLength = strlen(newEmployee->fname);
    lnameLength = strlen(newEmployee->lname);

    //Formula for employee id
    for(int i = 0; i < fnameLength; i++)
    {
        sum = sum + newEmployee->fname[i];
    }

    newEmployee->empId = sum + lnameLength;

    struct employee *currentEmployee = *headLL;

    //If a duplicate id exists add a random number
    while (currentEmployee != NULL)
    {
        if (currentEmployee->empId == newEmployee->empId)
        {
            newEmployee->empId += rand() % 999 + 1;
            currentEmployee = *headLL;
        }
        else
        {
            currentEmployee = currentEmployee->nextEmployee; //Set next employee to the current employee
        }
    }


    printf("\nYour computer-generated empId is %d", newEmployee->empId);

    newEmployee->nextEmployee = NULL;

    //If linked list is empty new employee is added as first node
    if (*headLL == NULL)
    {
        *headLL = newEmployee;
    }
    //Adds new employee to end of the list
    else 
    {
        while (endEmployee->nextEmployee != NULL)
        {
            endEmployee = endEmployee->nextEmployee;
        }
        endEmployee->nextEmployee = newEmployee;
    }
    
}
