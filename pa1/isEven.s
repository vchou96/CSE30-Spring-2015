/*
 * Filename: isEven.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Checks if a long int argument is even. Returns non-zero
                value if even to indicate true, 0 if odd to indicate false.
 * Date: 4-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
    .global isEven    ! Declares the symbol to be globally visible so we can
                      ! call the function from other modules.
    .section ".data"  ! The data segment begins here
        TWO = 2;

    .section ".text"  ! The text segment begins here

/*
 * Function name: isEven()
 * Function prototype: int isEven ( long num );
 * Description: Checks if long is even or not. Returns nonzero for true,
                zero for false.
 * Parameters:
 *      arg1: char ch -- the character to print
 * Side Effects: Outputs true or false for whether the num is even.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: Nonzero for true, zero for false.
 * Registers Used:
 *      %i0 - arg1 -- the num passed in to this function
 *      %o0 - param 1 to printf() -- copy of arg1 being passed in
 *      %o1 - local register -- stores value of 2 to mod o0 with
 */

isEven:
    save    %sp, -96, %sp    ! Save caller's window; if different than -96
                             ! then comment on how that value was calculated.
    mov     %i0, %o0         ! Argument stored in %o0
    mov     TWO, %o1         ! 2 stored in local register
    call    .rem             ! Calls modulus subroutine to mod o0 by l0
    nop                      ! Delay slot
    
    cmp     %o0, 0           ! Compares result of modding with 0 
    bne     else             ! If the remainder is not 0, go to else branch
    nop                      ! Delay slot

    mov     1, %i0           ! Moves 1 to i0
    ba      end_if           ! Take end_if branch
    nop                      ! Delay slot

else:     
    mov     0, %i0           ! Store 0 in i0
   
end_if:
    ret                      ! Return from subroutine
    restore                  ! Restore caller's window; in "ret" delay slot
