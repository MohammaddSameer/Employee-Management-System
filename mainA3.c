#include "../include/headerA3.h"

int main(){

    //Delcare variables
    int choice;
    int position;
    int userId;
    int returnPosition;
    int numEmp;
    char fireChoice;
    char fullName[MAX_LENGTH];
    char emptyChar;
    struct employee *head = NULL;

    //Call helper function 
    loadEmpData(&head, "proFile.txt");


    //Do while loop for menu
    do
    {
        //Menu
        printf("\n************************************************");
        printf("\n1. Add a new employee");
        printf("\n2. Print data of all employees");
        printf("\n3. Print data of the nth employee");
        printf("\n4. Search for employee based on empId");
        printf("\n5. Search for employee based on full name");
        printf("\n6. Count the total number of employees");
        printf("\n7. Sort the employees based on their empId");
        printf("\n8. Remove the nth employee in the current LL");
        printf("\n9. Remove all employees in the current LL");
        printf("\n10. Exit");
        printf("\n************************************************");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        //Switch cases to navigate through menu
        switch(choice)
        {
            case 1:

                //Function Call
                recruitEmployee(&head);
        
                break;

            case 2: 

                //Function call
                printAll(head);

                break;

            case 3:

                //Prompt user input
                printf("\nEnter a position: ");
                scanf("%d", &position);

                //Function call
                printOne(head, position);

                break;

            case 4: 

                //Prompt user input
                printf("\nEnter an Employee ID: ");
                scanf("%d", &userId);

                //Function call
                returnPosition = lookOnId(head, userId);

                //Print message if employee not found else print employee data
                if(returnPosition == -1)
                {
                    printf("\nEmployee not found");
                }
                else
                {
                    printOne(head, returnPosition);
                }
                
                break;

            case 5: 

                //Prompt user input
                printf("\nEnter the full name of the employee: ");
                scanf("%c", &emptyChar); //Buffer variable when enter button is pressed
                fgets(fullName, MAX_LENGTH, stdin); //fgets gets the whole user input

                //Function call
                returnPosition = lookOnFullName(head, fullName);
                printOne(head, returnPosition); //Print employee data

                //Print message if employee not found
                if(returnPosition == -1)
                {
                    printf("\nEmployee not found");
                }
                printf("\n");

                break;

            case 6:

                //Function call
                numEmp = countEmployees(head);

                //Print message if linked list is empty else print number of employees
                if(numEmp == 0)
                {
                    printf("Linked list is empty.");
                }
                else
                {
                    printf("\nNumber of employees = %d", numEmp);
                }

                break;

            case 7:

                //Function call
                sortEmployeesId(head);

                break;

            case 8: 

                //Function call to get number of employees
                numEmp = countEmployees(head);

                //Prompt user input
                printf("\nCurrently there are %d employees.", numEmp);
                printf("Which employee do you wish to fire - enter a value between 1 and %d: ", numEmp);
                scanf("%d", &position);

                //Function call
                fireOne(&head, position);
                break;

            case 9:

                //Prompt user input
                printf("\nAre you sure you want to fire everyone? (y/n) ");
                scanf(" %c", &fireChoice);

                if(fireChoice == 'Y' || fireChoice == 'y')
                {
                    fireAll(&head); //Function is called if user says yes
                }

                break;


            case 10:

                //Exits and frees program
                fireAll(&head);
                printf("\nExiting program...\n");
                exit(1);

                break;

            default: printf("\nThat is an invalid choice\n"); //Message if input is invalid
        }



    } while(choice >= 1 && choice <=10); //Loop runs if user input is between 1 and 10

}