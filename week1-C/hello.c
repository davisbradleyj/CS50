#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // instantiate string and get_string to ask name
    string name = get_string("What is your name?\n");
    
    // %s to return string (much like %i for int, or %f for float)
    printf("Hello, %s\n", name);
}