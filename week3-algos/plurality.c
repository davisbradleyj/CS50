#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

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
        string name = get_string("Vote: ");

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
    // instantiate a loop for the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if the name entered by as an argument matches those in the candidate list...
        if (strcmp(candidates[i].name, name) == 0)
        {
            // incriment that candidate's vote total by 1
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // instantiate a placeholder for most votes
    int most = 0;
    // loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // logic check to compare the candidate votes and make that the max value if appropriate
        if (candidates[i].votes > most)
        {
            most = candidates[i].votes;
        }
    }

    // loop through candidates to see where there is a value where the candidate votes is the most
    for (int i = 0; i < candidate_count; i++)
    {
        // this logical check should allow for multiple candidates if their vote total equals most
        if (candidates[i].votes == most)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

