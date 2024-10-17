#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }

    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // look for first three bytes of JPEG through the memory card.
    unsigned char buffer[512];
    int count = 0;
    char filename[8];
    FILE *outptr = NULL;

    while (fread(buffer, 1, 512, inputFile) == 512)
    {
        sprintf(filename, "%03i.jpg", count);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                if (outptr != NULL)
                {
                    fclose(outptr);
                    outptr = NULL;
                    count++;
                    sprintf(filename, "%03i.jpg", count);

                    outptr = fopen(filename, "w");
                    fwrite(buffer, 1, 512, outptr);
                }
                else
                {
                    outptr = fopen(filename, "w");
                    fwrite(buffer, 1, 512, outptr);
                }
            }
        }
        else if (outptr != NULL)
        {
            fwrite(buffer, 1, 512, outptr);
        }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    fclose(inputFile);
}
