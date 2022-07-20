#include <stdio.h>
#include <string.h>
#include <stdlib.h> // To use exit(0) function

/* Structs */
// typedef keyword to create an alias name for data types. It is commonly used with structures to simplify the syntax of declaring variables.
/*typedef struct User
{
    int userLevel; // userLevel, 1 = admin, 2 = user
};*/

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
    if (input == 1) // To purchase ticket
    {
        int userInput;
        printf("Movie name?\n");
        printf("----------------------\n");
        printf("1. Dr Strange Multiverse of Madness\n");
        printf("2. Fantastic Beast The Secrets of Dumbledore\n");
        printf("3. Resident Evil Welcome to Raccoon City\n");
        printf("4. Exiting the program\n");
        scanf("%d", &userInput);
        return userInput;
        // To book movie
    }
    else if (input == 2) // To cancel the seat
    {

        // To cancel the booking
    }
    else if (input == 3)
    {
        printf("See you soon!\n");
        exit(0);
    }
}

int adminFunction(int input)
{
    if (input == 1) // View reserved tickets
    {
    }
    else if (input == 2) // Edit price of the tickets
    {
        int adminInput;
        printf("Which movie to be edit?\n");
        printf("----------------------\n");
        printf("1. Dr Strange Multiverse of Madness\n");
        printf("2. Fantastic Beast The Secrets of Dumbledore\n");
        printf("3. Resident Evil Welcome to Raccoon City\n");
        printf("4. Exiting the program\n");
        scanf("%d", &adminInput);
        return adminInput;
    }
    else if (input == 3) // Exit
    {
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
struct movie edit1();
struct movie edit2();
struct movie edit3();
/* Main function */
int main()
{
    // declaring movie
    struct movie drstrange;
    struct movie fantastic;
    struct movie resident;

    //
    int loginInput = welcomeMessage();
    int input;
    int userInput;
    int adminInput;
    if (loginInput == 1) // admin
    {
        printf("Welcome admin!\n");
        printf("Indicate your preference by entering the appropriate number:\n");
        printf("1. View the reserved tickets\n");
        printf("2. Edit the price of ticket\n");
        printf("3. Exit\n");
        scanf("%d", &input);

        adminInput = adminFunction(input);
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

    if (adminInput == 1)
    {
        drstrange = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", drstrange.name);
        printf("\nHall: %d", drstrange.hall);
        printf("\nDate: %s", drstrange.date);
        printf("\nTime: %s", drstrange.time);
        printf("\nPrice: RM %.2f", drstrange.price);
    }
    else if (adminInput == 2)
    {
        fantastic = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", fantastic.name);
        printf("\nHall: %d", fantastic.hall);
        printf("\nDate: %s", fantastic.date);
        printf("\nTime: %s", fantastic.time);
        printf("\nPrice: RM %.2f", fantastic.price);
    }
    else if (adminInput == 3)
    {
        resident = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", resident.name);
        printf("\nHall: %d", resident.hall);
        printf("\nDate: %s", resident.date);
        printf("\nTime: %s", resident.time);
        printf("\nPrice: RM %.2f", resident.price);
    }

    if (userInput == 1)
    {
        drstrange = getSeat1();
        printf("\nDisplaying information\n");
        printf("Name: %s", drstrange.name);
        printf("\nHall: %d", drstrange.hall);
        printf("\nDate: %s", drstrange.date);
        printf("\nTime: %s", drstrange.time);
        printf("\nPrice: RM %.2f", drstrange.price);
        printf("\nSeat: %d", drstrange.seat);
    }
    else if (userInput == 2)
    {
        fantastic = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", fantastic.name);
        printf("\nHall: %d", fantastic.hall);
        printf("\nDate: %s", fantastic.date);
        printf("\nTime: %s", fantastic.time);
        printf("\nPrice: RM %.2f", fantastic.price);
        printf("\nSeat: %d", fantastic.seat);
    }
    else if (userInput == 3)
    {
        resident = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", resident.name);
        printf("\nHall: %d", resident.hall);
        printf("\nDate: %s", resident.date);
        printf("\nTime: %s", resident.time);
        printf("\nPrice: RM %.2f", resident.price);
        printf("\nSeat: %d", resident.seat);
    }
    else if (userInput == 4)
    {
        printf("Goodbye!");
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
    drstrange.hall = 2;
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
    fantastic.hall = 1;
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
    resident.hall = 1;
    strcpy(resident.date, "28-07-2022");
    strcpy(resident.time, "6.00p.m.");
    resident.price = 19.00;

    return resident;
}
struct movie edit1()
{
    struct movie drstrange;
    printf("Enter movie's name: ");
    scanf("%s", &drstrange.name);
    printf("Enter movie's hall: ");
    scanf("%d", &drstrange.hall);
    printf("Enter movie's date: ");
    scanf("%s", &drstrange.date);
    printf("Enter movie's time: ");
    scanf("%s", &drstrange.time);
    printf("Enter movie's price: ");
    scanf("%f", &drstrange.price);

    return drstrange;
}
struct movie edit2()
{
    struct movie fantastic;
    printf("Enter movie's name: ");
    scanf("%s", &fantastic.name);
    printf("Enter movie's hall: ");
    scanf("%d", &fantastic.hall);
    printf("Enter movie's date: ");
    scanf("%s", &fantastic.date);
    printf("Enter movie's time: ");
    scanf("%s", &fantastic.time);
    printf("Enter movie's price: ");
    scanf("%f", &fantastic.price);

    return fantastic;
}
struct movie edit3()
{
    struct movie resident;
    printf("Enter movie's name: ");
    scanf("%s", &resident.name);
    printf("Enter movie's hall: ");
    scanf("%d", &resident.hall);
    printf("Enter movie's date: ");
    scanf("%s", &resident.date);
    printf("Enter movie's time: ");
    scanf("%s", &resident.time);
    printf("Enter movie's price: ");
    scanf("%f", &resident.price);

    return resident;
}