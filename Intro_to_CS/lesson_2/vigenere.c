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
    if (islower(c) || isupper(c))
    {
        // Obtain index of c from uppers or lowers, compare strings, return index
        int n;
        printf("%c ", c);
        for (n = 0; n < 26; n++)
        {
            char * str1 = &c;
            char * str2 = lowers[n];
            char * str3 = uppers[n];
            if (strcmp(str1, str2) == 0)
            {
                printf("lwer %s ", lowers[n]);
                printf(" n %i ", n);
                return n;
                //break;
            }
            else if (strcmp(str1, str3) == 0)
            {
                //printf("%s ", uppers[i]);
                //printf("%i ", i);
                return n;
                //break;
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
                int j = 0;
                printf("ciphertext: ");

                for (int i = 0; i <= end ; i++)

                {
                    // Skip over spaces, digits, and puntuation
                    printf("i is %i j is %i ", i, j);
                    if (isspace(pt[i]) || isdigit(pt[i]) || ispunct(pt[i]))
                    {
                        printf("%c", pt[i]);
                        j -= 1;
                        printf("key %i ", j);
                    }
                    // Check for letters to encipher
                    else if (islower(pt[i]) || isupper(pt[i]))
                    {
                        int crypt_key = shift(pt[i]);
                        printf("crypt %i ", crypt_key);
                    // Keyword encryption
                        if (i != j)
                        {
                            if (j < i_input)
                            {
                                key = shift(argv[1][j]);
                                printf("key %i ", key);
                            }
                            else
                            {
                                int vj = j % i_input;
                                key = shift(argv[1][vj]);
                                printf("key %i ", key);
                            }
                        }
                        else if (i == j && i >= i_input)
                        {
                            int vi = i % i_input;
                            printf("vi %i arg %c ", vi, argv[1][vi]);
                            key = shift(argv[1][vi]);
                            printf("key %i ", key);
                        }
                        else if (i == j && i < i_input)
                        {
                            key = shift(input[i]);
                            printf("baz key %i ", key);
                        }
                        // Encipher letter in plaintext
                        //char ept = pt[i] + key;
                        // Print cipher
                        //printf("%c", ept);
                        int cipher = key;
                        cipher %= 26;
                        //cipher += crypt_key;
                        printf("cipher %i ", cipher);
                        if (islower(pt[i]))
                        {
                            printf("%s ", lowers[cipher]);
                        }
                        else if (isupper(pt[i]))
                        {
                            printf("%s", uppers[cipher]);
                        }
                    }
                    j ++;
                }
                printf("\n");
                running = false;
                break;
            }
        }
    }
    return 0;
}


