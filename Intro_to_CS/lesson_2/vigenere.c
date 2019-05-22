#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* uppers[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                                   "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
char* lowers[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
                                   "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Vigenere's cipher will encrypt letters with a sequence key of letters with shift values
int shift(char c)
{
    char * str1 = &c;
    if (islower(c) || isupper(c))
    {
        // Obtain index of c from uppers or lowers, compare strings, return index
        for (int i = 0; i < 26; i++)
        {
            char * str2 = lowers[i];
            char * str3 = uppers[i];
            if (strcmp(str1, str2) == 0)
            {
                //printf("%s ", lowers[i]);
                //printf("%i ", i);
                return i;
            }
            else if (strcmp(str1, str3) == 0)
            {
                //printf("%s ", uppers[i]);
                //printf("%i ", i);
                return i;
            }
        }
    }
    return 0;
}


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // Check for usage of argv[1]
    //printf("%s\n", argv[1]);
    char* input = argv[1];
    int i_input = strlen(argv[1]);
    bool running = true;
    if (running)
    {
    //printf("running\n");
        for (int ii = 0; ii < i_input; ii++)
        {
            //Check keyword
            if (isspace(argv[1][ii]) || isdigit(argv[1][ii]))
            {
                printf("Usage: ./vigenere keyword\n");
                //running = false;
                // Out of loop after one print statement
                break;
            }

            else
            {
                //Lowercase is difference of +32 uppercase ASCII
                string pt = get_string("plaintext: ");
                int len = strlen(pt);
                int end = len - 1;
                int key;
                printf("ciphertext: ");

                for (int i = 0; i <= end ; i++)
                {
                    if (isspace(pt[i]) || isdigit(pt[i]) || ispunct(pt[i]))
                    {
                        i = i - 1;
                        printf("%c", pt[i]);
                    }
                    else if (islower(pt[i]) || isupper(pt[i]))
                    {
                    // Keyword encryption
                        if (i >= i_input)
                        {
                            int v = i % i_input;
                            key = shift(argv[1][v]);
                            //printf("%i %i ", key, i);
                        }
                        else if (i < i_input)
                        {
                            key = shift(argv[1][i]);
                        //printf("%i %i ", key, i);
                        }
                        // Encipher letter in plaintext
                        char ept = pt[i] + key;
                        // Print cipher
                        printf("%c", ept);
                    }
                }
                printf("\n");
                running = false;
                break;
            }
        }
    }
    return 0;
}


