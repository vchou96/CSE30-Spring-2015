/*
 * Filename: testparseRotateValue.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function parseRotateValue.
 * Date: 4/27/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa2.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int testparseRotateValue( char *str, long *rotateValue );
 *
 * Returns 0 if the string was parsed successfully, ERANGE_ERR if errno is set
 * to non-zero, ENDPTR_ERR if endptr points to non-null character, BOUND_ERR
 * if the value is out of range.
 *
 * Precondition: Base is in the range of 2-36.
 */
long *key;
long keyVal;
int
testparseRotateValue()
{
    printf( "Testing parseRotateValue()\n" );
    key= &keyVal;
    TEST( parseRotateValue( "-40", key ) == 0 );
    TEST( keyVal= -40 );
    TEST( parseRotateValue( "-63", key ) == 0 );
    TEST( parseRotateValue( "1", key ) == 0 );
    TEST( parseRotateValue( "999999999999999999", key ) == ERANGE_ERR );
    TEST( parseRotateValue( "88888888888888888", key ) == ERANGE_ERR );
    TEST( parseRotateValue( "-44444444444444449", key ) == ERANGE_ERR );
    TEST( parseRotateValue( "99abc", key ) == ENDPTR_ERR );
    TEST( parseRotateValue( "ieng6", key ) == ENDPTR_ERR );
    TEST( parseRotateValue( "123a", key ) == ENDPTR_ERR );
    TEST( parseRotateValue( "64", key ) == BOUND_ERR );
    TEST( parseRotateValue( "100", key ) == BOUND_ERR );
    TEST( parseRotateValue( "-99", key ) == BOUND_ERR );
    
    printf( "Finished running tests on parseRotateValue()\n" );
}

int
main()
{
    testparseRotateValue();

    return 0;
}
