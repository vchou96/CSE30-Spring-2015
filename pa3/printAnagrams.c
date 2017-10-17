/*
 * Filename: printAnagrams.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: The function will print out each word in struct anagram array.
 *              Will not print any words that match the word passed in.
 * Date: 5-17-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: printAnagrams
 * Description: Prints out each word in struct anagram array pointed to within
 *              head. Does not print any words that match the word passed in.
 * Parameters: 
 *     arg1: struct anagramHeader *head- pointer to the struct anagram array
 *                                       whose contents will be printed
 *     arg2: char *word- pointer to the word passed in (does not print this
 *                       word) 
 * Return Value: No return value
 */

void printAnagrams(struct anagramHeader *head, char *word){
    int i;/*used as index of anagrams*/
    int firstWord=1;/*Used for the first anagram to be printed*/

    if(head->numElements==1){/*If there is only 1 possible anagram*/
        if(strncmp(word, head->anagrams[0].word,
                   strlen(word))==0){/*If anagram is the same as word*/
            (void)fprintf(stderr, STR_NO_ANAGRAMS_FOUND);/*Print that no
                                                           anagrams found*/
        }
        else{/*If they are different*/
            (void)fprintf(stderr, STR_ANAGRAMS_FOUND);/*Print which anagrams
                                                        found*/
            (void)printf(STR_FIRST_ANAGRAM_WORD,
                         head->anagrams[0].word);/*Print the anagram*/
        }
    }
    else{
        (void)printf(STR_ANAGRAMS_FOUND);/*Prints which anagrams found*/
        for(i=0; i<head->numElements; i++){/*Loops within struct anagram
                                             array*/
            if(strncmp(word, head->anagrams[i].word, 
               strlen(word))){/*If word in struct anagram array does
                                not match word*/
                if(firstWord){/*If it is the first word to be printed*/
                    (void)printf(STR_FIRST_ANAGRAM_WORD,
                                 head->anagrams[i].word);/*Print out the word*/
                    firstWord=0;/*Enter the else statement next time*/
                }
                else{/*If there is more than one anagram*/
                    (void)printf(STR_ANAGRAM_WORD,
                                 head->anagrams[i].word);/*Print out the word
                                                           with comma*/
                }
            }
        }
    }
    (void)printf(STR_ONE_NEW_LINE);/*Print extra line*/
}
