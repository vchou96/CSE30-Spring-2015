/*
 * Filename: defaultCompare.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Compares two strings with strcmp. 
 * Date: 5-25-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides,
 *                  class Piazza page
 */
    .global defaultCompare ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here	
        NEG=-1;            ! Negative one
    .section ".text"       ! The text segment begins here

/*
 * Function name: defaultCompare()
 * Function prototype: int defaultCompare(const void* p1, const void* p2);
 * Description: Uses strcmp to compare two pointers to character arrays.
 * Parameters:
 *      arg1: const void* p1 -- Pointer to first character array
 *      arg2: const void* p2 -- Pointer to second character array
 * Error Conditions: None. 
 * Return Value: Returns positive if the first string is greater, negative
 *               if the second string is greater, 0 if the strings are equal.
 * Registers Used:
 *      %i0 - Arg1 -- Pointer to first character array
 *      %i1 - Arg2 -- Pointer to second character array
 *      %o0 - Used to pass first argument to strcmp
 *      %o1 - Used to pass second argument to strcmp
 */

defaultCompare:
        save    %sp, -96, %sp         ! Save caller's window 
        mov     %i0,%o0               ! Move in %o0 register
        mov     %i1,%o1               ! Move in %o1 register
        call    strcmp                ! Call strcmp function 
        nop                           ! Delay slot
	
        cmp     %o0, 0                ! If strings are equal
        be      equal                 ! Branch to equal branch
        nop                           ! Delay slot

        cmp     %o0, 0                ! If first mismatch is greater in %i0
                                      ! than %i1
        bg      greater               ! Branch to greater branch
        nop                           ! Delay slot

        mov     NEG, %i0              ! Return negative value
        ba      end                   ! Branch always to end
        nop                           ! Delay slot

equal:
        mov     0, %i0                ! Return 0 since strings are same
        ba      end                   ! Branch always to end
        nop                           ! Delay slot

greater: 
        mov     1, %i0                ! Return positive

end:
        ret                           ! Return from subroutine
        restore                       ! Restore caller window
