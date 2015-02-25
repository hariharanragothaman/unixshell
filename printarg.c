#include <stdio.h>
#include <string.h>
void print_args(int argc, char **argv)
{
    int i;
    for (i = 0; i < argc; i++)
    printf("argv[%d] = '%s'\n", i, argv[i]);
}

int main(int argc, char **argv)
{
    print_args(argc, argv);
    return 0;
} 
