#include <stdio.h>
#include <conio.h>

// function to calculate subtotal
float totalPrice(float subTotal, float tax)
{
    float bill_Amount = subTotal + tax;
    return bill_Amount;
}

// function to calculate tax
float taxCalc(float subTotal, float taxRate)
{
    float tax = (subTotal * taxRate) / 100;
    return tax;
}

int main(void)
{
    //	Local Declarations
    const double nachos = 5.00, lekor = 2.00, nasi = 4.50, burger = 3.50, drink = 2.00, taxRate = 0.6;
    int ncQty, lekorQty, nlQty, burgerQty, drinkQty;
    float subTotal;
    char name[250];
    char cust[250];
    float total[5];

    //	Statements
    printf("\t\tWelcome To MASMED Sales Billing System\n");
    printf("\n Please Enter the following details. \n\n");

    printf("Cashier's Name: \n");
    scanf("%s", name);
    printf("Customer's Name: \n");
    scanf("%s", cust);

    printf("\n\t***Enter 0 for none****");

    printf("\nHow many nachos were sold? \n");
    scanf("%d", &ncQty);
    total[0] = ncQty * nachos;

    printf("How many keropok lekors were sold? \n");
    scanf("%d", &lekorQty);
    total[1] = lekorQty * lekor;

    printf("How many nasi lemaks were sold? \n");
    scanf("%d", &nlQty);
    total[2] = nlQty * nasi;

    printf("How many burgers were sold? \n");
    scanf("%d", &burgerQty);
    total[3] = burgerQty * burger;

    printf("How many drinks were sold? \n");
    scanf("%d", &drinkQty);
    total[4] = drinkQty * drink;

    printf("\n Press Any Key To Generate Bill");
    printf("\n\n\t\t\t\t\tBill Generated. \n\n");

    //	Calculation Statements
    for (int i = 0; i < 5; i++)
    {
        subTotal += total[i];
    }
    float tax = taxCalc(subTotal, taxRate);
    float finalPrice = totalPrice(subTotal, tax);

    //	Printing Bills
    printf("\n");
    printf("\t\t\t====================================================\n");
    printf("\t\t\t\t          Masmed Sales Bill\n");
    printf("\t\t\t====================================================\n");
    printf("\t\t\tQTY \t Description \t Unit Price$\t Total Price$\n");
    printf("\t\t\t--- \t ----------- \t ---------- \t -----------\n\n");
    printf("\t\t\t%02d \t Nachos                %.2f       %10.2f \n", ncQty, nachos, total[0]);
    printf("\t\t\t%02d  \t Keropok Lekor         %.2f       %10.2f  \n", lekorQty, lekor, total[1]);
    printf("\t\t\t%02d   \t Nasi Lemak            %.2f       %10.2f   \n", nlQty, nasi, total[2]);
    printf("\t\t\t%02d    \t Burger                %.2f       %10.2f    \n", burgerQty, burger, total[3]);
    printf("\t\t\t%02d     \t Drinks                %.2f       %10.2f     \n\n", drinkQty, drink, total[4]);
    printf("\t\t\t                                           ---------\n\n");
    printf("\t\t\t                           SUBTOTAL       %10.2f   \n", subTotal);
    printf("\t\t\t                           TAX            %10.2f    \n", tax);
    printf("\t\t\t                           Total$         %10.2f     \n", finalPrice);
    printf("\t\t\t                           Customer         %s     \n", cust);
    printf("\t\t\t                           Cashier          %s     \n", name);
    printf("\t\t\t====================================================\n\n");
    printf("\t\t\t\t\t\tEnd of bill\n\n");

    return 0;
}
