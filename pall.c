#include "monty.h"

/* `pall` function implementation */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    /* Traverse the stack and print each value */
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
    (void)line_number; /* line_number is currently unused */
}
