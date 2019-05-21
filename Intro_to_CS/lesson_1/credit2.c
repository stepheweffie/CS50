#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char card = get_long_long("Number: ");
    printf("%d\n", card);
}