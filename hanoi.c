/* Steven Sweet
 *
 * April 2023
 *
 * Self Study
 *
 */

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

/* Include a header file that provides functions for manipulating
 * the stack in the tote data structure
 */

#include "stack.h"


/* Implement the hanoi problem as a global array of three
 * tote data structures */

tote_t * hanoi_problem;
int num_moves;

int main(void)
{
    int i;

    /* Allocate memory hanoi problem, push
     * 3 disks onto the stack */
#define NUM_DISKS 8

    initialize_problem(NUM_DISKS);
    

    h(0, NUM_DISKS);
    print_problem(hanoi_problem);
    printf("This problem was solved in %d moves\n", num_moves);

}
/* Write a function that solves the hanoi problem recursively */
/* We are trying to solve a specific and well defined task. 
 * The mathematical recurrence for the Tower of Hanoi
 * problem is Tn = 2Tn-1+1, which means we are moving the
 * n-1 smallest disks from the first tote onto some other tote,
 * then moving the n largest onto the last tote, and then
 * again moving the n-1 smallest onto the last tote */

/* The function poppush(tote_t * src, tote_t * dst) should be used
 * to facilitate moving the top disc to another tote */

#define TOT(x) (&hanoi_problem[(x)])

int h(int srcIndex, int height)
{

    /* Basis case: Tote1 and Tote2 are emtpy */

    if(hanoi_problem[0].height == 0 && hanoi_problem[1].height == 0) return 0;

    /* Keep calling ourselves recursively for all frames of the tote */

    if(height == 0) return 0;
    else h(srcIndex, height-1);

    /* Basis case: Tote1 and Tote2 are emtpy */

    if(hanoi_problem[0].height == 0 && hanoi_problem[1].height == 0) return 0;

    /* We need to know if the tote holds an odd or
     * even number of discs, across three different 
     * totes. This leads to six possible operations
     * of poppush. They include:
     *
     *   
     * Tote0:
     * If n is odd:
     * poppush(0, 2);
     * else poppush(0, 1);
     *
     * Tote1:
     * If n is odd
     * poppush(1, 2);
     * else poppush(1, 0);
     *
     * Tote2:
     * If n is odd
     * poppush(2, 1);
     * else poppush(2, 0);
     *
     * Let n = hanoi_problem[srcIndex].height
     *
     * If poppush fails, call ourselves recursively onto dstIndex
     *
     */

    print_problem(hanoi_problem);

    if(is_odd(hanoi_problem[srcIndex].height)) 
    {
        switch(srcIndex) 
        {
            case 0: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(0), TOT(2)) ? 1 : h(2, hanoi_problem[2].height);
                        break;
                    }
            case 1: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(1), TOT(2)) ? 1 : h(2, hanoi_problem[2].height);
                        break;
                    }
            case 2: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(2), TOT(1)) ? 1 : h(1, hanoi_problem[1].height);
                        break;
                    }
            default: break;
        }
    } 
    else 
    {
        switch(srcIndex) 
        {
            case 0: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(0), TOT(1)) ? 1 : h(1, hanoi_problem[1].height);
                        break;
                    }
            case 1: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(1), TOT(0)) ? 1 : h(0, hanoi_problem[0].height);
                        break;
                    }
            case 2: {
                        /* If poppush succeeds, return 1, else call ourselves recursively */
                        poppush(TOT(2), TOT(0)) ? 1 : h(0, hanoi_problem[0].height);
                        break;
                    }
            default: break;
        }
    } 

    if(hanoi_problem[srcIndex].height == 0) {
        switch(srcIndex) {
            case 2: {
                        h(0, hanoi_problem[0].height);
                        break;
                    }
            case 1: {
                        h(0, hanoi_problem[0].height);
                        break;
                    }
            case 0: {
                        h(1, hanoi_problem[1].height);
                        break;
                    }
            default: break;
        }
    } else return 1;
}




/* 
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
 *
 */



void initialize_problem(int num_disks)
{
    int i;

    /* Dynamically allocate a structure for three totes */

    ASSERT(hanoi_problem = \
            malloc(sizeof(tote_t) * 3))

    /* Add some readability */
    

    /* Initialize the height in each tote structure to 0 */

    for(i = 0; i < 3; i++) {
        hanoi_problem[i].height = 0;
    }
    
    /* push num_disks onto the stack */
    
    for(i = 0; i < num_disks; i++) {
        push(hanoi_problem, num_disks - i);
    }     
}

/* Write a function that destroys the contents of the hanoi 
 * array. It takes the first element in the array and walks
 * it, freeing each stack using the pop() function.
 * It then frees each array element using it's address
 *
 */

void destroy_problem(tote_t * problem) {

    int i;

    /* Free the stack in each tote */
    
    for(i = 0; i < 3; i++) {
        while(problem[i].height) {
            pop(&problem[i]);
        }
    }

    /* Free the pointer */
    /* NOTE: You can only free a pointer allocated by malloc
     * due to heaps. You can't free a block of memory within
     * something bigger allocated by malloc */

    free(problem);
}

/* Write a function that sleeps the program for xxxx milli-
 * seconds */

void msleep(useconds_t milliseconds) {
    usleep(milliseconds * 1000);
}

/* Write a function that prints the contents of the hanoi
 * totes */
/* Example output:
 *
Tote1:          Tote2:          Tote3:
Height: 0       Height: 0       Height: 3
Contents:       Contents:       Contents:

*/

void print_problem(tote_t * problem) {
    int i, j;
    char * char_ptr;
    int shiftHeight;
    
    int maxHeight[3];

    
    /* Store "Height: XX" plus null character */

    char height_str[11] = "Height: ";
        
    /* Use %-xxxs to format each row. */

    printf("%-15s%-15s%-15s\n", "Tote1:", "Tote2:", "Tote3");

    /* Print the height of each tote */

    for(i = 0; i < 3; i++) {
        maxHeight[i] = problem[i].height;
        char_ptr = strchr(height_str, ' ');
        sprintf(char_ptr+1, "%d", problem[i].height);
        printf("%-15s", height_str);
        
    }

    /* Set a variable used to print each stack inline with each
     * other
     */

    shiftHeight = MAX(maxHeight[0], maxHeight[1], maxHeight[2]);

    printf("\n");

    for(i = 0; i < 3; i++) {
        printf("%-15s", "Contents:");
    }

    /* Print the contents of each tote */

    putchar('\n'); 
    
    /*
     * 
     * print the contents of each stack row by row
     * from the top down. 
     *
     * if the stack of a tote is done being printed, or
     * if it is empty, print 15 whitespaces
     *
     * continue printing these rows until the printing
     * requirements for the tallest stack are fulfilled
     *
     * print shorter stacks inline with taller stacks
     *
     */
    for(;;) {
        if(!maxHeight[0] && !maxHeight[1] && !maxHeight[2]) {
            break;
        }
        for(i = 0; i < 3; i++) {
            if(maxHeight[i] == 0 || (shiftHeight - maxHeight[i]) > 0) {
                printf("%-15c", ' ');
                continue;
            } 
             
            printf("%-15d", problem[i].stack[--maxHeight[i]]);
        }
        shiftHeight--;
        putchar('\n');
    }
    putchar('\n');
    printf("------------------------------------------");
    putchar('\n');
}

bool is_odd(int n) {
    if(!(n % 2)) {
        return false;
    } else {
        return true;
    }
}
