#include <stdio.h>
#include <string.h>
#include <stdlib.h> // To use exit(0) function

/* Structs */
// typedef keyword to create an alias name for data types. It is commonly used with structures to simplify the syntax of declaring variables.
/*typedef struct User
{
    int userLevel; // userLevel, 1 = admin, 2 = user
};*/

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

/* User-defined functions */
int welcomeMessage()
{
    // Login
    int loginInput;
    printf("----------------------------------------------------------------------\n");
    printf("Welcome to Tijani Home Theatre Booking System!\n");
    printf("Please indicate your preference by entering the number:\n");
    printf("1. Login as an admin\n");
    printf("2. Login as a user\n");
    printf("3. Exit\n");
    printf("----------------------------------------------------------------------\n");
    scanf("%d", &loginInput);
    return loginInput;
}

void exitProgram()
{
    printf("See you soon!\n");
    exit(0);
}

struct movie editMovie(int movieID)
{
    struct movie movie[3];
    if (movieID == 1)
    {
        printf("Movie name: \n", &movie[0].name);
        printf("Enter movie's new name: \n");
        scanf("%s", &movie[0].name);
        printf("Enter movie's new hall: \n");
        scanf("%d", &movie[0].hall);
        printf("Enter movie's new date: \n");
        scanf("%s", &movie[0].date);
        printf("Enter movie's new time: \n");
        scanf("%s", &movie[0].time);
        printf("Enter movie's new price: \n");
        scanf("%f", &movie[0].price);
        return movie[0];
    }
    else if (movieID == 2)
    {
        printf("Enter movie's new name: \n");
        scanf("%s", &movie[1].name);
        printf("Enter movie's new hall: \n");
        scanf("%d", &movie[1].hall);
        printf("Enter movie's new date: \n");
        scanf("%s", &movie[1].date);
        printf("Enter movie's new time: \n");
        scanf("%s", &movie[1].time);
        printf("Enter movie's new price: \n");
        scanf("%f", &movie[1].price);
        return movie[1];
    }
    else if (movieID == 3)
    {
        printf("Enter movie's new name: \n");
        scanf("%s", &movie[2].name);
        printf("Enter movie's new hall: \n");
        scanf("%d", &movie[2].hall);
        printf("Enter movie's new date: \n");
        scanf("%s", &movie[2].date);
        printf("Enter movie's new time: \n");
        scanf("%s", &movie[2].time);
        printf("Enter movie's new price: \n");
        scanf("%f", &movie[2].price);
        return movie[2];
    }
    else if (movieID == 4)
        exitProgram();
}
struct movie getMovie(int movieID)
{
    struct movie movie[3];
    printf("Enter seat: ");
    if (movieID == 1)
    {
        scanf("%d", &movie[0].seat);
        strcpy(movie[0].name, "Dr Strange Multiverse of Madness");
        strcpy(movie[0].date, "27-07-2022");
        strcpy(movie[0].time, "8.00p.m.");
        movie[0].hall = 2;
        movie[0].price = 17.50;
        return movie[0];
    }
    else if (movieID == 2)
    {
        scanf("%d", &movie[1].seat);
        strcpy(movie[1].name, "Fantastic Beast The Secrets of Dumbledore");
        strcpy(movie[1].date, "28-07-2022");
        strcpy(movie[1].time, "4.00p.m.");
        movie[1].hall = 2;
        movie[1].price = 18.50;
        return movie[1];
    }
    else if (movieID == 3)
    {
        scanf("%d", &movie[2].seat);
        strcpy(movie[2].name, "Resident Evil Welcome to Raccoon City");
        strcpy(movie[2].date, "28-07-2022");
        strcpy(movie[2].time, "6.00p.m.");
        movie[2].hall = 3;
        movie[2].price = 19.00;
        return movie[2];
    }
    else if (movieID == 4)
        exitProgram();
}
// User
int userFunction(int input)
{
    if (input == 1) // To purchase ticket
    {
        int purchaseTicketInput;
        printf("Movie name?\n");
        printf("1. Dr Strange Multiverse of Madness\n");
        printf("2. Fantastic Beast The Secrets of Dumbledore\n");
        printf("3. Resident Evil Welcome to Raccoon City\n");
        printf("4. Exit the program\n");
        scanf("%d", &purchaseTicketInput);

        struct movie movie = getMovie(purchaseTicketInput);

        printf("Movie details:\n");
        printf("Name: %s\n", movie.name);
        printf("Hall: %d\n", movie.hall);
        printf("Date: %s\n", movie.date);
        printf("Time: %s\n", movie.time);
        printf("Price: RM %.2f\n", movie.price);
        printf("Seat: %d\n", movie.seat);
    }
    else if (input == 2) // To cancel the seat
    {

        // To cancel the booking
    }
    else if (input == 3)
        exitProgram();
}
void userMenu()
{
    int afterMenuInput;
    printf("Welcome user!\n");
    printf("Please indicate your preference by entering the number:\n");
    printf("1. To purchase ticket\n");
    printf("2. To cancel the seat\n");
    printf("3. Exit\n");
    scanf("%d", &afterMenuInput);

    userFunction(afterMenuInput);
}

// Admin
int adminFunction(int input)
{
    if (input == 1) // View reserved tickets
    {
    }
    else if (input == 2) // Edit price of the tickets
    {
        int editPriceInput;
        printf("Which movie to be edit?\n");
        printf("1. Dr Strange Multiverse of Madness\n");
        printf("2. Fantastic Beast The Secrets of Dumbledore\n");
        printf("3. Resident Evil Welcome to Raccoon City\n");
        printf("4. Exit\n");
        scanf("%d", &editPriceInput);

        struct movie movie = editMovie(editPriceInput);
        printf("Displaying information\n");
        printf("New movie name: %s\n", movie.name);
        printf("New hall: %d\n", movie.hall);
        printf("New date: %s\n", movie.date);
        printf("New time: %s\n", movie.time);
        printf("New price: RM %.2f\n", movie.price);
    }
    else if (input == 3) // Exit
        exitProgram();
}
void adminMenu()
{
    int afterMenuInput;
    printf("Welcome admin!\n");
    printf("Indicate your preference by entering the appropriate number:\n");
    printf("1. View the reserved tickets\n");
    printf("2. Edit the price of ticket\n");
    printf("3. Exit\n");
    scanf("%d", &afterMenuInput);

    adminFunction(afterMenuInput);
}

/* Main function */
int main()
{
    int loginInput = welcomeMessage();
    if (loginInput == 1) // admin
        adminMenu();
    else if (loginInput == 2) // user
        userMenu();
    else if (loginInput == 3) // exit
        exitProgram();
    return 0;
}
