#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validation(string s);


int main(int argc, string argv[])
{
    // validates the user input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    bool validate = validation(argv[1]);
    if (validate == 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string pt = get_string("plaintext:  "); // pt is short for plaintext


    //implementing the code for ciphertext
    printf("ciphertext: ");
    int length = strlen(pt);
    string key = argv[1]; // because you can't use argv[1[index]]
    int index; // for indexing in alphabetical order

    for (int i = 0; i < length; i++)
    {
        if (isupper(pt[i]))
        {
            // converting pt to aplhabetical index
            index = pt[i] - 'A';
            // if it is uppercase, print the corresponding letter in uppercase as well
            printf("%c", toupper(key[index]));
        }
        else if (islower(pt[i]))
        {
            // converting pt to aplhabetical index
            index = pt[i] - 'a';
            // if it is lowercase, print the corresponding letter in lowercase as well
            printf("%c", tolower(key[index]));
        }
        else // for spaces and punctuations
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}

// function for validating user input
bool validation(string s)
{
    bool check;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if ((length == 26 && s[i] >= 'A' && s[i] <= 'Z') || (length == 26 && s[i] >= 'a' && s[i] <= 'z'))
        {
            for (int j = 1; j < length; j++)
            {
                if (s[i] == s[j])
                {
                    check = false;
                    break;
                }
                else
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }
    return check;
}