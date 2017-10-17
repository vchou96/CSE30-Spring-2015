/*
 * Filename: pa0_strings.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Strings used in PA0 output
 * Date: 4-6-2015
 * Sources of Help: Class handout, PA0 instructions
 */

#ifndef PA0_STRINGS_H
#define PA0_STRINGS_H

/*
 * Normal output messages
 */
#define STR_WELCOME_QUARTER "Spring 2015"
#define STR_DUEDATE         "PA0 is due on %s %d, %d\n"
#define STR_SQUARENUM       "The square of %d is %d\n"

/*
 * Error messages
 */
#define STR_ERR_USAGE       "Usage: %s [INTEGER]\n  Integer value to square\n"
#define STR_ERR_MISSING_ARG "%s: missing integer arg\n"
#define STR_ERR_EXTRA_ARG   "%s: too many arguments\n"

#endif /* PA0_STRINGS_H */
