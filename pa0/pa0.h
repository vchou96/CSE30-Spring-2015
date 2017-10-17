/*
 * Filename: pa0.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Function prototypes and defines for PA0
 * Date: 4/6/2015
 * Sources of Help: Class Handout, PA0 instructions
 */

#ifndef PA0_H
#define PA0_H

#define EXPECTED_ARGS 1
#define SEVEN 7 /*Used as due date's day*/
#define YEAR 2015 /*Used as due date's year*/
/*User-defined types used in PA0*/

struct DueDate {
  const char *month;
  unsigned int day;
  unsigned int year;
};

/* Function prototypes for the C and assembly routines used in PA0 */

void printDueDate( const struct DueDate *dueDate );
void printWelcome( const char *string );

int squareNum( int num );

#endif /* PA0_H */
