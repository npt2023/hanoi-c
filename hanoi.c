/* Write an algorithm in C that solves the Tower of Hanoi problem */
/* The iterations of the algorithm are in the notebook,
 * implement a recursive solution to the problem
 */

/* Include a file that has all the headers we need and a macro
 * named ASSERT that checks to see if memory allocation is
 * successful
 *
 * The header defines the data structures we need to solve
 * the problem.
 *
 */

#include "hanoi.h"



/* Here is the basic idea behind the data structure: */

/* Due to C compile-time restrictions on global variables,
 * I will have to write a function that initializes the
 * problem. This broken initialization will be left here
 * as a reference */

/* 
tote_t hanoi_problem[3] = {
    {
        .height = 3,
        .stack = (int *)malloc(sizeof(int) * 3)
    },
    {
        .height = 0, .stack = (int *)malloc(sizeof(int) * 3)
    },
    {
        .height = 0, .stack = (int *)malloc(sizeof(int) * 3)
    }
};
*/

/* Include a header file that provides functions for manipulating
 * the stack in the tote data structure
 */

#include "stack.h"

/* void initialize_problem(tote_t * problem, int num_disks)
 *
 * Initialize the Hanoi problem set. 
 *
 * This function takes a pointer to a tote
 * structure and the number of disks for the problem,
 * and then allocates an array of three totes.
 * It then dynamically allocates the stack for the hanoi
 * structure, and pushes the number of disks onto the stack.
 *
 *
 */


void initialize_problem(tote_t ** problem, int num_disks)
{
    int i;
    tote_t * tote_ptr; 

    /* Dynamically allocate a structure for three totes */

    ASSERT(*problem = \
            malloc(sizeof(tote_t) * 3))

    /* Add some readability */
    
    tote_ptr = *problem; 

    /* Initialize the height in each tote structure to 0 */

    for(i = 0; i < 3; i++) {
        tote_ptr[i].height = 0;
    }
    
}


int main(void)
{
    
}

