#ifndef HANOI_H
#define HANOI_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ASSERT(x) if((x) == NULL) { \
    printf("Error: Malloc failed to allocate\n"); \
    exit(EXIT_FAILURE); \
}

#define MAX(x, y, z) ( \
       (x) > (y) && (x) > (z) ? (x) : \
       (y) > (x) && (y) > (z) ? (y) : \
       (z))

#define LEAST(x, y, z) ( \
      (x) < (y) && (x) < (z) ? (x) : \
      (y) < (x) && (y) < (z) ? (y) : \
      (z))

#define MEDIAN(x, y, z) ( \
       (x) > (y) && (y) > (z) ? (y) : \
       (x) > (z) && (z) > (y) ? (z) : \
       (y) > (x) && (x) > (z) ? (x) : \
       (y) > (z) && (z) > (x) ? (z) : \
       (z))

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

void initialize_problem(int num_disks);

/* Write a function that solves the hanoi problem
 * recursively */

int h(int srcIndex, int height);

/* Write a function that prints the contents
 * of the hanoi stacks */

void print_problem(tote_t * problem);

/* Write a function that delays the program by xxxx
 * milliseconds */

void msleep(useconds_t milliseconds);

/* Write a function that destroys the contents of the hanoi 
 * array. It takes the first element in the array and walks
 * it, freeing each stack using the pop() function.
 * It then frees each array element using it's address
 *
 */

void destroy_problem(tote_t * problem);
bool is_odd(int n);

#endif
