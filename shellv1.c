/**************   SHELL IMPLEMENTATION  *******************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>


int status;
pid_t pid, w;

/**************     GETTING ARGUMENTS  ***********************/


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

/**************     PRINT  ARGUMENTS  ***********************/

/* FUNCTION TO PRINT ARGUMENTS */
void print_args(int argc, char **argv)
{
    int i;
    for(i=0;i<argc;i++)
	  printf("\nargv[%d]='%s'",i,argv[i]);
    printf("\n");

}

/***************   MAIN IMPLEMENTATION **********************/
void changedir()
{
	char newDirectory[255];
	getcwd(newDirectory, 255); //set newDirectory to current directory
	pid_t pid;      
	pid = fork();

	if(pid == 0)
	{   //child execution       
	    strcpy(newDirectory, "/");
	    exit(0);
	}

	else if (pid < 0)
	{                  
    	   printf( "Error!\n");    
    	   exit(1);
	}

	else
	{                       
     	   pid = waitpid(pid, NULL, 0);   
	}
	printf("%s\n", newDirectory);
	chdir(newDirectory);
}

int main()
{
   char s[200];
   char *argv[10];
   int argc;	

	while(1)
	{
		printf("shell$>");
		memset(argv,0,10);
		fgets(s, sizeof(s), stdin);	      	

		char *nw=strchr(s,'\n');
 		//searching and replacing new line character
        	if(nw)
                *nw=0;
	
		argc=get_args(s,argv,10);

		if(argv[0] == NULL)
		continue;

		if(!strcmp(argv[0],"exit"))
		{
			break;
		}

		if(!strcmp(argv[0],"cd"))
                {
                        changedir();
                }


		else
		{
			int ret = fork();
			if(ret==0)
			{
				execvp(argv[0],argv);
				printf("command not valid");
			}
			else
			{
				int w =wait(NULL);
			}
		}
	}
		print_args(argc, argv);		
	

}
