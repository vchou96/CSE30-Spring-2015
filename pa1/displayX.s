/*
 * Filename: displayX.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Performs the actual outputting of character by calling
 * printChar(). Creates an X pattern with values inputted by user.
 * Date: 4-18-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
    .global displayX  ! Declares the symbol to be globally visible so we can
                      ! call the function from other modules.
    .section ".data"  ! The data segment begins here
        NL = '\n';    ! assembly constant for newline character
        TWO = 2;
	BASE = 10;

    .section ".text"  ! The text segment begins here

/*
 * Function name: displayX()
 * Function prototype: void displayX( long size, long xChar, long fillerChar,
 *                                    long borderChar );
 * Description: Calls printChar() to create an X pattern with values inputted
 *              by the user.
 * Parameters:
 *      arg1: long size --
 *      arg2: long xChar --
 *      arg3: long filledChar --
 *      arg4: long borderChar --
 * Side Effects: Creates an X pattern.
 * Error Conditions: None. [Arg 1 is not checked to ensure it is not NULL.]
 * Return Value: None.
 * Registers Used:
 *      %i0 - arg1 -- the size passed in to this function
 *      %i1 - arg2 -- the xChar passed in to this function
 *      %i2 - arg3 -- the fillerChar passed in to this function
 *      %i3 - arg4 -- the borderChar passed in to this function
 *      %o0 - param 1
 *      %o1 - param 2
 *      %l0 - local variable for row
 *      %l1 - local variable for column
 *      %l2- local variable for borderCnt
 */

displayX:

/*
 * Displays the top border. Border depth is based on the number of digits
 *  in the X pattern size.
 */

    save    %sp, -96, %sp    ! Save caller's window; if different than -96
                             ! then comment on how that value was calculated.
    clr     %l0              ! Row mapped to %g0
    clr     %l1              ! Col mapped to %g1
    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Calls numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    cmp     %l0, %o0         ! Compare row and the return value of numOfDigits
    bge     end_firstloop    ! Opposite logic to skip to end_firstloop branch
    nop                      ! Delay slot

first_loop: 
    mov     0, %l1           ! Store 0 in col
    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Call numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    mov     TWO, %o1         ! Store 2 in %o1
    call    .mul             ! Call .mul on %o0 and %o1
    nop                      ! Delay slot

    add     %o0,%i0,%o0      ! Add %o0 and size and store in %o0    
    cmp     %l1, %o0         ! Compare col and %o0
    bge     end_secondloop   ! Opposite logic to branch to end_secondloop
    nop                      ! Delay slot

second_loop:
    mov     %i3, %o0         ! Store borderChar in o0
    call    printChar        ! Call printChar with borderChar as argument
    nop                      ! Delay slot

    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Call numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    mov     TWO, %o1         ! Store 2 in %o1
    call    .mul             ! Call .mul on %o0 and %o1
    nop                      ! Delay slot

    mov     %i0, %o1         ! Store size in %o1
    add     %o0,%o1,%o0      ! Add %o0 and size and store in %o0
 
    inc     %l1              ! Increment the column
    cmp     %l1, %o0         ! Compare row and return value of numOfDigits
    bl      second_loop      ! If row is less then loop
    nop                      ! Delay slot

end_secondloop:
    mov     NL, %o0          ! Store NL in %o0
    call    printChar        ! Call printChar with NL as argument
    nop                      ! Delay slot

    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Calls numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    inc     %l0              ! Increment the row
    cmp     %l0, %o0         ! Compare row and %o0
    bl      first_loop       ! If row is smaller then loop
    nop                      ! Delay slot

end_firstloop:
    

/*
 * Display the X pattern with border on either side of the X.
 */

    mov   0, %l0              ! Set row as 0
    mov   %i0, %o0            ! Store size in %o0
    clr   %l2                 ! Initialize borderCnt as 0
    cmp   %l0, %o0            ! Compare row and size
    bge   end_thirdloop       ! Opposite logic to branch to end_thirdloop
    nop                       ! Delay slot

third_loop:
    mov   %i0, %o0            ! Store size in %o0
    mov   BASE, %o1           ! Store base in %o1
    call  numOfDigits         ! Call numOfDigits with size and BASE as
                              ! arguments
    nop                       ! Delay slot

    mov   0, %l2              ! Set borderCnt as 0
    cmp   %l2, %o0            ! Compare borderCnt
    bge   end_fourthloop      ! Opposite logic to branch to end_fourthloop
    nop                       ! Delay slot

fourth_loop:
    inc   %l2                 ! Increment borderCnt
    mov   %i3, %o0            ! Store borderChar in %o0
    call  printChar           ! Calls printChar with borderChar as argument
    nop                       ! Delay slot

    mov   %i0, %o0            ! Store size in %o0
    mov   BASE, %o1           ! Store BASE in %o1
    call  numOfDigits         ! Call numOfDigits with size and BASE as
    nop                       ! argument
    
    cmp   %l2, %o0            ! Compare borderCnt and return value of
                              ! numOfDigits 
    bl    fourth_loop         ! If borderCnt is less then loop 
    nop                       ! Delay slot

