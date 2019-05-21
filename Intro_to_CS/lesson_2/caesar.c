#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    //Lowercase is difference of +32 uppercase
    string pt = get_string("plaintext: ");
    //char first = pt[0];
    int len = strlen(pt);
    int end = len - 1;
    int key = atoi(argv[1]);
    //key += 1;
    //printf("%s\n%i\n", argv[1], key);
    int letter;
    int cindex;
    //char* ctext[len];
    //printf("%d\n", len);
    char* uppers[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                       "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char* lowers[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
                       "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    printf("ciphertext: ");

    for (int i = 0; i <= end ; i++)
    {
        // Encrypt lowercase
        if (pt[i] <= 122 && pt[i] >= 96)
        {
            //printf("%d %d ", pt[i], i);
            cindex = 96 - key;
            letter = pt[i] - cindex;
            printf("%d", letter);
            if (letter > 25)
            {
                do
                {
                    letter %= 26;
                    printf(" %d ", letter);
                }
                while (letter > 25);
            }
            //ctext[i] = lowers[letter];
            letter -= 1;
            printf("%s %i ", lowers[letter], letter);
        }
        // Encrypt uppercase
        else if (pt[i] <= 90 && pt[i] >= 64)
        {
            //printf("b\n");
            cindex = 64 - key;
            letter = pt[i] - cindex;
            if (letter > 25)
            {
                do
                {
                    letter %= 26;
                }
                while (letter > 25);
            }
            //ctext[i] = uppers[letter];
            letter -= 1;
            printf("%s", uppers[letter]);
        }
        // Print other chars as they are
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}
