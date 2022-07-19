#include <stdio.h>
#include <stdlib.h> // To use exit(0) function

/* Structs */
// typedef keyword to create an alias name for data types. It is commonly used with structures to simplify the syntax of declaring variables.
typedef struct User
{
    int userLevel; // userLevel, 1 = admin, 2 = user
} user;

typedef struct Movie
{
    char movieName[50];
    float movieFee;
} movie;

/* User-defined functions */
int welcomeMessage()
{
    // Login
    int loginInput;
    printf("----------------------------------------------------------------------\n");
    printf("Welcome to Golden Screen Cinema Ticket Booking System!\n");
    printf("Choose your input:\n");
    printf("1. Login as an admin\n");
    printf("2. Login as a user\n");
    printf("3. Exit\n");
    printf("----------------------------------------------------------------------\n");
    scanf("%d", &loginInput);
    return loginInput;
}

int userFunction(int input)
{
    if (input == 1)
    {
        // To purchase ticket
    }
    else if (input == 2)
    {
        // To cancel the seat
    }
    else if (input == 3)
    {
        // Exit
        printf("See you soon!\n");
        exit(0);
    }
}

int adminFunction(int input)
{
    if (input == 1)
    {
        // View reserved tickets
    }
    else if (input == 2)
    {
        // Edit price of the tickets
    }
    else if (input == 3)
    {
        // Exit
        printf("See you soon!\n");
        exit(0);
    }
}

/* Main function */
int main()
{
    int loginInput = welcomeMessage();

    int input;
    if (loginInput == 1) // admin
    {
        printf("Welcome admin!\n");
        printf("Indicate your preference by entering the appropriate number:\n");
        printf("1. View the reserved tickets\n");
        printf("2. Edit the price of ticket\n");
        printf("3. Exit\n");
        scanf("%d", &input);

        adminFunction(input);
    }
    else if (loginInput == 2) // user
    {
        printf("Welcome user!\n");
        printf("Please indicate your preference by entering the appropriate number:\n");
        printf("1. To purchase ticket\n");
        printf("2. To cancel the seat\n");
        printf("3. Exit\n");
        scanf("%d", &input);

        userFunction(input);
    }
    else if (loginInput == 3)
    {
        printf("See you soon!\n");
        exit(0);
    }
    return 0;
}
