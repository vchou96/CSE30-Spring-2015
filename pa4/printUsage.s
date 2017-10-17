/*
 * Filename: printUsage.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Prints long usage message to stdout depending on the argument
 *              passed in.
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides,
 *                  class Piazza page
 */
    .global printUsage     ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here	

    .section ".text"       ! The text segment begins here

/*
 * Function name: printUsage
 * Function prototype: void printUsage(const char* filename);
 * Description: Prints long usage message to stdout.
 * Parameters:
 *      arg1: const char* filename- Determines which usage message to print. 
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- determines which usage message to print
 *      %o0 - Holds 1st argument for fprintf
 *      %o1 - Holds 2nd argument for fprintf
 *      %o2 - Holds 3rd argument for fprintf
 */

printUsage:
        save    %sp, -96, %sp         ! Save caller's window 
        
        set     standardOut, %o0      ! Set %o0 register as standardOut 
        ld      [%o0], %o0            ! Load %o0 register in %o0
        set     longUsage, %o1        ! Set %o1 register as longUsage
        ld      [%o1], %o1            ! Load %o1 register into %o1
        mov     %i0, %o2              ! Move 1st argument into %o2 register
        call    fprintf               ! Call fprintf
        nop                           ! Delay slot

        ret                           ! Return from subroutine
        restore                       ! Restores caller window
