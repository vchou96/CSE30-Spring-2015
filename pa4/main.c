/*
 * Filename: main.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Drives the rest of the program by calling other functions in pa4. 
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */
#include <search.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "pa4_strings.h"
#include "lcs.h"

/*
 * Function name: main
 * Description: Reads user input using setDisplayMode(), checks for and prints
 *              error messages. If there are no errors and help flag is not
 *              set, read in both files and call findLCS() to generate the
 *              lcsList. Make the results list using makeResults(). Display
 *              the results using displayResults() and free all memory used. 
 *     arg1: int argc- number of arguments
 *     arg2: char* argv[]- array of arguments from command line
 * Return Value: Returns exit(EXIT_SUCCESS) for success and exit(EXIT_FAILURE)
 *               for failure.
 */

int main(int argc, char* argv[]){
    int retVal;/*Holds return values of function calls*/
    char buffer[BUFSIZ];/*Create char array*/
    struct resultList* result= malloc(sizeof(struct resultList));
    struct lcsList* list= malloc(sizeof(struct lcsList));
    struct file* file1= malloc(sizeof(struct file));
    struct file* file2= malloc(sizeof(struct file));
    struct displayOpts display;
    
    int failed=0;/*0 if not failed, 1 if failed*/
    /*Initialize fields to 0*/
    result->numResults=0;
    result->startPtr=0;
    list->startPtr=0;
    list->numElems=0;
    display.width=0;
    display.displayMode=0;
    file1->startPtr=0;
    file1->numLines=0;
    file2->startPtr=0;
    file2->numLines=0;
    
    retVal= setDisplayMode(argc, argv, &display);/*Send arguments from command
                                                  line to setDisplayMode to
                                                  read user input*/
    if(retVal){/*If retVal is error*/
        if(retVal==MISSING_OP_ERR){/*If return value is 2*/
            (void)fprintf(stderr, STR_ERR_MISSING_OPERAND, argv[0],
                          argv[1]);/*Print corresponding error message*/
        }
        if(retVal==EXTRA_OP_ERR){/*If return value is 3*/
            (void)fprintf(stderr, STR_ERR_EXTRA_OPERAND, argv[0],
                          argv[3]);/*Print corresponding error message*/
        }
        if(retVal==VALUE_ERR){/*If return value is 4*/
            (void)fprintf(stderr, STR_ERR_INVALID_WIDTH, argv[0]);/*Print
                                            corresponding error message*/
        }
        if(retVal==EXCLUSION_ERR){/*If return value is 5*/
            (void)fprintf(stderr, STR_ERR_MUTUAL_EXL, argv[0]);/*Print
                                         corresponding error message*/
        }
        (void)fprintf(stderr, STR_ERR_USE_HELP, argv[0], argv[0]);
        return EXIT_FAILURE;
    }
    if(display.displayMode==H_FLAG){/*If help is entered*/
        printUsage(argv[0]);/*Print the usage when help is entered*/
    }


    retVal=buildFileStruct(argv[argc-2],file1);/*Call buildFileStruct to build
                                                 the struct file and set its
                                                 values*/
    if(retVal){/*If buildFileStruct returns errno*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_BAD_FILE, argv[0],
                       argv[argc-2]);
        perror(buffer);/*Prints error message*/
        failed=1;
    }
    retVal=buildFileStruct(argv[argc-1],file2);/*Call buildFileStruct to build
                                                 the struct file and set its
                                                 values*/
    if(retVal){/*If buildFileStruct returns errno*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_BAD_FILE, argv[0],
                       argv[argc-1]);
        perror(buffer);/*Prints error message*/
        failed=1;
    }
    if(failed){
        return EXIT_FAILURE;/*Returns failure*/
    }


    if (display.displayMode==I_FLAG){/*If i flag was entered*/
        (void)findLCS(file1, file2, &list, ignoreCaseCompare);/*Generate the
                                                                lcsList*/
    }
    else{
        (void)findLCS(file1, file2, &list,defaultCompare);
    }


    retVal=makeResults(file1,file2,list,result);/*Generate the resultList*/
    if(retVal){/*If makeResults returns errno*/
        return EXIT_FAILURE;/*Returns failure*/
    }
    displayResults(result,display);/*Display the results with displayResults*/
    free(result);
    free(list);
    freeFileStruct(file1);/*Call freeFileStruct to free the memory in file1*/
    free(file1);
    freeFileStruct(file2);/*Call freeFileSturct to free the memory in file2*/
    free(file2);
    return 0;
}
