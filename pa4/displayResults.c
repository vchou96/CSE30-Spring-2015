/*
 * Filename: displayResults.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Displays the results of the differences as columns.
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "pa4_strings.h"
#include "lcs.h"
/*
 * Function name: displayResults
 * Description: Displays the results of the differences using the generated
 *              resultList. Iterate over each element of the results list and
 *              print the first string, the symbol, and the second string.
 *     arg1: const struct resultList* results
 *     arg2: struct displayOpts
 * Return Value: No return value.
 */
#define half 2

void displayResults(const struct resultList* results, struct displayOpts display){
    int i;/*Index to access each element of results list*/
    int fileColBuffer= (display.width-SYMBOL_WIDTH)/half;/*Calculate */

    for(i=0;i < results->numResults;i++){/*Loops until all the elements are
                                           iterated over*/
        char buffer1[BUFSIZ]={0};/*Create char array */
        char buffer2[BUFSIZ]= {0};/*Create char array*/
        char buffer3[BUFSIZ]={0};/*Create char array*/
        expandTabs(buffer1, results->startPtr[i].str1, TAB_WIDTH);/*Expand the
                                                                    tabs*/
        expandTabs(buffer2, results->startPtr[i].str2, TAB_WIDTH);
        makeFileColBuffer(buffer1, buffer1, fileColBuffer);/*Call
                                              makeFileColBuffer*/
        makeSymbolColBuffer(buffer3, results->startPtr[i].type,
                            SYMBOL_WIDTH);/*Call makeSymbolColBuffer*/
       
        if(display.displayMode & D_FLAG){/*If d flag anded with displayMode is
                                           not 0*/
            if(results->startPtr[i].type== TYPE_SAME &&
               display.displayMode & L_FLAG){/*If type is SAME*/
                (void)fprintf(stdout, buffer1);
                (void)fprintf(stdout, buffer3);
                (void)fprintf(stdout, "%c", '\n');
            }
            else if(results->startPtr[i].type==TYPE_SAME){/*If type is SAME*/
                (void)fprintf(stdout, buffer1);
                (void)fprintf(stdout, buffer3);
                (void)fprintf(stdout, STR_PRINT_BUFFER, buffer2);
                (void)fprintf(stdout, "%c", '\n');
            }
        }
        else if(display.displayMode & S_LOWER_FLAG){/*If s flag anded with
                                                      displayMode is not 0*/
            if(results->startPtr[i].type==TYPE_SAME){
                (void)fprintf(stdout, buffer1);
                (void)fprintf(stdout, buffer3);
                (void)fprintf(stdout, STR_PRINT_BUFFER, buffer2);
                (void)fprintf(stdout, "%c", '\n');
            }
        }
        else{/*If no flags are entered*/
            if(display.displayMode & L_FLAG){/*Print only left side*/
                (void)fprintf(stdout, buffer1);
                (void)fprintf(stdout, buffer3);
                (void)fprintf(stdout, "%c", '\n');
            }
            else{/*Print both sides*/
                (void)fprintf(stdout, buffer1);
                (void)fprintf(stdout, buffer3);
                (void)fprintf(stdout, STR_PRINT_BUFFER, buffer2);
                (void)fprintf(stdout, "%c", '\n');
            }
        }
    }
}
