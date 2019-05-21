#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
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
            //printf("broken cont'd\n");
            if (isspace(argv[1][ii]) || isalpha(argv[1][ii]))
            {
                printf("Usage: ./caesar key\n");
                //running = false;
                // Out of loop after one print statement
                break;
            }

            else
            {
                //Lowercase is difference of +32 uppercase ASCII
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
                        //printf("%d", letter);
                        if (letter > 25)
                        {
                            do
                            {
                                letter %= 26;
                                //printf(" %d ", letter);
                            }
                            while (letter > 25);
                        }
                        //ctext[i] = lowers[letter];
                        letter -= 1;
                        printf("%s", lowers[letter]);
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
                running = false;
                break;
            }
        }
    }
}
