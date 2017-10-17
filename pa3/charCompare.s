/*
 * Filename: charCompare.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that compares two pointers to characters and returns
 *              a value corresponding to which one is larger.
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides,
 *                  class Piazza page
 */
    .global charCompare    ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here
   	NEG=-1;            ! Negative 1
    .section ".text"       ! The text segment begins here

/*
 * Function name: charCompare()
 * Function prototype: int charCompare(const void *lhs, const void *rhs)
 * Description: Takes two pointers to characters and compares them. The
 *              function is a leaf subroutine.
 * Parameters:
 *      arg1: const void *lhs- pointer to character
 *      arg2: const void *rhs- pointer to character
 * Side Effects: Two pointers to characters are compared.
 * Error Conditions: None. 
 * Return Value: Returns -1 if first char is smaller, +1 if the first char
 *               is larger, 0 if they are the same.
 * Registers Used:
 *      %o0 - Arg1 -- the pointer to char
 *      %o1 - Arg2 -- the pointer to char
 */

charCompare:
        ldub    [%o0], %o0       ! Load character
        ldub    [%o1], %o1       ! Load character
        cmp     %o0, %o1         ! Compare o0 and o1
        bg      firstLarger      ! Branch to firstLarger if o0 is larger
        nop                      ! Delay slot

        cmp     %o0, %o1         ! Compare o0 and o1
        bl      secondLarger     ! Branch to secondLarger if o1 is larger
        nop                      ! Delay slot

        mov     0, %o0           ! Return 0 if equal
        ba      end              ! Branch always to end
        nop                      ! Delay slot

firstLarger:
        mov     1, %o0           ! Return 1 since first char is greater
        ba      end              ! Branch always to end
        nop                      ! Delay slot

secondLarger:
        mov     NEG, %o0         ! Return -1 since second char is greater

end:
        retl
        nop
