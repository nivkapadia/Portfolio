#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = 0;
            average += round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //STORING VALUES
            float originalRed = image[i][j].rgbtRed;
            float originalBlue = image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;

            /*storing values in different variables because of int overflow
              Because it is possible that the values of these calculation is bigger than 255.
              The image[i][j].rgbt uses uint8_t which can count maximum upto 255.*/

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// SWAP FUNCTION FOR REFLECTION
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp_r = *a;
    *a = *b;
    *b = tmp_r;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // rows
    {
        int x = width / 2;
        for (int j = 0; j < x; j++) // columns
        {
            /*We divide width  by 2 because for example:
            we take an image with width of 5 pixels,
            the loop will swap the 1st and 2nd pixel with 5th and 4th respectively,
            3rd pixel remain as it is because it is in the center,
            now when it gets to 4th pixel, which is now the 2nd pixel it gets swaped again*/
            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
    return;
}

double ravg = 0;
double gavg = 0;
double bavg = 0;
void average(RGBTRIPLE *a)
{
    ravg += a->rgbtRed;
    gavg += a->rgbtGreen;
    bavg += a->rgbtBlue;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avg[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i + 1][j]);
                average(&image[i][j + 1]);
                average(&image[i + 1][j + 1]);

                ravg /= 4;
                bavg /= 4;
                gavg /= 4;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else if (i == height - 1 && j == 0)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i - 1][j]);
                average(&image[i][j + 1]);
                average(&image[i - 1][j + 1]);

                ravg /= 4;
                bavg /= 4;
                gavg /= 4;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else if (i == height && j == width)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i - 1][j]);
                average(&image[i][j - 1]);
                average(&image[i - 1][j - 1]);

                ravg /= 4;
                bavg /= 4;
                gavg /= 4;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else if (i == 0 && j == width)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i + 1][j]);
                average(&image[i][j - 1]);
                average(&image[i + 1][j - 1]);

                ravg /= 4;
                bavg /= 4;
                gavg /= 4;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else if (i == 0)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i + 1][j]);
                average(&image[i][j - 1]);
                average(&image[i + 1][j - 1]);
                average(&image[i + 1][j + 1]);
                average(&image[i][j + 1]);

                ravg /= 6;
                bavg /= 6;
                gavg /= 6;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else if (j == 0)
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i + 1][j]);
                average(&image[i][j + 1]);
                average(&image[i + 1][j + 1]);
                average(&image[i - 1][j + 1]);
                average(&image[i - 1][j]);

                ravg /= 6;
                bavg /= 6;
                gavg /= 6;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
            else
            {
                ravg = 0;
                bavg = 0;
                gavg = 0;

                average(&image[i][j]);
                average(&image[i - 1][j]);
                average(&image[i][j - 1]);
                average(&image[i - 1][j - 1]);
                average(&image[i][j + 1]);
                average(&image[i - 1][j + 1]);
                average(&image[i + 1][j + 1]);
                average(&image[i + 1][j - 1]);
                average(&image[i + 1][j]);

                ravg /= 9;
                bavg /= 9;
                gavg /= 9;

                avg[i][j].rgbtRed = round(ravg);
                avg[i][j].rgbtGreen = round(gavg);
                avg[i][j].rgbtBlue = round(bavg);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = avg[i][j];
        }
    }
    return;
}