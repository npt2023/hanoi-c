#ifndef STACK_H
#define STACK_H

#include "hanoi.h"

/* Write prototypes for allocating a stack.
 *
 * The push function will take a pointer to a tote structure
 * and push a disk of a specified width onto its stack using
 * memory reallocation.
 *
 * It will then increment the height variable by one.
 *
 */

void push(tote_t * tote, int width);

/*
 * The pop function will decrement the height
 * stored in a tote structure by one, and return
 * the width of the disk stored on the top of the
 * stack.
 *
 * If the stack is empty, write an error message
 * and exit the program.
 *
 */

int pop(tote_t * tote);

#endif
