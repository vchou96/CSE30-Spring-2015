/*
 * Filename: createMask.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that creates the two 32-bit mask values.
 * Date: 4-26-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides,
 *                  class Piazza page
 */
    .global createMask     ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here
        FOUR_OFFSET= 4;    ! Offset for second key in array	
    .section ".text"       ! The text segment begins here

/*
 * Function name: createMask()
 * Function prototype: void createMask(unsigned long keys[],
 *                     char passphrase[], unsigned long mask[]);
 * Description: Creates the two 32-bit mask values.
 * Parameters:
 *      arg1: unsigned long keys[] -- Array with the two keys
 *      arg2: char passphrase[] -- Array with the 8 chars of the passphrase
 *      arg3: unsigned long mask[] -- Array to hold the 64-bit mask.
 * Side Effects: The two 32-bit mask values are created.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- the array of keys
 *      %i1 - Arg2 -- the passphrase
 *      %i2 - Arg3 -- mask array
 *      %l0 - local register to hold first key
 *      %l1 - local register to hold first 4 chars of passphrase
 *      %l2 - local register to hold result of xor %l0 and %l1
 *      %l3 - local register to hold second key
 *      %l4 - local register to hold last 4 chars of passphrase
 *      %l5 - local register to hold result of xor %l3 and %l4
 */

createMask:
        save   %sp, -96, %sp            ! Save caller's window
        ld     [%i0], %l0               ! Load the first key
        ld     [%i1], %l1               ! Load the first 4 chars of passphrase
        xor    %l0, %l1, %l2            ! xor %l0 and %l1 and store result
                                        ! in %l2
        st     %l2, [%i2]               ! Store result in first 4 bytes
                                        ! of mask array

        ld     [%i0+FOUR_OFFSET], %l3   ! Load the second key
        ld     [%i1+FOUR_OFFSET], %l4   ! Load the last 4 chars of passphrase
        xor    %l3, %l4, %l5            ! xor %l3 and %l4 and store result
                                        ! in %l5
        st     %l5, [%i2+FOUR_OFFSET]   ! Store result in last 4 bytes of
                                        ! mask array

end:
        ret
        restore
