/*
 * Filename: pa4_strings.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Strings used in pa4.
 */

#ifndef PA4_STRINGS_H
#define PA4_STRINGS_H

// usage string
#define STR_USAGE_LONG "Usage: %s file1 file2\n"\
  "Compares file1 and file2 line by line.\n\n"\
  "Mandatory arguments to long options are mandatory for short options too.\n"\
  "  -d, --suppress-different-lines   hides lines that are different\n"\
  "  -i, --ignore-case                ignores capitalization\n"\
  "  -l, --left-column                prints same lines only on left column\n"\
  "  -s, --suppress-common-lines      hides lines that are the same\n"\
  "  -S, --summary                    prints a brief summary after results\n"\
  "  -w, --width=NUM                  sets output width to NUM characters\n"\
  "  -W, --ignore-all-space           ignores whitespace (spaces and tabs)\n"\
  "\n"\
  "      --help                       displays this help and exit\n"

// getopt() strings
#define ARG_STR "dilsw:"
// extra credit
#define ARG_STR_EC "dilsSw:W"

#define STR_D_LONG        "suppress-different-lines"
#define STR_H_LONG        "help"
#define STR_I_LONG        "ignore-case"
#define STR_L_LONG        "left-column"
#define STR_W_LOWER_LONG  "width"
#define STR_S_LOWER_LONG  "suppress-common-lines"
// extra credit
#define STR_S_UPPER_LONG  "summary"
#define STR_W_UPPER_LONG  "ignore-all-space"

// file open mode for reading
#define FILE_OPEN_MODE "r"

// output symbols
#define STR_ADD         "  +  "
#define STR_DELETE      "  -  "
#define STR_CHANGE      "  |  "
#define STR_SAME        "     "
#define STR_SYMBOL_COL  "%s"
#define STR_SUMMARY "==== Summary ====\n"\
                    "Lines Added: \t%d\nLines Deleted: \t%d\n"\
                    "Lines Changed:\t%d\nLines Same: \t%d\n"\
                    "=================\n"

// error strings
#define STR_ERR_FILE_READ       "%s: File read"
#define STR_ERR_BAD_FILE        "%s: %s"
#define STR_ERR_ALLOC           "%s: Allocation error"
#define STR_ERR_MISSING_OPERAND "%s: missing operand after \'%s\'\n"
#define STR_ERR_EXTRA_OPERAND   "%s: extra operand \'%s\'\n"
#define STR_ERR_USE_HELP        "%s: Try '%s --help' for more information.\n"
#define STR_ERR_INVALID_WIDTH   "%s: invalid width. \n"
#define STR_ERR_MUTUAL_EXL      "%s: flags 'd' and 's' are mutually "\
                                "exclusive.\n"

// printing a buffer
#define STR_PRINT_BUFFER "%s"

#endif /* PA4_STRINGS_H */
