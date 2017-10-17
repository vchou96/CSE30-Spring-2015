/*
 * Filename: setDisplayMode
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Sets the values of the struct displayOpts according to the
 *              command line arguments passed by user. 
 * Date: 5-29-2015
 * Sources of Help: Class Handouts, PA4 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "pa4_strings.h"
#include "pa4.h"
#include "lcs.h"

/*
 * Function name: setDisplayMode
 * Description: Sets the values of the struct displayOpts according to the
 *              command line arguments passed by the user using getopt_long().
 *              Supports the short and long options listed under overview.
 *              Checks that the correct number of files is passed and no two
 *              mutually exclusive flags are used.
 * Parameters: 
 *     arg1: int argc- number of arguments
 *     arg2: char* argv[]- array holding command line arguments
 *     arg3: struct displayOpts* display- pointer to struct displayOpts
 * Return Value: Returns 0 on success and the corresponding error value on
 *               failure.
 */
#define NEG -1/*Used to check if return of getopt_long is -1 or not*/

int setDisplayMode(int argc, char* argv[], struct displayOpts* display){
    char retVal;/*Holds the return values of getopt_long*/
    int width;/*HOlds optarg converted to int*/                             
    int flagD;/*Keeps track if flag d was called*/
    int flagS;/*Keeps track if flag s was called*/
    struct option optionD= {"STR_D_LONG", no_argument,
                             NULL, 'd' };/*Create struct option for d case*/
    struct option optionH= {"STR_H_LONG", no_argument,
                             NULL, 'h' };/*Create struct option for h case*/
    struct option optionI= {"STR_I_LONG", no_argument,
                             NULL, 'i' };/*Create struct option for i case*/
    struct option optionL= {"STR_L_LONG", no_argument,
                             NULL, 'l' };/*Create struct option for l case*/
    struct option optionS= {"STR_W_LONG", no_argument,
                             NULL, 's' };/*Create sturct option for w case*/
    struct option optionW= {"STR_S_LONG", no_argument,
                             NULL, 'w' };/*Create struct option for s case*/
    struct option flagOptions[]= {optionD, optionH, optionI, optionL,
                                  optionS, optionW};/*Create array of struct
                                                      options with struct
                                                      options above*/
    
    display->displayMode= 0;/*Initialize displayMode as 0*/
    display->width=DEFAULT_WIDTH;/*Initialize display's width as the
                                   default width*/
    flagD=0;/*Flag d has not been entered*/
    flagS=0;/*Flag s has not been entered*/
    retVal= getopt_long(argc,argv,ARG_STR,flagOptions,NULL);/*Set retVal as
                                                              return value of
                                                              getopt_long*/

    while(retVal!=NEG){/*While return value of getopt_long is not -1*/
        switch(retVal){/*Check cases for retVal*/
            case 0:/*If h flag is entered*/
                display->displayMode= H_FLAG|display->displayMode;/*Set
                                           displayMode as or'd H_FLAG*/
                return 0;
            case 'd':/*If d flag is entered*/
                display->displayMode= D_FLAG|display->displayMode;/*Set
                                           displayMode as or'd D_FLAG*/
                flagD=1;/*flag d was used*/
                break;
            case 'i':/*If i flag is entered*/
                display->displayMode= I_FLAG|display->displayMode;/*Set
                                           displayMode as or'd I_FLAG*/
                break;
            case 'l':/*If l flag is entered*/
                display->displayMode= L_FLAG|display->displayMode;/*Set
                                           displayMode as or'd L_FLAG*/
                break;
            case 's':/*If s flag is entered*/
                display->displayMode= S_LOWER_FLAG|display->displayMode;/*Set
                                           displayMode as or'd S_LOWER_FLAG*/
                flagS=1;/*Flag s was used*/
                break;
            case 'w':/*If w flag is entered*/
                width=strtol(optarg, NULL,0);/*Set strtol as integer value of
                                               optarg*/
                if(width<MIN_WIDTH||width>MAX_WIDTH){/*If value to set width
                                                       to is out of range or
                                                       not a number*/
                    display->displayMode= ERR_FLAG|display->displayMode;/*Set
                                               displayMode as or'd ERR_FLAG*/
                    return VALUE_ERR;/*Return value error*/
                }
                display->width=width;/*SEt display's width as width*/
                break;
            default:/*If invalid flag is entered*/
                display->displayMode= ERR_FLAG|display->displayMode;/*Set
                                           displayMode as or'd ERR_FLAG*/
                return INVALID_OPT_ERR;/*Return invalid opt error*/
            
        }
        retVal=getopt_long(argc, argv, ARG_STR, flagOptions,NULL);/*Call
                      getopt_long again and set retVal as return value*/
    }
    if(flagD && flagS){/*If both d and s flags were entered*/
        display->displayMode=ERR_FLAG|display->displayMode;/*Set displayMode
                                                             as or'd ERR_FLAG*/
        return EXCLUSION_ERR;/*Return mutually exclusive error*/
    }
    if(argc-optind<NUM_FILES){/*If there aren't enough files passed in*/
        display->displayMode=ERR_FLAG|display->displayMode;/*Set displayMode
                                                             as or'd ERR_FLAG*/
        return MISSING_OP_ERR;/*Return missing op error*/
    }
    if(argc-optind>NUM_FILES){/*If there are too many files passed in*/
        display->displayMode=ERR_FLAG|display->displayMode;/*Set displayMode
                                                             as or'd ERR_FLAG*/
        return EXTRA_OP_ERR;/*Return extra op error*/
    }
    return 0;/*Returns 0 for success*/
}

