/*
 * Filename: rotate.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that rotates the 64-bit mask.
 * Date: 4-26-2015
 * Sources of Help: Class Handouts, PA0 instructions,discussion slides, class
 *                  Piazza page
 */
    .global rotate         ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here
        FOUR_OFFSET=4;	   ! Offset for second 32-bit mask
        MASK_OFFSET= 26;   ! Offset to mask last 6 bits
	SIG_OFFSET= 31;    ! Offset for most significant bit
    .section ".text"       ! The text segment begins here

/*
 * Function name: rotate()
 * Function prototype: void rotate(unsigned long mask[], int rotateCnt);
 * Description: Rotates the current 64-bit mask by rotateCnt places. Rotates
 * left if rotateCnt is positive, right if it is negative.
 * Parameters:
 *      arg1: unsigned long mask[] -- the current 64-bit mask to rotate
 *      arg2: int rotateCnt -- the number of places to rotate mask[]. Only
 *                             the lower 6 bits are used.
 * Side Effects: Rotates mask[] by rotateCnt places.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- the 64-bit mask
 *      %i1 - Arg2 -- the number of places to rotate
 *      %l0 - local register for first mask
 *      %l1 - local register for second mask
 *      %l2 - local register for rotateValue
 */

rotate: 
        save   %sp, -96, %sp           ! Save caller's window.
      	ld     [%i0], %l0              ! Load mask[0]
        ld     [%i0+FOUR_OFFSET], %l1  ! Load mask[1]
        sll    %i1, MASK_OFFSET, %l2   ! Shift 26 bits left so the last 6
                                       ! are saved 
        srl    %l2, MASK_OFFSET, %l2   ! Shift 26 bits right
        cmp    %l2, 0                  ! Check if rotateValue is 0
        be     end                     ! If rotateValue is 0 then branch to
                                       ! end
        nop                            ! Delay slot
	
left_loop:
        srl   %l0, SIG_OFFSET, %l3     ! Get most significant bit of 1st mask
        srl   %l1, SIG_OFFSET, %l4     ! Get most significant bit of 2nd mask
        sll   %l0, 1, %l0              ! Shift the first mask 1 bit left
        or    %l0, %l4, %l0            ! Add the most significant bit from
                                       ! second mask to the end
        sll   %l1, 1, %l1              ! Shift the second mask 1 bit left
        or    %l1, %l3, %l1            ! Add the most significant bit from
                                       ! first mask to the end
        dec   %l2                      ! Decrement rotateValue
        cmp   %l2, 0                   ! Compare rotateValue and 0
        bg    left_loop                ! If rotateValue is larger then loop
        nop                            ! Delay slot

end:	
        st %l0, [%i0]                  ! Store rotated first mask in mask[0]
        st %l1, [%i0+4]                ! Store rotated second mask in mask[1]
        ret                            ! Return from subroutine
        restore                        ! Restore caller's window
