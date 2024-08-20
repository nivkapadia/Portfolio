#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_int("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0) // look for candidate called name
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // sort the number of votes of each candidate
    // TODO
    int candidatesmin1, most_votes0, most_votes1;
    candidatesmin1 = candidate_count - 1;

    // this for loop sends the candidate with most votes at the end of the array.
    for (int i = 0; i < candidate_count - 1; i++)
    {
        /* from candidates[i].votes to candidates[candidatesmin1].votes
                find the largest number of votes */
        if (candidates[i].votes > candidates[i + 1].votes)
        {
            int storevote = candidates[i].votes; // storing the original votes of each candidate before swaping them
            int storevote1 = candidates[i + 1].votes;
            candidates[i + 1].votes = storevote;   // swapping
            candidates[i].votes = storevote1;      // swapping
            string storename = candidates[i].name; // storing the original names of each candidate before swaping them
            string storename1 = candidates[i + 1].name;
            candidates[i + 1].name = storename;
            candidates[i].name = storename1;
        }
    }
    // print the name of candidate with most votes
    // TODO
    printf("%s\n", candidates[candidate_count - 1].name);

    // check if other candidate has same number of votes
    // TODO
    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (candidates[candidate_count - 1].votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
