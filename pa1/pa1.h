/*
 * Filename: pa1.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Lists function prototypes for PA1 and defines constants
 * Date: 4-14-15
 * Sources of Help: Piazza, PA1 Instructions
 */

#ifndef PA1_H
#define PA1_H

/* Local function prototypes for PA1 (written in Assembly or C) */

int checkRange( long minRange, long maxRange, long value );
void displayX( long size, long xChar, long fillerChar, long borderChar );
int isEven( long value );

#define BASE 10
#define X_SIZE_MIN 4
#define X_SIZE_MAX 5000

/*
 * See "man ascii" for ASCII char values
 */
#define ASCII_MIN 32				/* ' ' */
#define ASCII_MAX 126				/* '~' */

/*
 * void printChar( char ch );
 * int numOfDigits( long num );
 *
 * Only called from an Assembly routine. Not needed in any C routine.
 * Would get a lint message about function declared but not used.
 */

#endif /* PA1_H */
