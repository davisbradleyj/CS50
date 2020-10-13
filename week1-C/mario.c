#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // establish a height integer, then ask user to enter a height using 'do/while' provided the input is between 1 and 8
    int height;
    
    do
    {
        height = get_int("Enter Height: ");
    }
    while (height < 1 || height > 8);
    
    // create loop to create rows
    for (int i = 0; i < height; i++) // remember let is used for ES6... use int in C
    {
        // create loop to add in spaces and hash marks
        for (int j = 0; j < height; j++) // remember let is used for ES6... use int in C
        {
            // for first row, all indices before last index should be spaces; as the row count goes up, the amount of blank spaces should decrease
            if ((i + j) < (height - 1)) 
            {
                printf(" ");
            } 
            else 
            {
                printf("#");
            }
        }
        printf("\n"); // this will create the row for the next loop
    }
}
