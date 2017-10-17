/*
 * Filename: testnumOfDigits.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function numofDigits.
 * Date: 4/14/2015
 * Sources of Help: testcheckRange.c example, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int numOfDigits( long num, int base );
 *
 * Returns the number of digits of num in base.
 *
 * Precondition: Base is in the range of 2-36.
 */

void
testnumOfDigits()
{
    printf( "Testing numofDigits()\n" );

    /* Test 0 */
    TEST( numOfDigits( 0, 10 ) == 1 );
    TEST( numOfDigits( 0, 16 ) == 1 );

    /* Test out-of-range*/
    TEST( numOfDigits( 3, 37 ) == -1 );
    TEST( numOfDigits( 3, 1 ) == -1 );
    
    /* Test base 10 */
    TEST( numOfDigits( 2, 10 ) == 1 );
    TEST( numOfDigits( 10, 10 ) == 2 );
    TEST( numOfDigits( 100, 10 ) == 3 );

    /* Test base 2 */
    TEST( numOfDigits( 1, 2 ) == 1 );
    TEST( numOfDigits( 2, 2 ) == 2 );
    TEST( numOfDigits( 4, 2 ) == 3 );
    TEST( numOfDigits( 8, 2 ) == 4 );

    /*Test base 36*/
    TEST( numOfDigits( 35, 36 ) == 1 );
    TEST( numOfDigits( 36, 36 ) == 2 );
    printf( "Finished running tests on numOfDigits()\n" );
}

int
main()
{
    testnumOfDigits();

    return 0;
}
