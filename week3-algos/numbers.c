#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // statically entered array
  int numbers[6] = {4,8,15,16,23,42};

  // linear search
  for (int i=0; i<6; i++)
  {
    if (numbers[i] == 50)
    {
      printf("Found\n");
    }
  }
  printf("Not Found\n");
}