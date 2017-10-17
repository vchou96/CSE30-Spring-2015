/*
 * Filename: main.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Example C program for pa0. It calls a couple of functions
 *              written in assembly and C as examples if function calls and
 *              parameter passing in C and SPARC assembly (also known as
 *              the language's and architecture's calling conventions).
 * Date: 4-6-2015
 * Sources of Help: Class Handouts, PA0 instructions, class Piazza page
 */

/*
 * Header files included here.
 * Std C Lib header files first, then local headers.
 */

/* Standard C Library headers use angle brackets < > */
#include <stdlib.h>
#include <stdio.h> /*added this header so fprintf and printf have function
                     declarations*/

/* Local headers use double quotes " " */
#include "pa0.h"
#include "pa0_strings.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
                                or
 *                     int main( void ); if no command line processing.
 * Description: C main driver which calls C and SPARC assembly routines to
 *              print a greeting, assignment due date, and the square of the
 *              number entered at the command line.
 * Parameters: int containing the number to square
 * Side Effects: Outputs greeting, assignment due date, and square of a number
 * Error Conditions: None.
 * Return Value: 0 indicating succesful execution.
 */

int
main ( int argc, char *argv[] ) {
  struct DueDate dueDate;     /* Structure to hold assignment due date */
  int argVal = 0;             /* Value to square from command line */

  /*
   * We decrement argc because the name of the program is the first
   * argument which we do not want to count.
   */
  --argVal;
  --argc;/*decrement argc so we do not count the program's name*/

  if ( argc != EXPECTED_ARGS ) {
    /* Error messages are printed to stderr */
    (void) fprintf(
      stderr,
      argc < EXPECTED_ARGS ? STR_ERR_MISSING_ARG : STR_ERR_EXTRA_ARG,
      argv[0] );

    (void) fprintf( stderr, STR_ERR_USAGE, argv[0] );

    return EXIT_FAILURE;
  }

  /*
   * strtol() offers error checking/handling. See: man strtol
   */
  argVal = atol( argv[1] );

  /*
   * Updates the assignment due date.
   */
  dueDate.day = SEVEN;/*SEVEN is 7, defined in pa0.h*/
  dueDate.year = YEAR;/*YEAR is 2015, defined in pa0.h*/
  dueDate.month = "April";

  /*
   * Print the greeting message
   */
  printWelcome( STR_WELCOME_QUARTER );

  /*
   * Print assignment due date
   * printDueDate() takes the address of the DueDate struct
   * (a pointer to the DueDate struct)
   */
  printDueDate( &dueDate );

  /*
   * Now square the input and print the result
   */
  (void) printf( STR_SQUARENUM, argVal, squareNum( argVal ) );

  return EXIT_SUCCESS;
}
