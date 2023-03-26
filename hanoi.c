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



int main(void)
{
    int i;
    /* Create an array of three tote structures */
    tote_t * hanoi_problem; 
    initialize_problem(&hanoi_problem, 3);

    /* Test to see if the function worked */
    /* Do the following: Print the height of each tote structure */

    for(i = 0; i < 3; i++) {
        printf("%4d", hanoi_problem[i].height);
    }

    printf("\n");
    printf("\n\n");
    /* Print the contents of the stack */
    for(i = 0; i < 3; i++) {
        printf("%4d\n", pop(&hanoi_problem[0]));
    }

    destroy_problem(hanoi_problem);

}


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
    
    /* push num_disks onto the stack */
    
    for(i = 0; i < num_disks; i++) {
        push(tote_ptr, num_disks - i);
    }     
}

/* Write a function that destroys the contents of the hanoi 
 * array. It takes the first element in the array and walks
 * it, freeing each stack using the pop() function.
 * It then frees each array element using it's address
 *
 */

void destroy_problem(tote_t * problem) {
    int i, j;

    /* Free each stack */
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < problem[i].height; j++) {
            pop(&problem[i]);
        }
    }

    /* Free the pointer */
    /* NOTE: You can only free a pointer allocated by malloc
     * due to heaps. You can't free a block of memory within
     * something bigger allocated by malloc */

    free(problem);
}
