/*
 * Filename: appendResult.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Appends a new struct result to a dynamic array of struct
 *              results. Creates a new struct result and reallocs space for
 *              a new struct result at the end of the array.
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
 * Function name: appendResult
 * Description: Appends a new struct result to a dynamic array of struct
 *              results. Creates a new struct result using passed in values,
 *              and uses realloc to allocate space for a new struct result.
 *              Uses memmove to move the value into the newly allocated
 *              space.
 * Parameters: 
 *     arg1: struct results** results- address of startPtr in resultList
 *     arg2: const struct file* f1- pointer to file, provides values for new
 *                                  struct result
 *     arg3: const struct file* f2- pointer to file, provides values for new
 *                                  struct file
 *     arg4: int file1Pos- Used as index in startPtr array
 *     arg5: int file2Pos- Used as index in startPtr array
 *     arg6: unsigned int type- Type to set new struct result's type as
 *     arg7: int count- number of struct results already in the array
 * Return Value: Returns 0 on success and errno on error.
 */

int appendResult(struct result** results, const struct file* f1,
                 const struct file* f2, int file1Pos, int file2Pos,
                 unsigned int type, int count){
    struct result temp;/*Temporary struct to append to array*/
    
    if(!f1){/*If file pointer is NULL*/
        temp.str1= EMPTY;/*Set string to EMPTY*/
        temp.f1Line=file1Pos;/*Set f1Line as file1Pos*/
        temp.type=type;/*Store type passed in as temp's type*/
    }
    else{
        temp.str1=f1->startPtr[file1Pos];/*Set string as pos1th element*/
        temp.f1Line=file1Pos;/*Set f1Line as file1Pos*/
        temp.type=type;/*Store type passed in as temp's type*/
    }

    if(!f2){/*If file pointer is NULL*/
        temp.str2=EMPTY;/*Set string to EMPTY*/
        temp.f2Line= file2Pos;/*Set f2Line as file2Pos*/
        temp.type=type;/*Store type passed in as temp's type*/
    }
    else{
        temp.str2=f2->startPtr[file2Pos];/*Set string as pos2th element*/
        temp.f2Line=file2Pos;/*Set f2Line as file2Pos*/
        temp.type=type;/*Store type passed in as temp's type*/
    }

    *results=realloc(*results,(sizeof(struct result)*count)
                     +sizeof(struct result));/*Reallocate extra space for
                                              struct result to be appended*/
    if(!*results){/*If return result is null pointer*/
        return errno;/*return errno*/
    }
    memmove((&((*results)[count])),&temp,sizeof(struct result));/*memmove new
                                                                  struct into
                                                                  array*/
    return 0;/*Returns if successful*/
}
