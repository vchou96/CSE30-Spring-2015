/*
 * Filename: main.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Drives the rest of the program. Parses the command line
 * arguments, creates the mask, encrypts/decrypts, and closes the file. 
 * Date: 5-3-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa2_strings.h"
#include "pa2.h"

/*
 * Function name: main.c
 * Description: Parses the command line arguments, creates the mask,
 *              encrypts/decrypts, and closes the file. If there are errors
 *              then it will skip creating the mask and encryption/decryption
 *              and instead print the errors.
 * Parameters: 
 *     arg1: int argc -- Number of arguments on command line 
 *     arg2: char *argv -- Array that contains the user-inputted arguments
 * Return Value: Returns 0 for successful execution.
 */

int main(int argc, char*argv[]){
    int numOfErrors=0;/*The number of errors that occurred when parsing the
                        arguments*/
    char buffer [BUFSIZ];/*Buffer for snprintf/perror*/
    char *str;/*Stores value of user-inputted arguments*/
    char passPhrase[8];/*Argument for parsePassPhrase*/
    long *rotateValue;/*Argument for parseRotateValue*/
    long rotateVal;/*long that rotateValue points to*/
    unsigned long key1;/*Argument for parseKey*/
    unsigned long key2;/*Argument for parseKey*/
    FILE *inFile;/*Argument for parseInput*/
    unsigned long keys[2];/*Array to hold the keys*/
    unsigned long mask[2];/*Array to hold 64-bit mask*/


    (void) setvbuf(stdout, NULL, _IONBF, 0);/*Disables buffering on stdout*/

    if (argc - 1 < EXPECTED_ARGS){/*If there are less than EXPECTED_ARGS
                                    arguments*/
        (void)fprintf(stderr, STR_USAGE, argv[0], MIN_ROTATE,
                      MAX_ROTATE );/*Displays the usage*/
        return EXIT_FAILURE;/*Exits the function*/
    }

    /*Parsing the passphrase*/
    str= argv[PASS_PHRASE_INDEX];/*set str as the passphrase*/
    if (parsePassPhrase(str, passPhrase)){/*If parsePassPhrase returns
                                             LENGTH_ERR*/
        ++numOfErrors;/*Increment the number of errors*/
        (void)fprintf(stderr, STR_ERR_BAD_PASSPHRASE, PASS_PHRASE_SIZE);/*Prints
                                                    bad passphrase error*/
    }

    /*Parsing the first key*/
    errno=0;/*Set errno as 0*/
    str= argv[KEY_ONE_INDEX];/*Set str as first key argument*/
    if (parseKey(str, &key1)==ERANGE_ERR){/*If parseKey returns ERANGE_ERR*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_CONVERTING, str,
                       DEF_BASE);/*call snprintf to handle error printing*/
        perror(buffer);/*Call perror and pass buffer to handle error
                         printing*/
        ++numOfErrors;/*Increment the number of errors*/
    }
    if (parseKey(str, &key1)==ENDPTR_ERR){/*If parseKey returns
                                                 ENDPTR_ERR*/
        (void)fprintf(stderr, STR_ERR_NOTINT, str);/*Print not int error*/
        ++numOfErrors;/*Increment the number of errors*/
    }

    /*Parsing the second key*/
    errno=0;/*Set errno as 0*/
    str= argv[KEY_TWO_INDEX];/*Set str as second key argument*/
    if (parseKey(str, &key2)==ERANGE_ERR){/*If parseKey returns ERANGE_ERR*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_CONVERTING, str,
                       DEF_BASE);/*Call snprintf to handle error printing*/
        perror(buffer);/*Call perror and pass buffer to handle error
                         printing*/
        ++numOfErrors;/*Increment the number of errors*/
    }
    if(parseKey(str, &key2)==ENDPTR_ERR){/*If parseKey returns
                                                 ENDPTR_ERR*/
        (void)fprintf(stderr, STR_ERR_NOTINT, str);/*Call snprintf
                                                  to handle error printing*/
        ++numOfErrors;/*Increment the number of errors*/
    }
    
    /*Parsing the rotation value*/
    errno=0;/*set errno as 0*/
    str=argv[ROTATE_VALUE_INDEX];/*set str as the rotation value*/
    rotateValue= &rotateVal;/*Point rotateValue to rotateVal*/
    if(parseRotateValue(str, rotateValue)==ERANGE_ERR){/*if parseRotateValue
                                                         returns ERANGE_ERR*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_CONVERTING, str,
                       DEF_BASE);/*Call snprintf to handle error printing*/
        perror(buffer);/*Call perror and pass buffer to handle error
                         printing*/ 
        ++numOfErrors;/*Increment number of errors*/
    }
    if (parseRotateValue(str, rotateValue)==BOUND_ERR){/*If parseRotateValue
                                                         returns BOUND_ERR*/
        (void)fprintf(stderr, STR_ERR_BAD_ROT, MIN_ROTATE,
                MAX_ROTATE);/*Print bad rotation value error*/
        ++numOfErrors;/*Increment the number of errors*/
    }
    if (parseRotateValue(str, rotateValue)==ENDPTR_ERR){/*If parseRotateValue
                                                          returns ENDPTR_ERR*/
        (void)fprintf(stderr, STR_ERR_NOTINT, str);/*Print error message
                                                     since not int*/
        ++numOfErrors;/*Increment number of errors*/
    }      




    /*Parsing the input file*/
    str=argv[FILE_INDEX];/*set str as the input file*/
    if (parseInput(str, &inFile)){/*If parseInput returns FILE_ERR*/
        (void)snprintf(buffer, BUFSIZ, STR_ERR_BAD_FILE,
                       str);/*Call snprintf to handle error printing*/
        perror(buffer);/*Call perror and pass buffer*/
        ++numOfErrors;/*Increment the number of errors*/
    } 
    
    if(numOfErrors){
        (void)fprintf(stderr, STR_ERR_NUM_ERRORS, numOfErrors);/*Print the number of
                                                      errors encountered*/
    }
    else{/*If there are no errors*/
        keys[0]= key1;/*Set key1 as 1st key*/
        keys[1]= key2;/*Set key2 as 2nd key*/
        createMask(keys, passPhrase, mask);/*Create the mask*/
        mycrypt(inFile, mask, rotateVal);/*Call mycrypt*/
    }
    (void)fclose(inFile);/*Closes the inFile*/
    return 0;/*Returns from function*/
}
