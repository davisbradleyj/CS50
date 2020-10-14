#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // instantiate a float value (as input) and int count (as a counter), while value is greater than or equal to 0
    float value;
    int count = 0;
    
    do
    {
        value = get_float("Please enter changed owed: ");
    }
    while (value < 0);
    
    // convert the float which is dollars and cents into cents by multiplying by 100
    int cents = round(value * 100);
    
    // if cents is greater than 25, start subtracting that value while adding to count each time 25 is subtracted from cents
    for (; cents >= 25; cents -= 25) 
    {
        count++;
    }
    // if cents is greater than 10, start subtracting that value while adding to count each time 10 is subtracted from cents
    for (; cents >= 10; cents -= 10) 
    {
        count++;
    }
    // if cents is greater than 5, start subtracting that value while adding to count each time 55 is subtracted from cents
    for (; cents >= 5; cents -= 5) 
    {
        count++;
    }
    // if cents is greater than 1, start subtracting that value while adding to count each time 11 is subtracted from cents
    for (; cents >= 1; cents -= 1) 
    {
        count++;
    }
    // print the coin count
    printf("%i\n", count);
}