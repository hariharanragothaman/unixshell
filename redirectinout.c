struct Command
{
    struct SubCommand sub_commands[MAX_SUB_COMMANDS];
    int num_sub_commands;
    char *stdin_redirect;
    char *stdout_redirect;
    int background;
};

void readRedirectsAndBackground(struct Command *command)
{
    // Assume no redirects and no background
    command->stdin_redirect = NULL;
    command->stdout_redirect = NULL;
    command->background = 0;

    // Nothing if no sub-commands available
    if (!command->num_sub_commands)
    return;

    // Get last sub-command
    struct SubCommand *sub_command = &command->sub_commands[command->num_sub_commands - 1];

    // Keep extracting tokens from the last subcommand
    while (1)
    {
      // Count number of arguments left
      int argc = 0;
      while (sub_command->argv[argc])
      argc++;

      // Extract redirect/background tokens
      if (argc > 2 && !strcmp(sub_command->argv[argc - 2], ">"))
      {
        command->stdout_redirect = sub_command->argv[argc - 1];
        sub_command->argv[argc - 2] = NULL;
      }

      else if (argc > 2 && !strcmp(sub_command->argv[argc - 2], "<"))
      {
        command->stdin_redirect = sub_command->argv[argc - 1];
        sub_command->argv[argc - 2] = NULL;
      }

      else if (argc > 1 && !strcmp(sub_command->argv[argc - 1], "&"))
      {
        command->background = 1;
        sub_command->argv[argc - 1] = NULL;
      }
    
      else
      {
        // No more redirects/background
        break;
      }
  }
}
