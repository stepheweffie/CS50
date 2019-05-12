#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{
    //Run get_long on integer to determine check sum
    char card = get_long("Number: ");
    printf("%d\n", card);
    if (card %2 == 1)
    {
        if (card %3 >= 1 && card %5 >= 1 && card %7 >= 1 && card %9 >= 1)
        {
            printf("INVALID\n");
        }
    }
    if (card < 0)
    {
        card *= -1;
        //Check for even and product of 3 
        if (card %3 == 0)
        {    
            card /= 3;
            if (card %2 == 0)
            {
                card /= 2;
            }
            //Check for prime factor and factor of 3
            if (card %2 >= 1 && card %3 >= 1 && card %5 >= 1 && card %7 >= 1 && card %9 >= 1)
            {    
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n"); 
            }
        }
        if (card %2 == 1)
        {
            if (card %3 >= 1 && card %5 >= 1 && card %7 >= 1 && card %9 >= 1)
            {
                printf("INVALID\n");
            }
        }
        else if (card %4 == 0)
        {
            printf("MASTERCARD\n");
        }
    }
    
    else if (card %4 == 0 && card > 0)
    {
        printf("INVALID\n");
    }
    else if (card %3 == 0)
    {
        if (card %2 == 0)
        {
            card /= 6;
        }
        printf("Card divided by 6, %d\n", card);
        if (card %3 == 0)
        {
            do
            { 
                card /= 3;
                printf("Dividing by 3\n");
            }
            while (card %3 == 0);
        }
        if (card % 2 == 1)
        {    // Check for prime factor
            if (card == 1 || card == 3 || card == 5 || card == 7)
            {
                 printf("INVALID\n");
            }
            if (card %3 >= 1 && card %5 >= 1 && card %7 >= 1 && card %9 >= 1)
            {
                printf("INVALID\n");        
            }
        }
    }
}


