/*
 * Filename: printWelcome.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Example SPARC assembly routine to print out a greeting followed
 *              by a string (student's name) passed in as an argument
 *              to this function
 *              Called from main()
 * Date: 4-6-2015
 * Sources of Help: Class Handout, PA0 instructions
 */

        .global printWelcome   ! Declares the symbol to be globally visible so
                               ! we can call this function from other modules.
        .section ".data"       ! The data segment begins here
fmt:
        .asciz "Welcome to CSE 30, %s\n"


        .section ".text"       ! The text segment begins here

/*
 * Function name: printWelcome()
 * Function prototype: void printWelcome( const char *str );
 * Description: Prints to stdout a greeting string and the argument
 *              with a terminating newline via printf()
 * Parameters:
 *      arg1: char *str -- the string to print after the greeting
 *
 * Side Effects: Outputs greeting with string supplied as argument.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: None
 *
 * Registers Used:
 *      %i0 - arg1 -- the string (char *) passed in to this function
 *
 *      *o0 - param 1 to printf() -- format string
 *      *o1 - param 2 to printf() -- copy of arg1 being passed in
 */

printWelcome: 
        save   %sp, -96, %sp   ! Save caller's window; if different than -96
	                       ! then comment on how that value was calculated.

        set    fmt, %o0        ! Format string
	mov    %i0, %o1        ! Copy of formal parameter to print
        call   printf          ! Make function call
	nop                    ! Delay slot for call instruction

	ret                    ! Return from subroutine
	restore                ! Restore caller's window; in "ret" delay slot
