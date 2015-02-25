void readCommand(char *line, struct Command *command)
{
      // Read sub-command lines
      command->num_sub_commands = 0;
      while (1)
      {
        // Get next command
        char *sub_line = strtok(line, "|");
        line = NULL;

        // No more commands
        if (!sub_line)
        break;

        // Save it
        command->sub_commands[command->num_sub_commands].line = strdup(sub_line);
        command->num_sub_commands++;
      }

      // Split lines in arguments
      int i;
      for (i = 0; i < command->num_sub_commands; i++)
        readArgs(command->sub_commands[i].line, command->sub_commands[i].argv, MAX_ARGS);
}

void printCommand(struct Command *command)
{
    int i;
    for (i = 0; i < command->num_sub_commands; i++)
    {
        printf("Command %d:\n", i);
        printArgs(command->sub_commands[i].argv);
        printf("\n");
    }
}
