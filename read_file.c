#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <sys/types.h>

#define DELIMS " \t\n\a\r"

void read_file(char *filename)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    stack_t *stack = NULL;
    char *tokens[2];

    char *token; /* Declare token variable here */

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        line_number++;

        token = strtok(line, DELIMS);
        tokens[0] = token;

        if (tokens[0] == NULL || tokens[0][0] == '#')
            continue;

        token = strtok(NULL, DELIMS);
        tokens[1] = token;

        execute_instruction(tokens, line_number, &stack);
    }

    free_stack(stack);
    fclose(fp);
    if (line)
        free(line);
}

