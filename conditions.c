#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // prompt for x
    int x = get_int("x: ");

    // prompt for y
    int y = get_int("y: ");

    // compare variables
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y");
    }
}
