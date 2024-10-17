#include <stdio.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Invalid format\n");
        return 1;
    }

    char *outfile = argv[2];

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("could not open file\n");
        return 1;
    }

    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    bf.bfType = 0x100;
    bf.bfSize = 72;
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 11;

    bi.biSize = 72;
    bi.biWidth = 3;
    bi.biHeight = 3;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biSizeImage = 0;
    bi.biClrImportant = 0;

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bf, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE x, y, z;
    x.rgbtRed = 0xff;
    x.rgbtGreen = 0xff;
    x.rgbtBlue = 0xff;

    y.rgbtRed = 0xff;
    y.rgbtGreen = 0xff;
    y.rgbtBlue = 0xff;

    y.rgbtRed = 0xff;
    y.rgbtGreen = 0xff;
    y.rgbtBlue = 0xff;

    fwrite(&x, sizeof(RGBTRIPLE), 1, outptr);
    fwrite(&z, sizeof(RGBTRIPLE), 1, outptr);
    fwrite(&y, sizeof(RGBTRIPLE), 1, outptr);
}