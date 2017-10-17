/*
 * Filename: buildFileStruct.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Read in a file to memory using fgets() into a buffer of
 *              BUFSIZ. Allocates an array of char pointers and creates char
 *              arrays to store each line. Set the correct values in the
 *              struct file passed in.
 * Date: 5-25-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */
#include <search.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "lcs.h"
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: buildFileStruct
 * Description: Use fgets to read in a file to memory into a buffer. If the
 *              file opens, use realloc to allocate an array of char pointers
 *              and malloc to create char arrays to store each line. Set the
 *              correct values in the struct file passed in.
 * Parameters: 
 *     arg1: const char* name- char array
 *     arg2: struct file* file- struct file to set correct values in
 * Return Value: Returns 0 on success and errno on error.
 */

int buildFileStruct(const char* name, struct file* file){
    FILE* fp;/*Pointer to file opened*/
    char buffer[BUFSIZ]={0};/*Buffer to hold line read in*/

    file->startPtr=NULL;/*Set startPtr as NULL*/
    file->numLines=0;/*Set number of lines as 0*/
    errno=0;/*Set errno as 0*/
    fp=fopen(name, FILE_OPEN_MODE);/*Opens the file*/
    if(errno){/*If errno changed*/
        return errno;/*Return errno*/
    }
    while(fgets(buffer,BUFSIZ,fp)){/*While there is input from command line*/
        stripNewLine(buffer);/*Strips newline char*/
        file->startPtr=realloc(file->startPtr, 
                               sizeof(char*)*(file->numLines+1));/*Allocates a
                                                                   char pointer
                                                                   for each
                                                                   line in
                                                                   array*/
        if(!file->startPtr){/*If realloc returns null pointer*/
            return errno;/*Return errno if realloc returns null pointer*/
        }
        file->startPtr[file->numLines]=malloc(sizeof(buffer)+1);/*Allocate
                                                                  enough space
                                                                  for the
                                                                  line*/
        if(!file->startPtr[file->numLines]){/*If return value of malloc is null
                                              pointer*/
            return errno;/*Return errno*/
        }
        file->startPtr[file->numLines]=memmove(file->startPtr[file->numLines],
                                               buffer,strlen(buffer)+1);
                                               /*Moves each string line into
                                               array*/ 
        file->numLines++;/*Increment number of lines*/
    }
    (void)fclose(fp);/*Closes the file*/
    return 0;/*Return 0 on success*/
}
