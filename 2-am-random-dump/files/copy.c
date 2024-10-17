#include <cs50.h>
#include <stdio.h>

int main(void)
{
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        return 1;
    }

    FILE *outFile = fopen("output.txt", "w");

    char buffer[6];
    fread(buffer, 1, 5, inputFile);
    fwrite(outFile, 1, 5, buffer);
}
