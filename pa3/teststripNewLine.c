/*
 * Filename: teststripNewLine.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function stripNewLine.
 * Date: 5/12/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa3.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h>
#include <stdio.h>

void
teststripNewLine()
{
    printf( "Testing stripNewLine()\n" );
    char str[]="abcde";
    stripNewLine(str);
    TEST(strcmp(str, "abcde")==0 );
    char str1[]="abc\n";
    stripNewLine(str1);
    TEST(strcmp(str1, "abc\0")==0 );
    char str2[]="hel\nlo";
    stripNewLine(str2);
    TEST(strcmp(str2, "hel\0")==0 );
    printf( "Finished running tests on stripNewLine()\n" );
}

int
main()
{
    teststripNewLine();

    return 0;
}
