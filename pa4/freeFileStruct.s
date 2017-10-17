/*
 * Filename: freeFileStruct.s
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Frees all the memory allocated within a struct file.
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides,
 *                  class Piazza page
 */
    .global freeFileStruct ! Declares the symbol to be globally visible so
                           !  we can call the function from other modules.

    .section ".data"       ! The data segment begins here	
        INCREMENT=4;       ! Used to move pointer to access each line and
                           ! numLine
    .section ".text"       ! The text segment begins here

/*
 * Function name: freeFileStruct()
 * Function prototype: int freeFileStruct(const struct file* file);
 * Description: Frees all the memory allocated within a struct file.
 * Parameters:
 *      arg1: const struct file* file -- pointer to struct file to free
 * Error Conditions: None. 
 * Return Value: Returns the number of times free is called
 * Registers Used:
 *      %i0 - Arg1 -- pointer to struct to free
 *      %o0 - Used to send arguments to free/ return value
 *      %l0 - Counter for number of times free is called
 *      %l1 - Holds num of lines
 */

freeFileStruct:
        save    %sp, -96, %sp           ! Save caller's window 
           
        mov     0, %l0                  ! Number of times free is called
	ld      [%i0+INCREMENT], %l1    ! Gets number of lines
        cmp     %l1, 0                  ! Compares number of lines and 0
	be      end_loop                ! If equal, branch to end
	nop
	
	ld      [%i0], %l2              ! Load startPtr to %l2

loop:
	ld      [%l2], %o0              ! Load line pointed to in startPtr to %o0
	call    free                    ! Call free to free each line
	nop                             ! Delay slot
	
	add     %l2, INCREMENT, %l2     ! Move %l2 to next line

	inc     %l0                     ! Increment number of times freed is called
	cmp     %l0, %l1                ! Compare number of times freed with number of lines
	bl      loop                    ! If less then loop
	nop                             ! Delay slot
	
end_loop:
        cmp     %i0, %g0                ! Compare if array is null
	be      end                     ! If it is then branch to end
	nop                             ! Delay slot

        mov     %i0, %o0                ! Load array to %o0
        call    free                    ! Call free to free the array
        nop                             ! Delay slot
      
        inc     %l0                     ! Increment number of times free is called

end:
        mov     %l0, %i0                ! Moves %l0 to return number of times free was called
        ret                             ! Return from subroutine
        restore                         ! Restore caller window
