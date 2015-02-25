#include <stdio.h>
#include <string.h>
int main()
{
    char in[200];
    while (1)
  {
      // Show prompt and read string
      printf("$ ");
      fgets(in, sizeof in, stdin);
      // Remove last '\n' character
      in[strlen(in) - 1] = 0;
      // Print line
      printf("%s\n", in);
  }
} 
