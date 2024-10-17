#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./Usage inputfile outputfile\n");
        return 1;
    }

    if (fopen(argv[1], "r") == NULL)
    {
        printf("empty file\n");
        return 1;
    }

    char *infile = argv[1];
    char *outfile = argv[2];

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("could not open %s\n", infile);
        return 1;
    }

    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("could not open %s\n", outfile);
        return 1;
    }

    char buffer[11];
    char *number[4];

    int i = 0;
    while (fread(&buffer, 11, 1, inptr) != 0)
    {
        buffer[10] = '\0';

        strcpy(number[i], buffer);
        i++;
    }

    long numbers[4];
    for (int j = 0; j < 4; j++)
    {
        numbers[j] = atol(number[j]);
    }

    fwrite(&numbers, 10, 1, outptr);
}