end_fourthloop:
    mov   0, %l1              ! Set col as 0
    mov   %i0, %o0            ! Store size in %o0
    cmp   %l1, %o0            ! Compare col and size
    bge   end_fifthloop       ! Opposite logic to branch to end_fifthloop
    nop                       ! Delay slot

fifth_loop:
    cmp   %l0, %l1            ! Compare row and col
    be    if                  ! If equal then branch to if
    nop                       ! Delay slot
 
    sub   %i0, %l1, %o0       ! Subtract size by col and store value in %o0
    sub   %o0, 1, %o0         ! Subtract %o0 by 1 and store value in %o0
    cmp   %l0, %o0            ! Compare row and %o0
    be    if                  ! If equal then branch to if
    nop                       ! Delay slot

else:
    mov   %i2, %o0            ! Store fillerChar in %o0
    call  printChar           ! Call printChar with fillerChar as argument
    nop                       ! Delay slot

    ba    end_if              ! Always branch to end_if
    nop                       ! Delay slot

if:
    mov   %i1, %o0            ! Store xChar in %o0
    call  printChar           ! Call printChar with xChar as argument
    nop                       ! Delay slot

end_if:
    inc   %l1                 ! Increment col
    mov   %i0, %o0            ! Store size in %o0
    cmp   %l1, %o0            ! Compare col and size
    bl    fifth_loop          ! If col is smaller than size then loop
    nop                       ! Delay slot

end_fifthloop:
    mov   0, %l2              ! Set borderCnt as 0
    mov   %i0, %o0            ! Store size in %o0
    mov   BASE, %o1           ! Store BASE in %o1
    call  numOfDigits         ! Call numOfDigits with size and BASE as
                              ! arguments
    nop                       ! Delay slot

    cmp   %l2, %o0            ! Compare borderCnt and return value of numOfDigits
    bge   end_sixthloop       ! Opposite logic to branch to end_sixthloop
    nop                       ! Delay slot

sixth_loop:
    inc   %l2                 ! Increment the borderCnt
    mov   %i3, %o0            ! Store borderChar in %o0
    call  printChar           ! Call printChar with borderChar as argument
    nop                       ! Delay slot

    mov   %i0, %o0            ! Store size in %o0
    mov   BASE, %o1           ! Store BASE in %o1
    call  numOfDigits         ! Call numOfDigits with size and BASE as
                              ! arguments
    nop                       ! Delay slot

    cmp   %l2, %o0            ! Compare borderCnt and return value of
                              ! numOfDigits
    bl    sixth_loop          ! If borderCnt is smaller then loop
    nop                       ! Delay slot

end_sixthloop:
    mov   NL, %o0             ! Store NL in %o0
    call  printChar           ! Call printChar with NL as argument
    nop                       ! Delay slot

    inc   %l0                 ! Increment row
    mov   %i0, %o0            ! Store size in %o0
    cmp   %l0, %o0            ! Compare row and size
    bl    third_loop          ! If row is smaller then loop
    nop                       ! Delay slot

end_thirdloop:

/* Display the bottom border. Border depth is based on the number of digits
 * in the X pattern size.
 */
    mov     0, %l0           ! Set row as 0
    mov     0, %l1           ! Set col as 0
    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Calls numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    cmp     %l0, %o0         ! Compare row and the return value of numOfDigits
    bge     end_seventhloop  ! Opposite logic to skip to end_firstloop branch
    nop                      ! Delay slot

seventh_loop:    
    mov     0, %l1           ! Set col as 0
    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Call numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    mov     TWO, %o1         ! Store 2 in %o1
    call    .mul             ! Call .mul on %o0 and %o1
    nop                      ! Delay slot

    add     %o0,%i0,%o0      ! Add %o0 and size and store in %o0    
    cmp     %l1, %o0         ! Compare col and %o0
    bge     end_eighthloop    ! Opposite logic to branch to end_secondloop
    nop                      ! Delay slot

eighth_loop:
    mov     %i3, %o0         ! Store borderChar in o0
    call    printChar        ! Call printChar with borderChar as argument
    nop                      ! Delay slot

    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Call numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    mov     TWO, %o1         ! Store 2 in %o1
    call    .mul             ! Call .mul on %o0 and %o1
    nop                      ! Delay slot

    mov     %i0, %o1         ! Store size in %o1
    add     %o0,%o1,%o0      ! Add %o0 and size and store in %o0
 
    inc     %l1              ! Increment the column
    cmp     %l1, %o0         ! Compare row and return value of numOfDigits
    bl      eighth_loop      ! If row is less then loop
    nop                      ! Delay slot

end_eighthloop:
    mov     NL, %o0          ! Store NL in %o0
    call    printChar        ! Call printChar with NL as argument
    nop                      ! Delay slot

    mov     %i0, %o0         ! Store value of size in %o0
    mov     BASE, %o1        ! Store value of BASE in %o1
    call    numOfDigits      ! Calls numOfDigits with size and BASE as
                             ! arguments
    nop                      ! Delay slot

    inc     %l0              ! Increment the row
    cmp     %l0, %o0         ! Compare row and %o0
    bl      seventh_loop     ! If row is smaller then loop
    nop                      ! Delay slot

end_seventhloop:

end:
    ret
    restore
