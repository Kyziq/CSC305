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
    struct movie movie1;
    struct movie movie2;
    struct movie movie3;

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
        movie1 = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie1.name);
        printf("\nHall: %d", movie1.hall);
        printf("\nDate: %s", movie1.date);
        printf("\nTime: %s", movie1.time);
        printf("\nPrice: RM %.2f", movie1.price);
    }
    else if (adminInput == 2)
    {
        movie2 = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie2.name);
        printf("\nHall: %d", movie2.hall);
        printf("\nDate: %s", movie2.date);
        printf("\nTime: %s", movie2.time);
        printf("\nPrice: RM %.2f", movie2.price);
    }
    else if (adminInput == 3)
    {
        movie3 = edit1();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie3.name);
        printf("\nHall: %d", movie3.hall);
        printf("\nDate: %s", movie3.date);
        printf("\nTime: %s", movie3.time);
        printf("\nPrice: RM %.2f", movie3.price);
    }

    if (userInput == 1)
    {
        movie1 = getSeat1();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie1.name);
        printf("\nHall: %d", movie1.hall);
        printf("\nDate: %s", movie1.date);
        printf("\nTime: %s", movie1.time);
        printf("\nPrice: RM %.2f", movie1.price);
        printf("\nSeat: %d", movie1.seat);
    }
    else if (userInput == 2)
    {
        movie2 = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie2.name);
        printf("\nHall: %d", movie2.hall);
        printf("\nDate: %s", movie2.date);
        printf("\nTime: %s", movie2.time);
        printf("\nPrice: RM %.2f", movie2.price);
        printf("\nSeat: %d", movie2.seat);
    }
    else if (userInput == 3)
    {
        movie3 = getSeat2();
        printf("\nDisplaying information\n");
        printf("Name: %s", movie3.name);
        printf("\nHall: %d", movie3.hall);
        printf("\nDate: %s", movie3.date);
        printf("\nTime: %s", movie3.time);
        printf("\nPrice: RM %.2f", movie3.price);
        printf("\nSeat: %d", movie3.seat);
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
    struct movie movie1;
    printf("Enter seat: ");
    scanf("%d", &movie1.seat);
    strcpy(movie1.name, "Dr Strange Multiverse of Madness");
    movie1.hall = 2;
    strcpy(movie1.date, "27-07-2022");
    strcpy(movie1.time, "8.00p.m.");
    movie1.price = 17.5;

    return movie1;
}
struct movie getSeat2()
{
    struct movie movie2;
    printf("Enter seat: ");
    scanf("%d", &movie2.seat);
    strcpy(movie2.name, "Fantastic Beast The Secrets of Dumbledore");
    movie2.hall = 1;
    strcpy(movie2.date, "28-07-2022");
    strcpy(movie2.time, "4.00p.m.");
    movie2.price = 18.50;

    return movie2;
}
struct movie getSeat3()
{
    struct movie movie3;
    printf("Enter seat: ");
    scanf("%d", &movie3.seat);
    strcpy(movie3.name, "Resident Evil Welcome to Raccoon City");
    movie3.hall = 1;
    strcpy(movie3.date, "28-07-2022");
    strcpy(movie3.time, "6.00p.m.");
    movie3.price = 19.00;

    return movie3;
}
struct movie edit1()
{
    struct movie movie1;
    printf("Enter movie's name: ");
    scanf("%s", &movie1.name);
    printf("Enter movie's hall: ");
    scanf("%d", &movie1.hall);
    printf("Enter movie's date: ");
    scanf("%s", &movie1.date);
    printf("Enter movie's time: ");
    scanf("%s", &movie1.time);
    printf("Enter movie's price: ");
    scanf("%f", &movie1.price);

    return movie1;
}
struct movie edit2()
{
    struct movie movie2;
    printf("Enter movie's name: ");
    scanf("%s", &movie2.name);
    printf("Enter movie's hall: ");
    scanf("%d", &movie2.hall);
    printf("Enter movie's date: ");
    scanf("%s", &movie2.date);
    printf("Enter movie's time: ");
    scanf("%s", &movie2.time);
    printf("Enter movie's price: ");
    scanf("%f", &movie2.price);

    return movie2;
}
struct movie edit3()
{
    struct movie movie3;
    printf("Enter movie's name: ");
    scanf("%s", &movie3.name);
    printf("Enter movie's hall: ");
    scanf("%d", &movie3.hall);
    printf("Enter movie's date: ");
    scanf("%s", &movie3.date);
    printf("Enter movie's time: ");
    scanf("%s", &movie3.time);
    printf("Enter movie's price: ");
    scanf("%f", &movie3.price);

    return movie3;
}