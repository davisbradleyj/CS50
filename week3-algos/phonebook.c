#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  string names[4] = {"EMMA","BRAD","RODRIGO","DAVID"};
  string numbers[4] = {"415-555-0100","415-555-0101","415-555-0102","415-555-0103"};

  for (int=0; i<4; i++)
  {
    if (strcmp(names[i], "EMMA") == 0)
    {
      printf("%s\n", names[i]);
      printf("%s\n", numbers[i]);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}