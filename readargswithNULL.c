void readArgs(char *in, char **argv, int size)
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
        {
          // Null-terminated array
          argv[argc] = NULL;
          break;
        }

        // One more token
        argv[argc] = strdup(token);
        argc++;

        // Check if maximum number of tokens was reached
        if (argc >= size)
        {
          // Null-terminate
          argv[size - 1] = NULL;
          break;
        }
    }
}
