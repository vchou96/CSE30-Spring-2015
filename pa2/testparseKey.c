/*
 * Filename: testparseKey.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function parseKey.
 * Date: 4/27/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
//#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa2.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
//#include "pa2_globals.c"

/*
 * int parseKey( char *str, unsigned long *key );
 *
 * Returns 0 if the string was parsed successfully, ERANGE_ERR if errno is set
 * to non-zero, ENDPTR_ERR if endptr points to non-null character.
 *
 * Precondition: Base is in the range of 2-36.
 */
unsigned long *key;
unsigned long keyVal;
void
testparseKey()
{
    printf( "Testing parseKey()\n" );
    key = &keyVal;
    TEST( parseKey( "0", key ) == 0 );
    TEST( parseKey( "36", key ) == 0 );
    TEST( parseKey( "51515", key ) == 0 );
    TEST( parseKey( "789",key ) == 0 );
    TEST( keyVal  == 789 );
    TEST( parseKey( "99999999999999999999", key ) == ERANGE_ERR );
    TEST( parseKey( "88888888888888887", key ) == ERANGE_ERR );
    TEST( parseKey( "5555555555555555", key ) == ERANGE_ERR );
    TEST( parseKey( "99abc", key ) == ENDPTR_ERR );
    TEST( parseKey( "abc123", key ) == ENDPTR_ERR );
    TEST( parseKey( "567a23", key ) == ENDPTR_ERR );

    printf( "Finished running tests on parseKey()\n" );
}

int
main()
{
    testparseKey();

    return 0;
}
