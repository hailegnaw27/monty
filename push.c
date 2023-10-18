#include "monty.h"

/* `push` function implementation */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " "); /* get argument from input */
    int n; /* will store the integer value of the argument */

    /* Check if the argument is a valid integer */
    if (!is_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer */
    n = atoi(arg);

    /* Create new node and push to stack */
    if (!add_node(stack, n))
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}
