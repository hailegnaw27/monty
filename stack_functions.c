#include "monty.h"

int value = 0;

#define UNUSED(x) (void)(x)

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;
    UNUSED(line_number);

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = value;
    new->prev = NULL;
    if (*stack == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = *stack;
        (*stack)->prev = new;
    }

    *stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    UNUSED(line_number);

    temp = *stack;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

