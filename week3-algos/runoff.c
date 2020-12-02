#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
bool vote(int voter, int rank, string name)
{
    // instantiate a loop for the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if a candidate is correctly named in the election
        if (strcmp(candidates[i].name, name) == 0)
        {
            // the value of i represents the preference number for that voter and rank
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // loop through count of voter count
    for (int i = 0; i < voter_count; i++)
    {
        // loop through candidate count
        for (int j = 0; j < candidate_count; j++)
        {
            // instantiate and integer to represent the voter preference
            int choice = preferences[i][j];
            // if candidate is still active...
            if (candidates[choice].eliminated == false)
            {
                // increase vote total for that candidate
                candidates[choice].votes++;
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // should be the candidate with a vote count greater than voter_count/2
    // loop through candidate_count, and print the name of the candidate with greater than 50% of votes, or return false
    for (int i = 0; i < candidate_count; i++)
    {
        // set condition as mentioned above
        if (candidates[i].votes > (voter_count / 2))
        {
            // print name of candidate, as mentioned above
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // set a temp value for the low number of votes (such as the voter_coutn)
    int minVotes = voter_count;
    // loop through any remaining candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate has fewer votes than minVote and is still in the race...
        if (candidates[i].votes < minVotes && candidates[i].eliminated == false)
        {
            // replace the count of minVotes with candidate[i]'s votes
            minVotes = candidates[i].votes;
        }
    }
    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // instantiate placeholder integers for number of candidates running and the number of candidates that have the minimum number of votes
    int votes = 0;
    int running = 0;

    // loop through candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        // set condition candidate is still running and candidate has min votes
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            // increment votes and running
            votes++;
            running++;
        }
        // check for condition where candidate is running but does not have min votes
        else if (candidates[i].eliminated == false)
        {
            //increment running only
            running++;
        }
    }

    // if there is a tie, running and votes should be the same value
    if (votes == running)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // loop through remaining candidates to find the candidate with a vote total = min
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            // reset eliminated status to 'true'
            candidates[i].eliminated = true;
        }
    }
    return;
}
