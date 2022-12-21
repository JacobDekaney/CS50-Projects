#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Number: ");
    long tmp = credit;
    int mult = 0;
    int sum = 0;
    if (credit < 9000000000)
    {
        printf("INVALID\n");
        return 0;
    }

    tmp = credit / 10;
    while (tmp > 0)
    {
        mult = (tmp % 10);
        mult *= 2;
        if (mult >= 10)
        {
            while (mult > 0)
            {
                sum += (mult % 10);
                mult /= 10;
            }
        }
        else
        {
            sum += mult;
        }

        tmp /= 100;
    }

    //printf("%d\n", sum);

    tmp = credit;

    while (tmp > 0)
    {
        mult = tmp % 10;
        sum += mult;
        tmp /= 100;
    }
    //printf("%d\n", sum);


    while (credit > 100)
    {
        credit /= 10;
    }

    //printf("%ld\n", credit);


    if (0 == sum % 10)
    {
        //printf("test\n");
        if (4 == credit || (40 <= credit && 50 > credit))
        {
            printf("VISA\n");
        }
        else if (34 == credit || 37 == credit)
        {
            printf("AMEX\n");
        }
        else if (51 <= credit && 55 >= credit)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}