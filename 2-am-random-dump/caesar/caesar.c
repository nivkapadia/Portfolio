#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool checkstring(string argv);

int main(int argc, string argv[])
{
    char smallindex[26], upperindex[26];

    // defining variables
    string plaintext;
    int storeint, i, length, key, ciphertext;

    // Validating user input
    if (argc != 2 || checkstring(argv[1]) == true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // alphabetical index
    for (int j = 0; j < 26; j++)
    {
        upperindex[j] = j + 65;
        smallindex[j] = j + 97;
    }

    // prompt user for input
    plaintext = get_string("Plaintext:  ");
    // length of plaintext
    length = strlen(plaintext);
    // OUTPUT
    printf("Ciphertext: ");
    // cipher key
    key = atoi(argv[1]);

    // a loop that converts plaintext to ciphertext
    for (i = 0; i < length; i++)
    {
        // convert ASCII to alphabetical index
        int cu = (plaintext[i] + key - 65) % 26; // cipher upper
        int cs = (plaintext[i] + key - 97) % 26; // cipher lower

        // for all alphabets
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", upperindex[cu]);
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", smallindex[cs]);
            }
        }
        // for everything other than alphabet like punctuations
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

// rejects non-numeric arguments like 1x or 20x
bool checkstring(string argv)
{
    // length of string
    int i = strlen(argv);
    bool check = false;
    for (int j = 0; j < i; j++)
    {
        if (argv[j] >= '0' && argv[j] <= '9')
        {
            check = false;
        }
        else
        {
            check = true;
            break;
        }
    }
    return check;
}