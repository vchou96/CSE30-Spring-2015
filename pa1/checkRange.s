/*
 * Filename: checkRange.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Checks that the value argument is within the range of
                minRange and maxRange exclusively.
 * Date: 4-11-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides
 */
    .global checkRange    ! Declares the symbol to be globally visible so
                          ! we can call the function from other modules.

    .section ".text"      ! The text segment begins here

/*
 * Function name: checkRange()
 * Function prototype: int checkRange ( long minRange, long maxRange,
 *                                      long value );
 * Description: Checks that value is within the range of minRange and maxRange
 * Parameters:
 *      arg1: long minRange -- the min value that arg3 can be, exclusive
 *      arg2: long maxRange -- the max value that arg3 can be, exclusive
 *      arg3: long value -- the value to check
 * Side Effects: Outputs whether value is within the two ranges.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: Nonzero for true that value is within the ranges, zero for
 *               false.
 * Registers Used:
 *      %i0 - arg1 -- the min range
 *      %i1 - arg2 -- the max range
 *      %i2 - arg3 -- the value
 *      %o0 - param 1 -- copy of arg1 being passed in
 *      %o1 - param 2 -- copy of arg2 being passed in
 *      %o2 - param 3 -- copy of arg3 being passed in
 */

checkRange: 
        save   %sp, -96, %sp   ! Save caller's window; if different than -96
	                       ! then comment on how that value was calculated.
        mov     %i0, %o0       ! Arg1 stored in %o0
	mov     %i2, %o2       ! Arg3 stored in %o2
        cmp     %o0, %o2       ! Compare if minRange is larger than value
	bge     else           ! If larger then branch over to else
	nop                    ! Delay slot
	
        mov     %i1, %o1       ! Arg2 stored in %o1
	cmp     %o2, %o1       ! Compare if value is larger than maxRange
        bge     else           ! If larger then to branch over to else
	nop                    ! Delay slot

        mov     1, %i0         ! Store non-zero value as return value for true
        ba      end_if         ! Take end_if branch
	nop                    ! Delay slot
        
else: 
        set     0, %i0         ! Store zero as return value for false

end_if:
        ret                    ! Return from subroutine
        restore                ! Restore caller's window; in "ret" delay slot
