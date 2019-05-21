#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Run get_long on integer to determine checksum value
    char card = get_long("Number: ");
    printf("%d\n", card);
    
    // Check for factor of 11, but AMEX number 378734493671000 is 88 as is 45656
    if (card %11 == 0)
        {
            printf("INVALID\n");
        }
    // Check for Mastercard - Checksum is a positive prime or negative product of 4 and a prime 
    // Test values  5105105105178909, 5105105105105100, 5555555555554444
    if (card %2 == 1 || card == 2 || card == 1)
    {
        if (card > 0)
        {
            if (card %3 >= 1 && card %5 >= 1 && card %7 >= 1) // AMEX number 371449635398431 is 31
            {
                printf("MASTERCARD\n");
            }
        }
        if (card == 2 || card == 1 || card == 3 || card == 5 || card == 7)
        {
            printf("MASTERCARD\n");
        }
    }
    else if (card %4 == 0)
    {
        card /= 4;
        // Make positive to handle mod remainder values 
        if (card < 0)
        {
            card *= -1;
        }
        //printf("Dividing by 4\n%d\n", card);
        if (card %2 == 1)
        {
            //printf("Checking prime\n");
            if (card %3 >= 1 && card %5 >= 1 && card %7 >= 1)
            {
                printf("MASTERCARD\n");
            }
        }
    }
    // Check for VISA values, test values 4012888888881881, 4222222222222, 4111111111111111
    if (card < 0)
    {
        card *= -1;
        //Check for even and product of 3 
        //printf("Checking negative VISAs\n");
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
    }
    
    
}
