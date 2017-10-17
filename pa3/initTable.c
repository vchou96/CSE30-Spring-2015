/*
 * Filename: initTable.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Reads one line of the file at a time and inserts the word into
 *              the hash table. If an ENTRY with the same key is already in
 *              the table the word must be appended to the anagram array. If
 *              there is not already an ENTRY, then a struct anagramHeader is
 *              allocated and a corresponding entry is inserted into the table
 *              before appending into the word.
 * Date: 5-17-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <search.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: initTable
 * Description: Use fgets() to read one line at a time and use hsearch() to
 *              insert the word. Use appendAnagram() to append the word to the
 *              anagrams array if there is already an ENTRY with the same key
 *              in the table. Otherwise use createAnagramHeader() to create a
 *              new struct anagramHeader.
 * Parameters: 
 *     arg1: FILE *file
 * Return Value: Returns -1 if createAnagramHeader(), appendAnagram(), or
 *               hsearch() fail. Otherwise, return the number of words inserted
 *               into the table.
 */

int initTable(FILE *file){
    char str [MAX_WORD_LENGTH+1];/*Array to hold string read from command
                                   line*/
    char key [MAX_WORD_LENGTH+1];/*Array to hold key*/
    int numWords=0;/*Counter for the number of words*/
    int NEG= -1;/*Negative 1*/
    struct anagramHeader * localHeader;/*Local anagramHeader pointer*/
    ENTRY *entryPointer;/*Local ENTRY pointer*/
    ENTRY entry;/*Local ENTRY*/

    while(fgets(str,MAX_WORD_LENGTH+1,file)){/*While there are characters
                                               to read*/
        stripNewLine(str);/*Call stripNewLine to change newline to null
                            char*/
        createHashKey(key,str, charCompare);/*Call createHashKey*/
        entry.key=key;/*Set entry's key as key*/

        entryPointer=hsearch(entry,FIND);/*Call hsearch to find if matching
                                           entry is in table*/
        if(entryPointer){/*If matching entry is found*/
            struct anagram *newAnagram= malloc(sizeof(struct anagram));
                /*Declare new struct anagram pointer*/
            (void)strcpy(newAnagram->word, str);
            /*LINTED*/
            if(appendAnagram((struct anagramHeader *)(*entryPointer).data,
                              newAnagram)==NEG){/*If function returns -1*/
                return NEG;/*Return -1 for error*/
            }
            else{/*If appendAnagram executed successfully*/
                ++numWords;/*Increment the number of words inserted*/
            }
        }
        else{/*If hsearch returned null pointer; no match was found*/
                      
            localHeader= createAnagramHeader(key);/*Create new anagramHeader*/
            if(!localHeader){/*If createAnagramHeader returns NULL*/
                return NEG;/*Return -1 for error*/
            }
            else{/*If anagramHeader was succesfully created*/
                struct anagram *anagrams= malloc(sizeof(struct anagram));
                    /*Declare new struct anagram pointer*/
                (void)strcpy(anagrams->word,str);/*Copy str to anagrams' word
                                                   array*/
                if(appendAnagram(localHeader,anagrams)==NEG){/*If appendAnagram
                                                               returns -1*/
                    return NEG;/*Return -1 for error*/
                }
                else{/*If anagram was appended successfully*/
                    entry.key= localHeader->key;/*Set entry's key to key*/
                    entry.data= (char *)localHeader;/*Set entry's data to
                                                      anagramHeader*/
                    (void)hsearch(entry,ENTER);/*Call hsearch to enter the
                                                 entry*/
                    ++numWords;/*Increment the number of words inserted*/
                }
            }
        }
    }
    return numWords;/*Return the number of words inserted*/
}
