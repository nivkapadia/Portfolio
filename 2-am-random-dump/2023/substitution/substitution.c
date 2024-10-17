#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validation(int argc, string s);

int main(int argc, string argv[])
{
    if (validation(argc, argv[1]) == false)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string pt = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            if (isalpha(pt[i]))
            {
                if(isupper(pt[i]))
                {
                    int x = (pt[i] - 65) % 26;
                    printf("%c", toupper(argv[1][x]));
                }
                else if(islower(pt[i]))
                {
                    int y = (pt[i] - 97) % 26;
                    printf("%c", tolower(argv[1][y]));
                }
            }
            else
            {
                printf("%c", pt[i]);
            }
        }
        printf("\n");
    }
}

bool validation(int argc, string s)
{
    bool check = true;
    if (argc != 2)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(s[i]) == false && strlen(s) != 26)
        {
            return false;
        }
        else if (isalpha(s[i]) && strlen(s) == 26)
        {
            for (int j = 1; j < 25; j++)
            {
                if (s[i] == s[j])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return check;
}