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
    //int ciphered[len];
    int letter;
    int cindex;
    //char* ctext[len];
    //printf("%d\n", len);
    char* uppers[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                       "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char* lowers[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
                       "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    printf("ciphertext: ");
    argc -= 1;
    for (int i = 0; i <= end ; i++)
    {
        // Encrypt lowercase

        if (pt[i] <= 122 && pt[i] >= 97)
        {
            //printf("a\n");
            cindex = 97 - argc;
            letter = pt[i] - cindex;
            if (letter > 25)
            {
                do
                {
                    letter %= 26;
                }
                while (letter > 25);
            }
            //ctext[i] = lowers[letter];
            printf("%s", lowers[letter]);
        }
        // Encrypt uppercase
        else if (pt[i] <= 90 && pt[i] >= 64)
        {
            //printf("b\n");
            cindex = 64 - argc;
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
