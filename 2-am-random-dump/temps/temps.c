// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);
void swap(int temp, int temp1);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here
    // SELECTION SORT
    /*
    int min, st;
    string s;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (temps[j].temp < temps[i].temp)
            {
                st = temps[j].temp;
                temps[j].temp = temps[i].temp;
                temps[i].temp = st;

                s = temps[j].city;
                temps[j].city = temps[i].city;
                temps[i].city = s;
            }
        }
    }
    */

    //BUBBLE SORT
    int st;
    string s;
    int counter = 1;
    while (counter != 0)
    {
        int i = 0;
        counter = 0;
        while (i < 9)
        {
            if (temps[i+1].temp < temps[i].temp)
            {
                st = temps[i+1].temp;
                temps[i+1].temp = temps[i].temp;
                temps[i].temp = st;
                counter++;
            }
            i++;
        }
    }
}