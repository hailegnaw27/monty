#include "monty.h"
#include <stdio.h>   /* for fgets */
#include <stdlib.h>  /* for exit */

/**
 * main - Entry point for the Monty Bytecode Interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
    FILE *fp;
    char *line = NULL, *opcode = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    instruction_t instruction;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, len, fp) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode == NULL || *opcode == '#') {
          continue;
        }
        
        instruction.opcode = opcode;
        instruction.f = NULL;

        if (strcmp(opcode, "push") == 0) {
          instruction.f = push;
        }
        else if (strcmp(opcode, "pall") == 0) {
          instruction.f = pall;
        }
        else {
          fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
          exit(EXIT_FAILURE);
        }

        instruction.f(&stack, line_number);
    }

    free_stack(&stack);
    free(line);
    fclose(fp);

    return EXIT_SUCCESS;
}
