/*
 * Filename: makeSymbolColBuffer.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Fills a char buffer of max length n with the string for the
 *              symbol that corresponds to the type passed in.
 * Date: 5-25-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */
#include <search.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: makeSymbolColBuffer
 * Description: Fills destination buffer with string based on the type
 *              passed in.
 * Parameters: 
 *     arg1: char* s1 - Destination buffer 
 *     arg2: unsigned int type - Refers to type
 *     arg3: int n - Max length 
 * Return Value: No return value.
 */

void makeSymbolColBuffer(char* s1, unsigned int type, int n){
    if(type==TYPE_ADD){/*If type is 1*/
        (void)snprintf(s1, n, STR_ADD);/*Print string for add case*/
    }
    if(type==TYPE_DELETE){/*If type is 2*/
        (void)snprintf(s1, n, STR_DELETE);/*Prints string for delete case*/
    }
    if(type==TYPE_CHANGE){/*If type is 3*/
        (void)snprintf(s1, n, STR_CHANGE);/*Prints string for change case*/
    }
    if(type==TYPE_SAME){/*If type is 4*/
        (void)snprintf(s1, n, STR_SAME);/*Prints string for same case*/
    }
}
