/*
 * Filename: pa1_strings.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Strings used in PA1 output
 * Date: 4-14-15
 * Sources of Help: Piazza, PA1 Instructions
 */


#ifndef PA1_STRINGS_H 
#define PA1_STRINGS_H


#define STR_USAGE  "\nUsage: %s X_size X_char filler_char border_char\n"\
       "    X_size      (must be within the range of [%d - %d])\n"\
       "                (must be even)\n"\
       "    X_char      (must be an ASCII value within the range [%d - %d])\n"\
       "    filler_char (must be an ASCII value within the range [%d - %d])\n"\
       "                (must be different than X_char)\n"\
       "    border_char (must be an ASCII value within the range [%d - %d])\n"\
       "                (must be different than X_char)\n\n"
 
#define STR_ERR_XSIZE_RANGE "\n\tX_size(%ld) must be within the"\
                            " range of [%d - %d]\n"


#define STR_ERR_XSIZE_EVEN "\n\tX_size(%ld) must be even\n"

#define STR_ERR_XCHAR_RANGE "\n\tX_char(%ld) must be an ASCII code"\
                            " in the range [%d - %d]\n"

#define STR_ERR_FILLERCHAR_RANGE "\n\tfiller_char(%ld) must be an "\
                                 "ASCII code in the range [%d - %d]\n"

#define STR_ERR_XCHAR_FILLERCHAR_DIFF "\n\tX_char(%ld) and "\
                                      "filler_char(%ld) must be "\
                                      "different\n"
	
#define STR_ERR_BORDERCHAR_RANGE "\n\tborder_char(%ld) must be an "\
                                 "ASCII code in the range [%d - %d]\n"
	
#define STR_ERR_XCHAR_BORDERCHAR_DIFF "\n\tX_char(%ld) and "\
                                      "border_char(%ld) must be different\n"

#define STR_CONVERTING "\n\tConverting \"%s\" base \"%d\""
	
#define STR_NOTINT "\n\t\"%s\" is not an integer\n"

#endif /* PA1_STRINGS_H */
