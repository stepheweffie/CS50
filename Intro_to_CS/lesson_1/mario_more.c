#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 | height > 8);
    for (int i = 1; i <= height; i++)
    {
        for (int k = i; k < height; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
            //printf("..");
        }
        printf("  ");
        for (int n = 0; n < i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}
