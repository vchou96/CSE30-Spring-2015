/*
 * Filename: parseInput.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Parses the specified input file.Sets inFile and returns 0 for
 *              successful parsing. If there is an error then the
 *              corresponding value is returned. 
 *              
 * Date: 5-3-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa2.h"

/*
 * Function name: parseInput
 * Description: Parses the fifth command line argument and returns 0 for
 *              success. Otherwise, FILE_ERR is returned for a file name that
 *              fails to open.
 * Parameters: 
 *     arg1: char *str -- the string to be parsed
 *     arg2: FILE **inFile -- to be set to stdin if the dash is found
 * Return Value: Returns 0 for successful parsing, FILE_ERR for a file name
 *               that fails to open.
 */

int parseInput(char *str, FILE **inFile){
    if (!strcmp("-", str)){/*If the string matches the dash*/
        *inFile= stdin;/*Set inFile to stdin*/
        return 0;/*Return 0 for successful parsing*/
    }
    if(fopen(str,FILE_OPEN_OPT)!=NULL) {/*If fopen does not return NULL
                                          pointer*/
        *inFile = fopen(str,FILE_OPEN_OPT);/*Point inFile to opened file*/
        return 0;/*Return 0 for successful parsing*/
    }
    else{/*If the file does not open*/
        return FILE_ERR;/*return unable to open file error*/
    }
}
