#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct menu
{
    char menuName[64];
    float menuPrice;
};

// Function to calculate subtotal
float totalPrice(float subTotal, float tax)
{
    float billAmount = subTotal + tax;
    return billAmount;
}

// Function to calculate tax (Govt Tax)
float taxCalc(float subTotal, float taxRate)
{
    float tax = (subTotal * taxRate) / 100;
    return tax;
}
// main program
int main()
{

    // Write to txt file
    struct menu menu[7];
    strcpy(menu[0].menuName, "Nachos");
    menu[0].menuPrice = 5.00;
    strcpy(menu[1].menuName, "Keropok Lekor (Small)");
    menu[1].menuPrice = 2.00;
    strcpy(menu[2].menuName, "Keropok Lekor (Large)");
    menu[2].menuPrice = 3.50;
    strcpy(menu[3].menuName, "Nasi Lemak");
    menu[3].menuPrice = 4.50;
    strcpy(menu[4].menuName, "Burger");
    menu[4].menuPrice = 3.50;
    strcpy(menu[5].menuName, "Drink (Small)");
    menu[5].menuPrice = 2.00;
    strcpy(menu[6].menuName, "Drink (Large)");
    menu[6].menuPrice = 3.00;

    FILE *fptr;

    fptr = fopen("./menu.txt", "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for (int x = 0; x < sizeof(menu) / sizeof(*menu); x++)
    {
        fprintf(fptr, "%s\n%.2f\n", menu[x].menuName, menu[x].menuPrice);
        fprintf(fptr, "\n"); // New line
    }

    fclose(fptr);

    /*	Local Declarations */
    // Fixed food prices
    const double
        nachos = 5.00,
        lekor = 2.00,
        lekorL = 3.50,
        nasi = 4.50,
        burger = 3.50,
        drink = 2.00,
        drinkL = 3.00;

    // Tax rate in %
    const double taxRate = 6;
    int ncQty, lekorQty, nlQty, burgerQty, drinkQty, drinkChoice, lekorChoice;
    float subTotal;
    char name[250], cust[250], userChoice = 'y';
    float total[5];

    //	Statements
    while (userChoice == 'y')
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome To MASMED Sales Billing System\n");
        printf("Please enter the following details:\n\n");

        printf("Cashier's name: \n");
        scanf("%s", name);
        printf("Customer's name: \n");
        scanf("%s", cust);

        printf("\n*** Enter 0 (quantity) if none were sold ****");

        printf("\nHow many nachos were sold? \n");
        scanf("%d", &ncQty);
        total[0] = ncQty * nachos;

        printf("How many keropok lekors were sold? \n");
        scanf("%d", &lekorQty);

        printf("What type of lekor were sold? (1 for small, 2 for large) \n");
        scanf("%d", &lekorChoice);

        if (lekorChoice == 1)
            total[1] = lekorQty * lekor;
        else if (lekorChoice == 2)
            total[1] = lekorQty * lekorL;

        printf("How many nasi lemaks were sold? \n");
        scanf("%d", &nlQty);
        total[2] = nlQty * nasi;

        printf("How many burgers were sold? \n");
        scanf("%d", &burgerQty);
        total[3] = burgerQty * burger;

        printf("How many drinks were sold? \n");
        scanf("%d", &drinkQty);
        printf("What type of drinks were sold? (1 for small, 2 for large) \n");
        scanf("%d", &drinkChoice);
        if (drinkChoice == 1)
            total[4] = drinkQty * drink;
        else if (drinkChoice == 2)
            total[4] = drinkQty * drinkL;

        //	Calculation Statements using array
        for (int i = 0; i < 5; i++)
        {
            subTotal += total[i];
        }
        // Calling function to calculate food price
        float tax = taxCalc(subTotal, taxRate);
        float finalPrice = totalPrice(subTotal, tax);

        //	Printing Bills
        printf("\n");
        printf("\t\t\t================================================================\n");
        printf("\t\t\t\t\t\t*Masmed Sales Bill*\n\n");
        printf("\t\t\t\t\tCustomer - %s     \n", cust);
        printf("\t\t\t\t\tCashier  - %s     \n", name);
        printf("\t\t\t================================================================\n");
        printf("\t\t\tQty \t Description \t Unit Price(RM) \t Total Price(RM)\n");
        printf("\t\t\t--- \t ----------- \t -------------- \t ---------------\n\n");
        printf("\t\t\t%02d \t Nachos                    %.2f              %10.2f \n", ncQty, nachos, total[0]);

        if (lekorChoice == 1)
            printf("\t\t\t%02d  \t Keropok Lekor(S)          %.2f              %10.2f  \n", lekorQty, lekor, total[1]);
        else if (lekorChoice == 2)
            printf("\t\t\t%02d  \t Keropok Lekor(L)          %.2f              %10.2f  \n", lekorQty, lekorL, total[1]);

        printf("\t\t\t%02d   \t Nasi Lemak                %.2f              %10.2f   \n", nlQty, nasi, total[2]);
        printf("\t\t\t%02d    \t Burger                    %.2f              %10.2f    \n", burgerQty, burger, total[3]);

        if (drinkChoice == 1)
            printf("\t\t\t%02d     \t Drinks(S)                 %.2f              %10.2f     \n", drinkQty, drink, total[4]);
        else if (drinkChoice == 2)
            printf("\t\t\t%02d     \t Drinks(L)                 %.2f              %10.2f     \n", drinkQty, drinkL, total[4]);

        printf("\t\t\t                                  ------------------------------\n\n");
        printf("\t\t\t                                  SUBTOTAL          RM%10.2f     \n", subTotal);
        printf("\t\t\t                                  GOVT. TAX (6%)    RM%10.2f     \n", tax);
        printf("\t\t\t                                  TOTAL             RM%10.2f     \n", finalPrice);
        printf("\t\t\t================================================================\n\n");
        printf("\t\t\t\t\t\tEnd of Bill\n\n");

        printf("Do you still want to continue? (y/n)\n");
        scanf("%s", &userChoice);
    }
    return 0;
}
