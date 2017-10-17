/*
 * Filename: main.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Drives the rest of the program. Checks if the input is valid,
 *              and calls displayX(). If the input is not valid then the
 *              corresponding error messages in pa1_strings.h will print.
 * Date: 4-18-2015
 * Sources of Help: Class Handouts, PA0 instructions, discussion slides, class
 *                  Piazza page
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa1_strings.h"

void displayX( long size, long xChar, long fillerChar,
               long borderChar);/*function declaration for displayX*/
int isEven( long num );/*function declaration for isEven*/
int checkRange ( long minRange, long maxRange,
                 long value);/*function declaration for checkRange*/

/*
 * Function name: main.c()
 * Description: 
 * Parameters:
 *      argc: the number of command line arguments
 *      argv: array of pointers to characters
 * Return Value: Returns 0 for successful execution.
 */
int main( int argc, char *argv[] ){
    char * str;/*Points to each argument in argv*/
    char * endptr;/*Points to end of argument, equal to null if argument is
                    int*/
    char * newLine = "\n";/*Newline at end of output*/
    char buffer [BUFSIZ];/*buffer for snfprint and perror*/
    long int value1,value2, value3, value4;/*Used to store the ints after strtol*/
    int MIN_SIZE= 4;/*Min value of size*/
    int MAX_SIZE= 5000;/*Max value of size*/
    int MIN= 32;/*Min ASCII value*/
    int MAX= 126;/*Max ASCII value*/
    int XCHAR_INDEX=2;/*Index of xChar in argv*/
    int FILLERCHAR_INDEX=3;/*Index of fillerChar in argv*/
    int BORDERCHAR_INDEX= 4;/*Index of borderChar in argv*/
    int FIVE= 5;/*Number of arguments*/
    int BASE=10;/*Base 10*/
    int passAll= 1;/*1 if passes all tests, 0 if failed*/



    /*Check for whether there are 5 arguments*/
    if ( argc != FIVE ){/*If argc is not 5*/
       (void) fprintf( stderr, STR_USAGE, argv[0], MIN_SIZE, MAX_SIZE, MIN,
                       MAX, MIN, MAX, MIN, MAX );/*Display the usage*/
        return EXIT_FAILURE;/*Exits the function*/
    }


    /*Tests for size argument*/
    errno=0;/*Set errno to 0 before strtol*/
    str= argv[1];/*set str as size input*/
    value1= strtol(str, &endptr, BASE);/*Call strtol and set value1 as return
                                       value*/
    if(!errno){ /*If errno did not change*/
        if ( *endptr!= NULL){/*If not an int*/
            (void) fprintf( stderr, STR_NOTINT, argv[1] );/*Prints not integer
                                                            error*/
            passAll=0;/*Failed a test*/
        }
        else{/*End pointer points to NULL*/
            if (!checkRange(MIN_SIZE-1, MAX_SIZE+1, value1)){/*If value is not
                                                               within the
                                                               range*/
                (void) fprintf( stderr, STR_ERR_XSIZE_RANGE, value1, MIN,
                                MAX );/*Error message for not within range*/
                passAll=0;/*Failed a test*/
            }
            if (!isEven(value1)){/*If value is not even*/
                (void)fprintf(stderr,STR_ERR_XSIZE_EVEN,value1);/*Error message
                                                                  for not
                                                                  even*/
                passAll=0;/*Failed a test*/
            }
        }
    }
    else{/*If size is too large*/
        (void) snprintf( buffer, BUFSIZ, STR_CONVERTING, argv[1],
                  BASE);/*Print converting error*/
        perror ( buffer );/*Pass buffer into perror*/
        passAll=0;/*Failed a test*/
    }


    /*Tests for xChar argument*/
    errno=0;/*Set errno to 0 before strtol*/
    str= argv[XCHAR_INDEX];/*Set str to xChar argument*/
    value2=strtol(str, &endptr, BASE);/*Call strtol and set value2 as return
                                      value*/
    if (!errno){ /*If errno did not change*/ 
        if ( *endptr!= NULL){/*If not an int*/
            (void) fprintf(stderr, STR_NOTINT, argv[XCHAR_INDEX]);/*Prints not
                                                                    integer
                                                                    error*/
            passAll=0;/*Failed a test*/
        }
        else{/*endptr points to NULL*/
            if (!checkRange(MIN-1, MAX+1, value2)){/*If value is not within
                                                     the range*/
                (void) fprintf(stderr, STR_ERR_XCHAR_RANGE, value2, MIN,
                                MAX );/*Error message for not within range*/
                passAll=0;/*Failed a test*/
            }
        }
    }
    else{/*If xChar is too large*/
        (void) snprintf(buffer, BUFSIZ, STR_CONVERTING, argv[XCHAR_INDEX],
                  BASE);/*Print converting error*/
        perror(buffer);/*Pass bufferint into perror*/
        passAll=0;/*Failed a test*/
    }

    
    /*Tests for fillerChar argument*/
    errno=0;/*Set errno as 0 before strtol*/
    str= argv[FILLERCHAR_INDEX];/*Set str as the fillerChar argument*/
    value3= strtol(str, &endptr, BASE);/*Call strtol and set value3 as return
                                       value*/
    if (!errno){/*If errno did not change*/
        if ( *endptr!= NULL){/*If not an int*/
            (void) fprintf(stderr, STR_NOTINT,
                           argv[FILLERCHAR_INDEX]);/*Prints not integer error*/
            passAll=0;/*Failed a test*/
        }
        else{/*endptr points to NULL*/
            if (!checkRange(MIN-1, MAX+1, value3)){/*If value is not within the
                                                     range*/
                (void) fprintf(stderr, STR_ERR_FILLERCHAR_RANGE, value3, MIN,
                               MAX );/*Error message for not within range*/
                passAll=0;/*Failed a test*/
            } 
            if (value2==value3){/*If xChar and filler are the same*/
                (void) fprintf(stderr, STR_ERR_XCHAR_FILLERCHAR_DIFF, value2,
                               value3 );/*Error message for same xChar and
                                          filler*/
                passAll=0;/*Failed a test*/
            }
        }
    }
    else{/*If xChar is too large*/
        (void) snprintf( buffer, BUFSIZ, STR_CONVERTING, argv[FILLERCHAR_INDEX],
                  BASE );/*Print converting error*/
        perror ( buffer );/*Pass buffer into perror*/
        passAll=0;/*Failed a test*/
    }

    /*Tests for borderChar argument*/
    errno=0;/*Set errno to 0 before strtol*/
    str= argv[BORDERCHAR_INDEX];/*Set str as borderChar argument*/
    value4= strtol(str, &endptr, BASE);/*Call strtol and set value4 as return
                                       value*/
    if (!errno){/*If errno did not change*/ 
        if ( *endptr!= NULL){/*If not an int*/
            (void) fprintf(stderr, STR_NOTINT,
                           argv[BORDERCHAR_INDEX]);/*Prints not integer error*/
            passAll=0;/*Failed a test*/
        }
        else{/*endptr points to NULL*/
            if (!checkRange(MIN-1, MAX+1, value4)){/*If value is not within
                                                     the range*/
                (void) fprintf(stderr, STR_ERR_BORDERCHAR_RANGE, value4, MIN,
                               MAX );/*Error message for not within range*/
                passAll=0;/*Failed a test*/
            }
            if (value2==value4){/*If xChar is equal to border*/
                (void) fprintf(stderr, STR_ERR_XCHAR_BORDERCHAR_DIFF, value2,
                               value4 );/*Error message for same xChar and
                                          border*/
                passAll=0;/*Failed a test*/
            }
        }
    }
    else{/*If borderChar is too large*/
        (void) snprintf( buffer, BUFSIZ, STR_CONVERTING, argv[BORDERCHAR_INDEX],
                  BASE );/*Print converting error*/
        perror ( buffer );/*Pass buffer into perror*/
        passAll=0;/*Failed a test*/
    }


    if (passAll){/*If there are no errors for all 4 arguments, run displayX*/
        displayX( value1, value2, value3, value4);/*Call displayX with value1,
                                                    value2,value3,and value4 as
                                                    arguments*/
        return 0;/*Returns after X is displayed*/
    }
    (void)fprintf(stderr,newLine);/*Extra newline*/
    return 0;/*Returns 0 for finished execution*/

}

