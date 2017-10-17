/*
 * Filename: makeResults.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Generates a resultList based on lcsList. Dynamically grows the
 *              resultList by adding elements with appendResult(). 
 * Date: 5-25-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */

#include <search.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "lcs.h"

/*
 * Function name: makeResults
 * Description: Generates a resultList based on lcsList. Dynamically grows the
 *              resultList by adding elements with appendResult().
 * Parameters: 
 *     arg1: const struct file* f1- pointer to file 1
 *     arg2: const struct file* f2- pointer to file 2
 *     arg3: const struct lcsList* list-generated list from the call before
 *     arg4: struct resultList* results- resultList to be expanded dynamically
 * Return Value: Returns 0 on success and errno on failure.
 */


int makeResults(const struct file* f1, const struct file* f2, const struct
                lcsList* list, struct resultList* results){
    int file1Pos=0;/*Initializes file 1 position value to 0*/
    int file2Pos=0;/*Initialize file 2 position value to 0*/
    int LCSPos=0;/*Initialize LCS position value to 0*/
    int distance1;/*Distance between f1Line and file1Pos*/
    int distance2;/*Distance between f2Line and file2Pos*/
    int infinite=1;/*Mkaes while loop run infinitely until break or return*/


    results->numResults=0;/*Set numResults as 0*/
    errno=0;/*Set errno as 0*/    
    while(infinite){/*Loops infinitely until break*/    
        distance1= list->startPtr[LCSPos].f1Line - file1Pos;/*Set distance1 as
                                                              distance between
                                                              f1Line and
                                                              file1Pos*/
        distance2= list->startPtr[LCSPos].f2Line - file2Pos;/*Set distance2 as
                                                              distance between
                                                              f2Line and
                                                              file2Pos*/
        if(!distance1 && !distance2){/*If distance1 and distance2 are 0*/
            errno=appendResult(&results->startPtr, f1, f2, file1Pos, file2Pos,
                               TYPE_SAME,results->numResults);/*Call
                                                                appendResult to
                                                                grow the
                                                                resultList*/
            if(errno){/*If appendResult returned errno*/
                return errno;/*Return errno for failure*/ 
            }
            file1Pos++;/*Increment the file 1 position*/
            file2Pos++;/*Increment the file 2 position*/
            LCSPos++;/*Increment the LCS position*/
        }
        else if(!distance1 && distance2){/*If distance1 is 0 and distance2 is
                                           greater than 0*/
            errno=appendResult(&results->startPtr,NULL, f2, file1Pos, file2Pos,
                               TYPE_ADD,results->numResults);/*Call
                                                               appendResult to
                                                               grow
                                                               resultList*/
            if(errno){/*If appendResult returned errno*/
                return errno;/*Return errno for failure*/
            }
            results->numResults++;/*Increment the number of results*/
            file2Pos++;/*Increment the file 2 position*/
        }
        else if(distance1 && !distance2){/*If distance1 is greater than 0 and
                                           distance2 is 0*/
            errno=appendResult(&results->startPtr,f1, NULL, file1Pos, file2Pos,
                               TYPE_DELETE,results->numResults);/*Call
                                                                  appendResult
                                                                  to grow the
                                                                  resultList*/
            if(errno){/*If appendResult returned errno*/
                return errno;/*Return errno for failure*/
            }
            results->numResults++;/*Increment the number of results*/
            file1Pos++;/*Increment the file 1 position*/
        }
        else if(distance1 && distance2){/*If distance1 and distance2 are both
                                          greater than 0*/
            errno=appendResult(&results->startPtr,f1, f2, file1Pos, file2Pos,
                               TYPE_CHANGE,results->numResults);/*Call
                                                                  appendResult
                                                                  to grow
                                                                  resultList*/
            if(errno){/*If appendResult returned errno*/
                return errno;/*Return errno for failure*/
            }
            results->numResults++;/*Increment the number of results*/
            file1Pos++;/*Increment the file 1 position*/
            file2Pos++;/*Increment the file 2 position*/
        }

        if(!distance1 && !distance2 && LCSPos==list->numElems){/*If distances
                                                                 are 0 and
                                                                 LCSPos is at
                                                                 sentinel
                                                                 node*/
            break;
        }
    }
    return 0;/*Return 0 for success*/


}
