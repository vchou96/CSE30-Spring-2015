/*
 * Filename: main.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Drives the rest of the program by checking the number of
 *              arguments, reading the file passed on the command line,
 *              creating the hash table, filling the table, interacting with
 *              the user, then destroying the table. exit (EXIT_FAIURE) is
 *              called if any of the functions called by main encounters
 *              errors; otherwise, main returns 0.
 * Date: 5-12-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
#include <search.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: main.c
 * Description: Checks for the expected number of arguments and reads in the
 *              arguments passed on the command line. Creates the hash table
 *              with hcreate(), fills the tables with initTable(), interacts
 *              with the user with searchForAnagrams(), and destroys the table
 *              with hdestroy(). If any errors are encountered, the
 *              corresponding error message is printed.
 * Parameters: 
 *     arg1: int argc- number of arguments
 *     arg2: char*argv[]- the inputted arguments
 * Return Value: Returns 0 for successful execution.
 */

int main(int argc, char*argv[]){
    char *file;/*char pointer to file inputted in command line*/
    char buffer [BUFSIZ];/*buffer for snprintf/perror*/
    int NEG= -1;/*Negative 1*/
    FILE * retVal;/*Holds return value of fopen*/

    if (argc - 1 !=  EXPECTED_ARGS){/*If there are incorrect number of
                                      arguments*/
        printUsage(argv[0]);/*Call printUsage function*/
        exit(EXIT_FAILURE);/*Exits the function*/
    }


    file= argv[1];/*Set file pointing to file name in command line*/
    retVal=fopen(file, "r");/*Call fopen and pass FILE * to retVal*/
    if (!retVal){/*If fopen returns null pointer*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_FOPEN);/*Call snprintf to
                                                        handle error printing*/
        perror(buffer);/*Call perror and pass buffer to handle error printing*/
        (void)fprintf(stderr,STR_ONE_NEW_LINE);/*Print one new line*/
        return EXIT_FAILURE;/*Exits function*/
    }


    if (!hcreate(HASH_TABLE_SIZE)){/*If hcreate returns null pointer*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_HCREATE);/*call snprintf to
                                                          handle error
                                                          printing*/
        perror(buffer);/*Call perror and pass buffer to handle error
                         printing*/
        (void)fprintf(stderr,STR_ONE_NEW_LINE);/*Print one new line*/
        return EXIT_FAILURE;/*Exits function*/
    }
    
    if(initTable(retVal)==NEG){/*If initTable returns -1*/
        (void)fprintf(stderr, STR_ERR_DB_CREATE);/*Print creating anagram
                                                   error*/
        (void)fprintf(stderr,STR_ONE_NEW_LINE);/*Print one new line*/
        return EXIT_FAILURE;/*Exits function*/
    }

    searchForAnagrams();/*Call search for anagrams*/
    hdestroy();/*Destroys the table*/
    return 0;/*Returns 0 for no errors*/
}
