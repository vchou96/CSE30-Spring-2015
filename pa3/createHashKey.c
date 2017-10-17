/*
 * Filename: createHashKey.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Contains the method for copying the characters from src to
 *              key, making them lower case, and sorting them.
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA3 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pa3.h"

/*
 * Function name: createHashKey
 * Description: Copies each character from src to key and makes each lower
 *              case using tolower(). Sorts the characters using qsort()
 *              and compare function.
 * Parameters: 
 *     arg1: char *key- where the copied characters go
 *     arg2: const char *src- provides the characters to be copied
 *     arg3: int (*compare)(const void *, const void *)- comparison function
 * Return Value: No return value.
 */

void createHashKey(char *key, const char *src, int (*compare)(const void *,
                   const void *)){
    int strLength;/*Holds length of src*/
    int i;/*index in the for loop*/
    

    strLength=strlen(src);/*Gets the length of src*/
    (void)strncpy(key,src, strLength);
    for(i=0; i<strLength; i++){/*for loop that stores the lower case of src's
                                 letter in key one at a time*/
        key[i]= tolower(key[i]);/*sets characters in lower case*/
    }
    qsort(key, strLength, sizeof(char), compare);/*call qsort to sort the
                                                   letters in key*/
    key[i]='\0';/*Add null char at end*/
}
