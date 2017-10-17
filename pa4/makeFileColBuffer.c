/*
 * Filename: makeFileColBuffer.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Fills a char buffer of max length n with the source string. If
 *              the source string's length is less than n, fill the remaining
 *              positions with spaces.
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "lcs.h"
/*
 * Function name: makeFileColBuffer
 * Description: Fills a char buffer s1 of max length n with source string s2.
 *              Fill remaining positions with spaces if the source string's
 *              length is <n. Add nul terminating character to destination
 *              buffer.
 * Parameters: 
 *     arg1: char* s1- The char buffer for s2 to be copied to
 *     arg2: const char* s2- The source string
 *     arg3: const int n- Max length of string in s1
 * Return Value: No return value.
 */

void makeFileColBuffer(char* s1, const char* s2, int n){
    memset(s1, ' ', strlen(s1));/*Fills s1 with spaces*/
    memcpy(s1, s2, strlen(s2));/*Copies contents of s2 to s1*/
    s1[n+1]= '\0';/*Adds null character at end of s1*/
}

