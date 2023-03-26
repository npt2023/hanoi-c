#ifndef HANOI_H
#define HANOI_H

#include <stdlib.h>
#include <stdio.h>

#define ASSERT(x) if((x) == NULL) { \
    printf("Error: Malloc failed to allocate\n"); \
    exit(EXIT_FAILURE); \
}

/* Implement the hanoi problem using an array of 
 * three tote data structures. Each tote should
 * contain the number of disks stored in it,
 * as well as a stack containing the size of 
 * each disk.
 *
 * For example, a game initialized with three disks will
 * have somewhat of this initialization (below the tote struct):
 *
 */

typedef struct {
    int height;
    int * stack;
} tote_t;

void initialize_problem(tote_t ** problem, int num_disks);

#endif
