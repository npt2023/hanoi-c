#ifndef STACK_H
#define STACK_H

#include "hanoi.h"

/* Write a macro named top that takes the name of a 
 * tote and evaluates into the thing stored at the
 * top of the stack
 */

/* Write prototypes for allocating a stack.
 *
 * The push function will take a pointer to a tote structure
 * and push a disk of a specified width onto its stack using
 * memory reallocation.
 *
 * It will then increment the height variable by one.
 *
 */

bool push(tote_t * tote, int width);

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

/* The poppush function will pop a disc from source
 * tote and push it onto a destination tote 
 *
 * It will return true if the operation was
 * successful, or false if it wasn't */

bool poppush(tote_t * src, tote_t * dst);

/* The get_top function will return the top element
 * on the stack in the tote. If it is empty, return 0 */
int get_top(tote_t * tote);

#endif
