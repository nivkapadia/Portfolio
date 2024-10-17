#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // prompting user for input
    string s = get_string("Text: ");

    // counting letters words and sentences

    float words = count_words(s);
    float L = (count_letters(s) / words) * 100; // number of letters per 100 words
    float S = (count_sentences(s) / words) * 100; // number of sentences per 100 words


    // calculating index
    float index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau index
    int i = round(index); // converting index to round number


    // printing the results
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (i >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (i > 1 && i < 16)
    {
        printf("Grade %i\n", i);
    }
}

// to count the number of letters
int count_letters(string s)
{
    int length = strlen(s);
    int lettercount = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i]))
        {
            lettercount += 1;
        }
    }
    return lettercount;
}
// to count the number of words
int count_words(string s)
{
    int length = strlen(s);
    int spaces = 1;
    for (int i = 0; i < length; i++)
    {
        if (isspace(s[i]))
        {
            spaces += 1;
        }
    }
    return spaces;
}

// to count the number of sentences
int count_sentences(string s)
{
    int length = strlen(s);
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '?' || s[i] == '.' || s[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}