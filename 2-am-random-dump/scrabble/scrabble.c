#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int length = strlen(word);
    int score = 0; // keeps track of score
    int j; // keeps track of POINTS index
    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                j = word[i] - 'A';
                score = score + POINTS[j];
            }
            else if (islower(word[i]))
            {
                j = word[i] - 'a';
                score = score + POINTS[j];
            }
        }
        else
        {
            score += 0;
        }
    }
    return score;
}
