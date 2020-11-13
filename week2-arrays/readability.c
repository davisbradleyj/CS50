#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentances = 0;
    float L, S, index;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
        {
            letters++;
        }   
        else if (s[i] == ' ')
        {
            words++;
        } 
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentances++;
        }
    }
    L = (100 * ((float)letters / (float)words));
    S = (100 * ((float)sentances / (float)words));
    index = 0.0588 * L - 0.296 * S - 15.8;
//   printf("Letters: %i\n", letters); 
//   printf("Words: %i\n", words);
//   printf("Sentances: %i\n", sentances);
//   printf("L: %f\n", L);
//   printf("S: %f\n", S);
//   printf("Index: %d\n", (int) round(index));
    if (index < 1) 
    {
        printf("Before Grade 1\n");
    }
    if (index >= 1 && index <= 16) 
    {
        printf("Grade %i\n", (int) round(index));    
    }
    if (index > 16) 
    {
        printf("Grade 16+\n");    
    }
}