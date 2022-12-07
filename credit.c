/*
Code created for the CS50 certification course

Code with take an number input from the user and verfiy that
the number is a valid credit card number by following Luhn's
algorithm
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Number: "); //gets user input
    long tmp = credit;
    int mult = 0;
    int sum = 0;
    
    if (credit < 9000000000){ //if the credit card is under a certain value the program will reject it and terminate
        printf("INVALID\n");
        return 0;
    }

    tmp = credit / 10; //divides by ten to remove the least
    while (tmp > 0) {
        mult = (tmp % 10);
        
        mult *= 2;
        if (mult >= 10) {
            while (mult > 0) {
                sum += (mult % 10);
                mult /= 10;
            }
        }
        else {
            sum += mult;
        }

        tmp /= 100;
    }

    tmp = credit;

    while (tmp > 0) {
        mult = tmp % 10;
        sum += mult;
        tmp /= 100;
    }

    while (credit > 100) {
        credit /= 10;
    }

    if (0 == sum % 10) {
        //printf("test\n");
        if (4 == credit || (40 <= credit && 50 > credit)) {
            printf("VISA\n");
        }
        else if (34 == credit || 37 == credit) {
            printf("AMEX\n");
        }
        else if (51 <= credit && 55 >= credit) {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
}