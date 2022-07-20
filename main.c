#include <stdio.h>
#include <string.h>
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
    printf("Welcome to Tijani Home Theatre Booking System!\n");
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
        int userInput;
        printf("Movie name?\n");
        printf("----------------------\n");
        printf("1. to Dr Strange Multiverse of Madness\n");
        printf("2. to Fantastic Beast The Secrets of Dumbledore\n");
        printf("3. to Resident Evil Welcome to Raccoon City\n");
        printf("4. to Exiting the program\n");
        scanf("%d", &userInput);
        return userInput;
        // To book movie
    }
    else if (input == 2)
    {

        // To cancel the booking
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
// declaring struct movie dictionary
struct movie
{
    char name[64];
    char date[16];
    char time[16];
    int hall;
    int seat;
    float price;
};
struct movie getSeat1();
struct movie getSeat2();
struct movie getSeat3();
/* Main function */
int main()
{
    // declaring movie
    struct movie drstrange;
    struct movie fantastic;
    struct movie resident;

    int loginInput = welcomeMessage();

    int input;
    int userInput;
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

        userInput = userFunction(input);
    }
    else if (loginInput == 3)
    {
        printf("See you soon!\n");
        exit(0);
    }

        if (userInput == 1)
    {
        drstrange = getSeat1();
        printf("\nDisplaying information\n");
        printf("Name: %s", drstrange.name);
        printf("\nDate: %s", drstrange.date);
        printf("\nTime: %s", drstrange.time);
        printf("\nPrice: %f", drstrange.price);
        printf("\nSeat: %d", drstrange.seat);
    }
    else if (userInput == 2)
    {
        fantastic = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", fantastic.name);
        printf("\nDate: %s", fantastic.date);
        printf("\nTime: %s", fantastic.time);
        printf("\nPrice: %f", fantastic.price);
        printf("\nSeat: %d", fantastic.seat);
    }
    else if (userInput == 3)
    {
        resident = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", resident.name);
        printf("\nDate: %s", resident.date);
        printf("\nTime: %s", resident.time);
        printf("\nPrice: %f", resident.price);
        printf("\nSeat: %d", resident.seat);
    }
    return 0;
}
// function to get seat
struct movie getSeat1()
{
    struct movie drstrange;
    printf("Enter seat: ");
    scanf("%d", &drstrange.seat);
    strcpy(drstrange.name, "Dr Strange Multiverse of Madness");
    strcpy(drstrange.date, "27-07-2022");
    strcpy(drstrange.time, "8.00p.m.");
    drstrange.price = 17.5;

    return drstrange;
}
struct movie getSeat2()
{
    struct movie fantastic;
    printf("Enter seat: ");
    scanf("%d", &fantastic.seat);
    strcpy(fantastic.name, "Fantastic Beast The Secrets of Dumbledore");
    strcpy(fantastic.date, "28-07-2022");
    strcpy(fantastic.time, "4.00p.m.");
    fantastic.price = 18.50;

    return fantastic;
}
struct movie getSeat3()
{
    struct movie resident;
    printf("Enter seat: ");
    scanf("%d", &resident.seat);
    strcpy(resident.name, "Resident Evil Welcome to Raccoon City");
    strcpy(resident.date, "28-07-2022");
    strcpy(resident.time, "6.00p.m.");
    resident.price = 19.00;

    return resident;
}
