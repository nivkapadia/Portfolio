#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name) // NO CHANGES TO BE MADE
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // for (int i = 0; i < voter_count; i++)
    // {
    //     if (!candidates[i].eliminated)
    //     {
    //         candidates[preferences[i][0]].votes++; //Increasing the vote count of the first preference of voters.
    //     }
    // }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!candidates[preferences[i][j]].eliminated) // CHECK IF THE FIRST PREFERENCE OF THE CANDIDATE IS ELIMINATED
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
            else
            {
                j++;
                while (j < candidate_count)
                {
                    if (!candidates[preferences[i][j]].eliminated)
                    {
                        candidates[preferences[i][j]].votes++;
                        break;
                    }
                    else
                    {
                        j++;
                    }
                }
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > (ceil(voter_count * 50) / 100))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO

    //NESTED LOOP FOR BUBBLE SORT
    // int counter = 1;
    // while (counter != 0)
    // {
    //     counter = 0;
    //     for (int i = 0; i < candidate_count - 1; i++)
    //     {
    //         if (!candidates[i].eliminated)
    //         {
    //             if (candidates[i].votes > candidates[i + 1].votes)
    //             {
    //                 int temp = candidates[i].votes;
    //                 candidates[i].votes = candidates[i + 1].votes;
    //                 candidates[i + 1].votes = temp;

    //                 string temp1 = candidates[i].name;
    //                 candidates[i].name = candidates[i + 1].name;
    //                 candidates[i + 1].name = temp1;

    //                 bool temp2 = candidates[i].eliminated;
    //                 candidates[i].eliminated = candidates[i + 1].eliminated;
    //                 candidates[i + 1].eliminated = temp2;
    //                 counter++;
    //             }
    //         }
    //     }
    // }

    int min_temp; //MIN TEMPORARY
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count - 1; j++)
        {
            if (!candidates[i].eliminated && !candidates[j].eliminated)
            {
                if (candidates[i].votes < candidates[j].votes)
                {
                    min_temp = candidates[i].votes;
                }
                else if (candidates[i].votes > candidates[j].votes)
                {
                    min_temp = candidates[j].votes;
                }
            }
        }
    }

    return min_temp;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    // TODO

    /*
    IF ALL THE NON ELIMINATED CANDIDATES HAVE THE SAME VOTES, RETURN TRUE
    STEPS:
    1. find out votes of all the non eliminated candidates
    2. compare them with each other
    3. if all are same, return true
    */
    int same;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            same = candidates[i].votes;
            break;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes != same)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO

    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}