/*
 * Filename: stripNewLine.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that changes a newline character in a string to a null
 *              character.
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA3 instructions, discussion slides,
 *                  class Piazza page
 */
    .global stripNewLine   ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here	
        NEWLINE= '\n';     ! Newline character
    .section ".text"       ! The text segment begins here

/*
 * Function name: stripNewLine()
 * Function prototype: void stripNewLine(char *str);
 * Description: Uses strchr() to search for a newline character in the str.
 *              If there is one, it will be changed to a null character.
 * Parameters:
 *      arg1: char *str -- the string to search in
 * Error Conditions: None. 
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- the string to search in.
 *      %o0 - Used to pass string to strchr
 *      %o1 - Used to pass second argument to strchr
 */

stripNewLine:
        save    %sp, -96, %sp         ! Save caller's window 
	mov     %i0, %o0              ! Move %i0 to %o0
        mov     NEWLINE, %o1          ! Move '\n' in %o1
        call    strchr                ! Call strchr() with the string and
	                              ! '\n' as arguments
        nop                           ! Delay slot

        cmp     0, %o0                ! Check if return value is null pointer
        be      end                   ! If it is then branch to end
        nop                           ! Delay slot

        stb     %g0, [%o0]            ! Replace newline with null character

end:
	ret
	restore
