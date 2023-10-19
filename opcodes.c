#include "monty.h"

void execute_instruction(char *tokens[], unsigned int line_number, stack_t **stack)
{
    int i;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {NULL, NULL}
    };

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(tokens[0], instructions[i].opcode) == 0)
        {
            if (strcmp(tokens[0], "push") == 0)
            {
                if (tokens[1] == NULL)
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }

                value = atoi(tokens[1]);
            }

            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens[0]);
    exit(EXIT_FAILURE);
}
