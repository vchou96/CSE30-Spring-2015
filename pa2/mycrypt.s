/*
 * Filename: mycrypt.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Module that encrypts/decrypts the data using the key and masks
 *              from the user.
 * Date: 5-3-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
    .global mycrypt        ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here
        BUFSIZ= 1024;      ! Value of BUFSIZ	

    .section ".text"       ! The text segment begins here

/*
 * Function name: mycrypt()
 * Function prototype: void mycrypt(FILE *inFile, unsigned long mask[], int
 *                                  rotateValue);
 * Description: Encrypts/decrypts the data using the keys and masks from the
 *              user.
 * Parameters:
 *      arg1: FILE *inFile -- contains the data to encrypt
 *      arg2: unsigned long mask[] -- contains the 64-bit mask
 *      arg3: int rotateValue -- the rotation key to pass to rotate
 * Side Effects: 
 * Return Value: No return value.
 * Registers Used:
 *      %i0 - Arg1 -- contains the data to encrypt
 *      %i1 - Arg2 -- contains the 64-bit mask
 *      %i2 - Arg3 -- the rotation key to pass to rotate
 *      %l0 - local register
 *      %l1 - local register
 *      %l2 - local register
 *      %l3 - local register
 *      %l4 - local register
 *      %l5 - local register
 */

mycrypt:
        save   %sp, -(92+BUFSIZ) & -8, %sp       ! Save caller's window
        mov    0, %l5

loop:   
        sub    %fp, BUFSIZ, %o0    ! Read from %fp-BUFSIZ
        mov    1, %o1              ! Store 1 in %o1
        mov    BUFSIZ, %o2         ! Store BUFSIZ in %o2
        mov    %i0, %o3            ! Store %i0 in %o3
        call   fread               ! Call fread with %o0, %o1, %o2, %o3 as
                                   ! arguments
        nop                        ! Delay slot
	
	mov    %o0, %l0            ! Store number of bytes read in %l0
	cmp    %o0, 0              ! Compare the return value of fread and 0 
        be     exit                ! If 0 bytes read then branch to exit
	nop                        ! Delay slot

/*	cmp    %o0, 8              ! Compare number of bytes read and 8
*	bl     before             ! If read less than 8 bytes branch to leftover
*	nop                        ! Delay slot
*/
every_eight:


        ld     [%i1], %l1              ! Load mask[0]
	sub    %fp, BUFSIZ, %l2        ! %fp-BUFSIZ
	add	%l2, %l5, %l2          ! address we are accessing from
	ld     [%l2], %l3          ! Load %fp-BUFSIZ+%l5 in %l2
	xor    %l1, %l3, %l1           ! XOR first 4 bytes of data with mask[0]
	st     %l1, [%l2]              ! Store back in frame pointer
	

	ld     [%i1+4], %l3            ! Load mask[1]
        sub    %fp, BUFSIZ, %l4        ! %fp-BUFSIZ
	add    %l4, %l5, %l6           ! %fp-BUFSIZ+%l5
	add    4, %l6, %l6
	ld     [%l6], %l1            ! Load %fp-BUFSIZ+%l5+4 in %l4
        xor    %l3, %l1, %l3           ! XOR second 4 bytes of data with mask[1]
        st     %l3, [%l6]              ! Store back in frame pointer

        mov    %i1, %o0                ! Store masks in %o0
        mov    %i2, %o1                ! Store rotateValue in %o1
        call   rotate                  ! Call rotate with %o0 and %o1 as
	                               ! arguments
        nop                            ! Delay slot

        add    %l5, 8, %l5           ! Add 8 to %l5
        sub    %l0, %l5, %l6         ! Store difference of bytes read and %l5 in %l6
        cmp    %l6, 8                ! Compare %l6 and 8
        bge    every_eight           ! If there are more than 8 bytes left then loop 
        nop                          ! Delay slot
        
        cmp    %l6, 0
        be     write    
        nop

/*
before:
        mov    0, %l1

leftover:
        sub    %fp, %l5, %l2        ! %fp+(total bytes read)
        ldub   [%l2+%l1], %l3       ! Load next byte 
        ldub   [%i1+%l1], %l4       ! Load next most significant byte of mask
        xor    %l3, %l4, %l5        ! XOR first byte with most significant byte of mask[0]
        stb    %l5, [%l3]          ! Store back in frame pointer
        dec    %l6                  ! Decrement %l6
        inc    %l1
        cmp    %l6, 0               ! Compare %l6 and 0
        bg     leftover             ! If there are still bytes left, loop
        nop
*/

write:
        sub    %fp, BUFSIZ, %o0        ! %fp-BUFSIZ
        mov    1, %o1                  ! Store 1 in %o1
        mov    %l0, %o2                  ! Store bits read in %o2
        set    standardOut, %l0           ! Store standardOut in %l0
        ld     [%l0], %o3                 ! Load standardOut to %o3
        call   fwrite                     ! Call fwrite to write the encrypted data out to stdout
        nop                               ! Delay slot

        ba     loop                       ! Branch always to loop
        nop                               ! Delay slot

exit:   
        ret                               ! Return from subroutine
        restore                           !
