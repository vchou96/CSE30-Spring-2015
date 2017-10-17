/*
 * Filename: parseKey.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Converts string into unsigned long and sets key and returns 0
 *              for success.
 * Date: 4-26-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa2.h"
#include "pa2_strings.h"


/*
 * Function name: parseKey
 * Description: Converts the string to an unsigned long and sets the key
 *              and returns 0 if successful. If there are errors, the
 *              appropriate error is returned.
 * Parameters: 
 *     arg1: char *str -- the string to be parsed
 *     arg2: unsigned long *key -- the key to set through point dereferencing
 * Return Value: Returns 0 for successful parsing, ERANGE_ERR if errno is
 *               set to non-zero, ENDPTR_ERR if endptr points to non-null char.
 */

int parseKey(char *str, unsigned long *key){
    char * endptr;/*endptr that points to last character in str*/
    unsigned long value;/*holds the return value of strtoul*/
    
    errno=0;/*set errno as 0*/
    value= strtoul(str, &endptr, DEF_BASE);/*convert string to unsigned long*/
    if (errno){/*If errno is set to non-zero*/
        return ERANGE_ERR;/*Returns range error message*/
    }
    if(*endptr){/*If endptr points to non-null character*/
        return ENDPTR_ERR;/*Returns endptr error message*/
    }
    *key= value;/*set key pointing to value*/
    return 0;/*if successful*/
}
