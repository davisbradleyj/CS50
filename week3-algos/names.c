#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  // statically entered array
  string names[4] = {"EMMA","BRAD","RODRIGO","DAVID"};

  // linear search
  for (int i=0; i<4; i++)
  {
    if (strcmp(names[i], "EMMA") == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not Found\n");
  return 1;
}