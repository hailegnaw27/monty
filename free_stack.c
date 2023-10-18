#include "monty.h"

/* `free_stack` function implementation */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    /* Traverse the stack and free each node */
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
