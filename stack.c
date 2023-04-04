#include "stack.h"


/* 
 *
 * The push function will take a pointer to a tote structure
 * and push a disk of a specified width onto its stack using
 * memory reallocation.
 *
 */

extern int num_moves;

bool push(tote_t * tote, int width)
{

    /* Dynamically reallocate the stack */
    ASSERT(tote->stack = realloc(tote->stack, (sizeof(int) * (tote->height)+1)))

    /* push a disk of width width on to the stack */

    tote->stack[tote->height++] = width;
    return true;
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

bool poppush(tote_t * src, tote_t * dst) {


    if(get_top(src) > get_top(dst)) {
        return false;
    }

    num_moves++;

    return push(dst, pop(src));

}

int get_top(tote_t * tote) {
    return tote->height > 0 ? tote->stack[tote->height-1] : 100;

}
