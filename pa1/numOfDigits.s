/*
 * Filename: numOfDigits.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Counts the number of base digits in the argument.
 * Date: 4-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides
 */
    .global numOfDigits    ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here
        MIN_BASE = 2;      ! Define min base as 2
        MAX_BASE = 36;     ! Define max base as 36
	
    .section ".text"       ! The text segment begins here

/*
 * Function name: numOfDigits()
 * Function prototype: int numOfDigits ( long num, int base );
 * Description: Counts the number of base digits in argument.
 * Parameters:
 *      arg1: long nume -- the argument to count the number of base digits of
 *      arg2: int base -- the base in which we count the number of digits
 * Side Effects: Outputs number of digits in the particular base.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: Nonzero for true that value is within the ranges, zero for
 *               false.
 * Registers Used:
 *      %i0 - Arg1 -- the number
 *      %i1 - Arg2 -- the base
 *      %o0 - param 1 -- copy of MIN_BASE, copy of Arg1
 *      %o1 - param 2 -- copy of MAX_BASE, copy of Arg2
 *      %l0 - local register -- increments each time a loop executes
 */

numOfDigits: 
        save   %sp, -96, %sp   ! Save caller's window; if different than -96
                               ! then comment on how that value was calculated.
        mov    MIN_BASE, %o0   ! MIN_BASE stored in %o0
        mov    MAX_BASE, %o1   ! MAX_BASE stored in %o1
        dec    %o0             ! Decrement o0 since numOfDigits is inclusive
        inc    %o1             ! Increment o1 since numOfDigits is inclusive
        mov    %i1, %o2        ! Arg2 stored in %o2
        call   checkRange      ! Call checkRange function to check if %o2 is
                               ! in acceptable range  
        nop                    ! Delay slot for call instruction

        cmp    %o0, 1          ! Check if return value of checkRange is nonzero
        bne    out_of_range    ! Opposite logic test to take out_of_range
                               ! branch
        nop                    ! Delay slot

        clr    %l0             ! initialize l0 to 0
        mov    %i1, %o1        ! store number (Arg1) in o1
        mov    %i0, %o0        ! store base (Arg2) in o0
        cmp    %o0, 0          ! Compare if o0 is equal to 0
        bne    loop            ! opposite logic test to take loop branch
        nop                    ! Delay slot

        mov    1, %i0          ! set return value as 1 since 0 case
        ba     end             ! take end branch
        nop                    ! Delay slot

out_of_range:
        mov    -1, %i0         ! set return value as -1 since out-of-range case
        ba     end             ! take end branch
        nop                    ! Delay slot

loop:
        inc    %l0             ! increment %l0, the number of loop executions
        mov    %o0, %o0        ! store o0 in o0
        mov    %o1, %o1        ! store o1 in o1
        call   .div            ! Call div function on o0 and o1
        nop                    ! Delay slot for call instruction
  
        cmp    %o0, 0          ! Compare if o0 is equal to 0
        bg     loop            ! opposite logic test to execute loop again
        nop                    ! Delay slot

end_loop:
        mov    %l0, %i0        ! set %l0 as return value

end:
        ret                    ! Return from subroutine
        restore                ! Restore caller's window; in "ret" delay slot
