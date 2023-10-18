#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;
    stack_t *current;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}

