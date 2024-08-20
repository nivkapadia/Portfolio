#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(char bit);
int binary = 0;

int main(void)
{
    // TODO
    string s = get_int("Message: "); // prompting for input
    char bits[8]; // array that will hold bits of each character in string

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int x = s[i];
        for (int j = 0; j < 8; j++)
        {
            int z = x % 2; // converting dec2bin
            if (z == 0)
            {
                bits[j] = 0;
                x /= 2;
            }
            else
            {
                bits[j] = 1;
                x /= 2;
            }
        }

        //This loop will print. (can't do it in the J loop because it assings value in reverse)
        for (int k = 7; k >= 0; k--)
        {
            print_bulb(bits[k]);
        }
        printf("\n");
    }
}
void print_bulb(char bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
