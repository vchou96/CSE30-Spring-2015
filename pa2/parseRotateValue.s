/*
 * Filename: parseRotateValue.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Parses the rotate value from string input and stores it into
 *              the long that rotateValue points to. 
 * Date: 4-26-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
    .global parseRotateValue   ! Declares the symbol to be globally visible so
                               !  we can call the function from other modules.
    .global errno              ! Declares errno
    .section ".bss"            ! bss section begins here
    .align 4                   ! aligns 4
    .skip 4                    ! skips 4

    .section ".data"           ! The data segment begins here
        ENDPTR_OFFSET = 4;     ! Offset for endptr is 4 
	BASE= 10;              ! Base is always 10

    .section ".text"           ! The text segment begins here

/*
 * Function name: parseRotateValue()
 * Function prototype: int parseRotateValue(char *str, long *rotateValue);
 * Description: Parses the rotation value. Sets the rotateValue and returns 0
 *              for successful parsing.
 * Parameters:
 *      arg1: char *str -- the string to parse
 *      arg2: long *rotateValue -- the rotateValue to set.
 * Side Effects: Parses the rotation value.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: Retruns 0 if successful, ERANGE_ERR if errno is set to
 *               non-zero, ENDPTR_ERR if endptr points to non-null char, and
 *               BOUND_ERR if out of range.
 * Registers Used:
 *      %i0 - Arg1 -- the string
 *      %i1 - Arg2 -- the rotation value
 *      %o0 - param 1 for strtol & return value
 *      %o1 - param 2 for strtol
 *      %o2 - param 3 for strtol
 *      %l0 - local register 
 *      %l1 - local register
 *      %l2 - local register
 *      %g0 - global variable
 */

parseRotateValue: 
        save   %sp, -(92+ENDPTR_OFFSET) & -8, %sp   ! save space for char
                                          ! *endptr
        set    errno, %l0                 ! Address of where errno storage is
        st     %g0, [%l0]                 ! Dereference to set value to 0
        mov    %i0, %o0                   ! Store str in %o0
        add    %fp, -ENDPTR_OFFSET, %o1   ! Store  in %o1
        mov    BASE, %o2                  ! Store DEF_BASE in %o2
        call   strtol                     ! Call strtol with %o0, %o1, and %o2
        nop                               ! as arguments
                                          ! Delay slot
        set    errno, %l0                 ! Load address of errno
        ld     [%l0], %l0                 ! Get value of errno
        cmp    %l0, %g0                   ! Compare errno and 0 
        be     errnoSame                  ! Opposite logic to branch to
                                          ! errnoSame
        nop                               ! Delay slot

errnoError:
        set    ERANGE_ERR_G, %i0          ! Returns ERANGE_ERR since errno is
	                                  ! non-zero
        ld     [%i0], %i0                 ! Load value of %i0
        ba     end                        ! Branch always to end
        nop                               ! Delay slot

errnoSame:
        ld     [%fp - ENDPTR_OFFSET], %l1  ! gets us the value of endptr
        ldub   [%l1], %l1                  ! dereference it to get the
        cmp    %l1, %g0                    ! char; check if it is ''0'
        be     endptrSame                  ! if '\0', no endptr error
        nop                                ! Delay slot

endptrError:
        set    ENDPTR_ERR_G, %i0           ! Returns ENDPTR_ERR since endptr
	                                   ! points to
                                           ! non-null character
        ld     [%i0], %i0                  ! Load value of %i0 
        ba     end                         ! Branch always to end
        nop                                ! Delay slot

endptrSame:
        set    MIN_ROTATE_G, %l2           ! Store MIN_ROTATE_G in %l2
	ld     [%l2], %l2                  ! Load value of %l2
	cmp    %o0, %l2                    ! Compare %o0 and minimum rotate
	                                   ! range
        bl     out_of_range                ! If smaller then branch to out of
	                                   ! range case
        nop                                ! Delay slot
        
	set    MAX_ROTATE_G, %l2           ! Store MIN_ROTATE_G in %l2
	ld     [%l2], %l2                  ! Load value of %l2
	cmp    %o0, %l2                    ! Compare %o0 and maximum rotate
	                                   ! range
	bg     out_of_range                ! If larger then branch to out of
	                                   ! range case
	nop                                ! Delay slot

        mov    0, %i0                      ! Returns 0 for successful
	ba     end                         ! Branch to end
	nop                                ! Delay slot

out_of_range:
        set    BOUND_ERR_G, %i0            ! Returns BOUND_ERR for out of range
        ld     [%i0], %i0                  ! Load value of %i0
end:    
        ret                                ! Return from subroutine
        restore                            ! Restore caller's window
        
