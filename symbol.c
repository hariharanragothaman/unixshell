/* HEADER FILES REQUIRED */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* MAIN FUNCTION*/
int main(int argc, char **argv)
{
	/* INFINITE LOOP TILL USER EXITS */
	int j;
	char L[20]; 
	for(;;)
	{
		printf("$");			/* Printing the terminal symbol */ 
		fgets(L,20,stdin);		/* User I/P from keyboard */
		
		for(j=0;j<=(strlen(L)-1);j++)	/* Printing String */
		printf("%c",L[j]); 
	
		continue;		
	}

	return 0;
}
