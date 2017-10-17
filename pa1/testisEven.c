/*
 * Filename: testisEven.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function isEven.
 * Date: 4/14/2015
 * Sources of Help: testcheckRange.c example, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa1.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int isEven( long num );
 *
 * Returns non-zero if value is even.
 * Returns 0 otherwise.
 *
 * Precondition: None.
 */

void
testisEven()
{
    printf( "Testing isEven()\n" );

    /* Test 0 */
    TEST( isEven( 0 ) == 1 );

    /* Test odd numbers */
    TEST( isEven( 1 ) == 0 );
    TEST( isEven( 3 ) == 0 );
    TEST( isEven( -5 ) == 0 );
    TEST( isEven( -7 ) == 0 );

    /* Test even numbers */
    TEST( isEven( 2 ) == 1 );
    TEST( isEven( 4 ) == 1 );
    TEST( isEven( -10 ) == 1 );
    TEST( isEven( 22 ) == 1 );
    printf( "Finished running tests on isEven()\n" );
}

int
main()
{
    testisEven();

    return 0;
}
