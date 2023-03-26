#include "stack.h"


/* 
 *
 * The push function will take a pointer to a tote structure
 * and push a disk of a specified width onto its stack using
 * memory reallocation.
 *
 */

void push(tote_t * tote, int width)
{

    /* Dynamically reallocate the stack */
    ASSERT(tote->stack = realloc(tote->stack, (sizeof(int) * (tote->height)+1)))

    /* push a disk of width width on to the stack */

    tote->stack[tote->height++] = width;

}

int pop(tote_t * tote) {
    int returnVal;
    if(tote->height == 0) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    returnVal = tote->stack[--tote->height];

    /* Shrink the memory allocated for the stack) */

    ASSERT(tote->stack = realloc(tote->stack, sizeof(int) * tote->height+1))
    return returnVal;

}

