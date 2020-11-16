#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // validate commandline sent the right information
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        // validate argv[1] is actually a number
        for (int i = 0, s = strlen(argv[1]); i < s; i++) 
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: %s key\n", argv[0]); 
                return 1;
            }
        }
    }
    
    // make argv[1] an integer, since it checks out through validation
    int key = atoi(argv[1]);
    
    // prompt user for a plaintext message
    string text = get_string("plaintext: ");
    string c = text;
    
    // iterate over plaintext and 'shift' each letter by the key in its cypher
    for (int i = 0; i < strlen(c) ; i++)
    {
        if (c[i] >= 'a' && c[i] <= 'z') 
        {
            c[i] = 'a' + ((c[i] - 'a' + key) % 26);
        }
        else if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] = 'A' + ((c[i] - 'A' + key) % 26);
        }
    }

    printf("ciphertext: %s\n", c);
}
