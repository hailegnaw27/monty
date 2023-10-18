#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char buffer[MAX_BUFFER_SIZE];
    FILE *file;
   
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        line_number++;

        /* Tokenize the line to get the opcode and argument */
        /* TODO: Implement the logic to tokenize the line */

        /* TODO: Execute the opcode based on the tokenized line */
    }

    fclose(file);
    /* TODO: Free the stack */

    return 0;
}

