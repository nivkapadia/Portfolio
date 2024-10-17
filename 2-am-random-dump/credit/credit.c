#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_number(void);
long countdigits(long n);
int lastdigit(long number);

int main(void)
{
    //prompt user for input
    long number = get_number();
    long nu1 = number;

    // calculates the number of digits
    int digits = countdigits(number);
    //printf("%i\n", digits);

    // loop get every alternate digit and multiply it with 2
    int store = 0;
    long nu = number / 10;
    for (int j = 0; j < digits; j += 2)
    {
        int first_digit, second_digit, m, multiply, k;
        k = lastdigit(nu);
        nu = nu / 100;
        multiply = k * 2;
        m = multiply / 10; // to calculate last digit
        second_digit = lastdigit(multiply);
        first_digit = m % 10;
        if (second_digit > 0)
        {
            int sum = first_digit + second_digit;
            store += sum;
        }
        else
        {
            store += first_digit;
        }
    }
    int store1 = 0;
    for (int m = 0; m < digits; m += 2)
    {
        int k = lastdigit(nu1);
        nu1 /= 100;
        store1 += k;
    }
    int sum = store + store1;

    // checking the conditions
    long digmin1 = digits - 1;
    digmin1 = pow(10, digmin1);
    long starts_with = number / digmin1;
    long digmin2 = digits - 2;
    long second_digit = pow(10, digmin2);
    second_digit = number / second_digit;
    second_digit = lastdigit(second_digit); // gives us second digit of the number
    starts_with = lastdigit(starts_with); // gives us the first digit of the number

    // checking the last digit of sum
    int lastdigsum = lastdigit(sum); // checking the last digit of sum
    if (lastdigsum == 0)
    {
        // vaild criteria if last digit is zero
        if (digits == 13 && starts_with == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (digits == 15 && starts_with == 3 && second_digit == 4)
        {
            printf("AMEX\n");
            return 0;
        }
        else if (digits == 15 && starts_with == 3 && second_digit == 7)
        {
            printf("AMEX\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 5 && second_digit == 1)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 5 && second_digit == 2)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 5 && second_digit == 3)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 5 && second_digit == 4)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (digits == 16 && starts_with == 5 && second_digit == 5)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (lastdigsum != 0 || digits < 13 || digits > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

//function to prompt user for input
long get_number(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    return n;
}

//function that counts the number of digits
long countdigits(long n)
{
    long i = 0;
    do
    {
        n = n / 10;
        i++;
    }
    while (n != 0);
    return i;
}

int lastdigit(long number)
{
    return number % 10;
}