#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    int coins = 0;
    float change;
    int remaining = 0;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < .009);
    int cents = round(change * 100);
    //printf("%d\n", cents);
    if (cents == 0)
    {
        printf("%d\n", cents);
    }
    if (cents >= 25)
    {
        //printf("%d\n", coins);
        coins += cents / 25;
        if (cents % 25 == 0)
        {
            printf("%d\n", coins);
        }
        else
        {
        cents -= coins * 25;
        }
    }
    if (cents < 25 && cents >= 10)
    {
        coins += cents / 10;
        remaining = cents / 10;
        if (cents % 10 == 0)
        {
            printf("%d\n", coins);
        }
        else
        {
        cents -=  remaining * 10;
        }
    }
    if (cents < 10 && cents >= 5)
    {
        coins += cents / 5;
        remaining = cents / 5;
        if (cents % 5 == 0)
        {
            printf("%d\n", coins);
        }
        else
        {
        cents -=  remaining * 5;
        }
    }
    if (cents < 5 && cents >= 0)
    {
        coins += cents;
        printf("%d\n", coins);
    }
}