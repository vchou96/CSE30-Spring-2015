/*
 * Filename: appendAnagram.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Contains the method for allocating additional memory at the
 *              end of the struct anagram array. Returns the number of
 *              elements in the array after the addition. 
 * Date: 5-11-2015
 * Sources of Help: Class Handouts, PA3 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3.h"

/*
 * Function name: appendAnagram
 * Description: Allocates additional memory at the end of the struct anagram
 *              using realloc() and copies the struct anagram using memcpy().
 * Parameters: 
 *     arg1: struct anagramHeader *head: points to struct anagram
 *     arg2: struct anagram *anagram: struct to be copied
 * Return Value: Returns -1 if realloc fails, otherwise it returns the number
 *               of elements in the array after the new addition.
 */
int appendAnagram(struct anagramHeader *head, struct anagram *anagram){
    int NEG= -1;/*Negative 1*/
    int currSize;/*The current size of the anagrams array*/

    currSize= head->numElements * sizeof(struct anagram);/*set currsize as the
                                                           number of elements
                                                           times the size of
                                                           an anagram*/
    head->anagrams=realloc(head->anagrams, currSize+
                           sizeof(struct anagram));/*Allocates memory*/
    if (!head->anagrams){/*If type returned by realloc is null pointer*/
        return NEG;/*Returns -1 if allocation failed*/
    }
    (void)memcpy(&head->anagrams[head->numElements], anagram, 
           sizeof(struct anagram));/*Copies the struct anagram passed in to
                                     the allocated memory*/
    head->numElements++;/*Increment the number of elements*/
    return head->numElements;/*Returns number of anagrams in array*/
}
