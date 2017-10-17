/*
 * Filename: printUsage.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that prints the usage messages.
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides,
 *                  class Piazza page
 */
    .global printUsage     ! Declares the symbol to be globally visible so
                           ! we can call the function from other modules.

    .section ".data"       ! The data segment begins here
    .section ".text"       ! The text segment begins here

/*
 * Function name: printUsage()
 * Function prototype: void printUsage(const char *programName);
 * Description: Prints the usage message to stderr.
 * Parameters:
 *      arg1: const char *programName
 * Side Effects:
 * Error Conditions: None. 
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- The program name to print in usage message
 *      %o0 -  -- 1st argument (output stream) for fprintf
 *      %o1 -  -- 2nd argument (Usage string) for fprintf
 *      %o2 -  -- 3rd argument (program name) for fprintf
 */

printUsage:
        save    %sp, -96, %sp         ! Save caller's window 
        set     StandardErr, %o0      ! Set StandardErr label in %o0
        ld      [%o0], %o0            ! Ld %o0 in %o0
        set     STR_USAGE_G,%o1       ! Set STR_USAGE_G label in %o1
        ld      [%o1], %o1            ! Load %o1 register into %o1
	mov     %i0, %o2              ! Mov program name in %o2 register
        call    fprintf               ! Call fprintf with %o0, %o1, and %o2
	                              ! as arguments
        nop                           ! Delay slot
	
	ret                           ! Return from subroutine
        restore                       ! Restore caller window
