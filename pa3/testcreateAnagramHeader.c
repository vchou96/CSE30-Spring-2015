/*
 * Filename: testcreateAnagramHeader.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function createAnagramHeader.
 * Date: 4/27/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa3.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

struct anagramHeader* pointer;
void
testcreateAnagramHeader()
{
    printf( "Testing createAnagramHeader()\n" );
    pointer= createAnagramHeader("hello");

    TEST(pointer->key[0] == 'h' );
    TEST(pointer->key[1] == 'e' );
    TEST(pointer->key[2] == 'l' );
    TEST(pointer->key[3] == 'l' );
    TEST(pointer->key[4] == 'o' );
    TEST(pointer->anagrams == NULL );
    TEST(pointer->numElements ==0  );
    printf( "Finished running tests on createAnagramHeader()\n" );
}

int
main()
{
    testcreateAnagramHeader();

    return 0;
}

