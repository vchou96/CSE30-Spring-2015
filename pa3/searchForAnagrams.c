/*
 * Filename: searchforAnagrams.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Reads a word from stdin and looks for an ENTRY in the table
 *              with the same key. If there is a match call printAnagrams.
 *              If not then print that no anagrams were found. Prompt user
 *              for new word until ^D. 
 * Date: 5-17-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <search.h>
#include <string.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: searchforAnagrams
 * Description: Use fgets() to read in word from stdin. If no entries with the
 *              same key are found, call printAnagrams. If not, print that
 *              none were found and keep re-prompting for a new word. 
 * Parameters: None 
 * Return Value: No return value
 */

void searchForAnagrams(){
    char str [MAX_WORD_LENGTH+1];/*Stores input from command line*/
    char key [MAX_WORD_LENGTH];/*Holds key created from createHashKey*/
    ENTRY entry;/*Declares entry*/
    ENTRY * entryPointer;/*Declares entry pointer*/
     
    (void)fprintf(stderr, STR_SEARCH);/*Asks for word to search*/
    while(fgets(str,MAX_WORD_LENGTH+1,stdin)){/*While there is input from
                                                command line*/
        stripNewLine(str);/*Strip new line character*/
        createHashKey(key, str, charCompare);/*Convert word to key*/
        entry.key=key;/*Set entry's key as key*/
        entryPointer= hsearch(entry, FIND);/*Call hsearch and set entryPointer
                                             as return value*/
        if(entryPointer){/*If there is a match*/
            /*LINTED*/
            printAnagrams((struct anagramHeader *)(*entryPointer).data,
                           str);/*Call printAnagrams*/
        }
        else{/*No match*/
            (void)fprintf(stderr, STR_NO_ANAGRAMS_FOUND);/*Prints no anagrams
                                                           found message*/ 
        }
        (void)printf(STR_ONE_NEW_LINE);/*Print extra line*/
        (void)fprintf(stderr, STR_SEARCH);/*Asks for word to search*/
    }
    (void)printf(STR_NEW_LINE);/*Print a new line*/
}
