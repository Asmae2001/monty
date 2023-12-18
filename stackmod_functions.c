#include "monty.h"
#include <stdio.h>

// Declare a custom function to check if a character is ASCII
int is_ascii(int ch);

/**
 * pchar - Function to print the first character on the top of the stack.
 * @stk: Stack
 * @linenum: Line number
 * Return: void
 */
void pchar(stack_t **stk, unsigned int linenum)
{
    if (stk == NULL || *stk == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", linenum);
        exit(EXIT_FAILURE);
    }

    if (is_ascii((unsigned char)(*stk)->n))
        printf("%c\n", (*stk)->n);
    else
    {
        fprintf(stderr, "L%d: can't pchar, value out of ASCII range\n", linenum);
        exit(EXIT_FAILURE);
    }
}

/**
 * pstr - Function to print a string.
 * @stk: Stack
 * @linenum: Unused
 * Return: void
 */
void pstr(stack_t **stk, __attribute__((unused)) unsigned int linenum)
{
    stack_t *str;

    if (stk == NULL || *stk == NULL || (*stk)->n == 0)
    {
        printf("\n");
        return;
    }

    str = *stk;

    while (str != NULL && str->n != 0 && is_ascii(str->n))
    {
        printf("%c", str->n);
        str = str->next;
    }
    printf("\n");
}

/**
 * rotl - Function to rotate the stack from top to bottom once.
 * @stk: Stack
 * @linenum: Unused
 * Return: void
 */
void rotl(stack_t **stk, __attribute__((unused)) unsigned int linenum)
{
    stack_t *new;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    new = *stk;

    while (new->next != NULL)
        new = new->next;

    new->next = *stk;
    (*stk)->prev = new;
    *stk = (*stk)->next;
    (*stk)->prev = NULL;
    new->next->next = NULL;
}

/**
 * rotr - Function to rotate the stack from bottom to top once.
 * @stk: Stack
 * @linenum: Unused
 * Return: void
 */
void rotr(stack_t **stk, __attribute__((unused)) unsigned int linenum)
{
    stack_t *rev;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    rev = *stk;

    while (rev->next != NULL)
        rev = rev->next;

    rev->next = *stk;
    rev->prev->next = NULL;
    rev->prev = NULL;
    (*stk)->prev = rev;
    *stk = rev;
}

/**
 * is_ascii - Custom function to check if a character is ASCII.
 * @ch: Character
 * Return: 1 if ASCII, 0 otherwise
 */
int is_ascii(int ch)
{
    return ch >= 0 && ch <= 127;
