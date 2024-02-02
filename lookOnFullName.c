#include "../include/headerA3.h"

int lookOnFullName(struct employee* headLL, char whichName[100])
{
    //Delclare variables
    int position = 1;
    char tempName[MAX_LENGTH];
    char * firstName;
    char * lastName;

    struct employee* currentEmployee = headLL; //Set head to current employee

    //Return -1 if linked list is empty
    if(currentEmployee == NULL)
    {
        return -1;
    }

    strncpy(tempName, whichName, sizeof(tempName)); //Copy contents of whichName to tempName
    firstName = strtok(tempName, " "); //Use " " to account for white space between firt and last name
    lastName = strtok(NULL, " \n"); // Terminates \n at the end of the string

    //Iterate through linked list
    while (currentEmployee != NULL) 
    {
        //If input names are the same as the names in the linked list then the employees position/index will be returned
        if(strcmp(currentEmployee->fname, firstName) == 0 && strcmp(currentEmployee->lname, lastName) == 0) 
        {
            return position;
        }

        position++; //Increment position to keep track of employee
        currentEmployee = currentEmployee->nextEmployee; //Set current employee to the next employee
    }

    return -1;
}
