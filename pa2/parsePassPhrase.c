/*
 * Filename: parsePassPhrase.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Parses the passphrase and checks if the string has at least 8
 *              characters. Returns 0 if the string is successfully parsed and
 *              returns LENGTH_ERR if there is an error. 
 * Date: 5-3-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa2.h"

/*
 * Function name: parsePassPhrase
 * Description: Parses the passphrase and checks if it at least 8 chars.
 * Parameters: 
 *     arg1: char *str -- the string to be parsed
 *     arg2: char *passphrase -- the array that will hold the characters of
 *                               the first argument 
 * Return Value: Returns 0 for successful parsing, LENGTH_ERR if the string
 *               is too short
 */

int parsePassPhrase(char *str, char *passphrase ){
    
    if(strlen(str)>= PASS_PHRASE_SIZE){/*If the string is at least 8 chars*/
        (void)strncpy(passphrase, str, PASS_PHRASE_SIZE);/*Copy the string to
                                                     passphrase*/
        return 0;/*returns 0 for successful parsing*/
    }
    else{/*if the string is too short*/
        return LENGTH_ERR;/*returns string too short error*/
    }
}
