int get_args(char *in, char **argv, int max_args)
{
  // Initialize number of arguments
  int argc = 0;
  // Extract arguments
  while (1)
  {
      // Get a token, and set 'in' to NULL for next time
      char *token = strtok(in, " ");
      in = NULL;
      // Done if no more tokens
      if (!token)
      break;
      // One more token
      argv[argc] = strdup(token);
      argc++;
      // Check if maximum number of tokens was reached
      if (argc >= max_args)
      break;
  }
      // Return number of arguments
      return argc;
}

/* FUNCTION TO PRINT ARGUMENTS */
void print_args(int argc, char **argv)
{
    int i;
    for(i=0;i<argc;i++)
	  printf("\nargv[%d]='%s'",i,argv[i]);
    printf("\n");

}

/* MAIN FUNCTION */

int main() 
{   
        char s[200]; 
        char *argv[10];
        int argc;

        printf("\nEnter a string:");
      	fgets(s, sizeof(s), stdin);
	      argc=get_args(s,argv,10);
        print_args(argc, argv);
        return 0;
}                 
