/*
 * Filename: createAnagramHeader.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Contains the method for allocating memory for a struct
 *              anagramHeader and initializing its values.
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA3 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3.h"

/*
 * Function name: createAnagramHeader
 * Description: Allocates memory for one struct anagramHeader using malloc
 *              and initializes the values. To set the key, strnpy copies the
 *              key value passed in, anagram pointer is set to NULL, and
 *              numElements set to 0.
 * Parameters: 
 *     arg1: const char *key: the key value
 * Return Value: Returns NULL if malloc fails, otherwise returns pointer to
 *               struct.
 */

struct anagramHeader* createAnagramHeader(const char *key){
    struct anagramHeader* head;/*Declare pointer to stuct anagramHeader*/

    head=malloc(sizeof(struct anagramHeader));/*Allocates memory*/
    (void)strncpy(head->key, key, MAX_WORD_LENGTH+1);/*Copies key value passed
                                                     in*/
    head->anagrams=NULL;/*set pointer to NULL*/
    head->numElements=0;/*Set numElements to 0*/
    if (!head){/*If malloc() fails*/
        return NULL;/*Return NULL*/
    }
    else{/*If malloc() was successful*/
        return head;/*Return the pointer to the struct anagramHeader*/
    }
}
