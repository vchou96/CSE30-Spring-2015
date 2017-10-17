/*
 * Filename: testcreateMask.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function createMask.
 * Date: 4/27/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa2.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
/*
 * void createMask( unsigned long keys[], char passphrase[], unsigned long mask[] );
 *
 * No return value. The function creates the two 32-bit mask values.
 */


void
testcreateMask()
{
    unsigned long key[2];
    char passphrase [2];
    unsigned long mask[2];
    
    printf( "Testing createMask()\n" );
    
    key[0]= 0x01234567;
    key[1]= 0x76543210;
    createMask(key, "00000000", mask);
    TEST( mask[0]== 0x31137557 );
    TEST( mask[1]== 0x46640220 );
    
    key[0]= 0x00001111;
    key[1]= 0x11110000;
    createMask(key, "abcdefgh", mask);
    TEST( mask[0]== 0x61627275 );
    TEST( mask[1]== 0x74776768 );
    
    key[0]= 0xFEDCBA00;
    key[1]= 0x00ABCDEF;
    createMask(key, "01234567", mask);
    TEST( mask[0]== 0xCEED8833);
    TEST( mask[1]== 0x349EFBD8);
    
    key[0]= 0x01234567;
    key[1]= 0x0ABCDEFF;
    createMask(key, "zyxwvuts", mask);
    TEST( mask[0]== 0x7B5A3D10);
    TEST( mask[1]== 0x7CC9AA8C);
    printf( "Finished running tests on createMask()\n" );
}

int
main()
{
    testcreateMask();

    return 0;
}
