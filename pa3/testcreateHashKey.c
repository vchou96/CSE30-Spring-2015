/*
 * Filename: testcreateHashKey.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function createHashKey.
 * Date: 5/12/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa3.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

void
testcreateHashKey()
{
    printf( "Testing createHashKey()\n" );
    char key [BUFSIZ];
    char *src;
    char *sorted;
    int retVal;

    src= "RCZML";
    sorted="clmrz";
    createHashKey(key, src, charCompare);
    TEST(key[0] == 'c' );
    TEST(key[1] == 'l' );
    TEST(key[2] == 'm' );
    TEST(key[3] == 'r' );
    TEST(key[4] == 'z' );
    TEST(key[5] == '\0');
    printf(key);
    TEST(strcmp(key,sorted )==0);
    printf( "Finished running tests on createHashKey()\n" );
}

int
main()
{
    testcreateHashKey();

    return 0;
}

