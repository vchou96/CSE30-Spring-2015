/*
 * Filename: printChar.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Prints the character argument to stdout.
 * Date: 4-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides
 */
    .global printChar      ! Declares the symbol to be globally visible so we can
                           ! call the function from other modules.
    .section ".data"
fmt:
    .asciz "%c"

    .section ".text"       ! The text segment begins here

/*
 * Function name: printChar()
 * Function prototype: void printChar( char ch );
 * Description: Prints to stdout the character argument via printf()
 * Parameters:
 *      arg1: char ch -- the character to print
 * Side Effects: Outputs character argument.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: None
 * Registers Used:
 *      %i0 - arg1 -- the char passed in to this function
 *      %o0 - param 1 to printf() -- copy of arg1 being passed in
 */

printChar: 
        save   %sp, -96, %sp   ! Save caller's window; if different than -96
	                       ! then comment on how that value was calculated.

	set    fmt, %o0
	mov    %i0, %o1        ! Copy of formal parameter to print
        call   printf          ! Make function call
	nop                    ! Delay slot for call instruction

	ret                    ! Return from subroutine
	restore                ! Restore caller's window; in "ret" delay slot

