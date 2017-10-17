/*
 * Filename: pa3_strings.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Strings used in pa3.
 */

#ifndef PA3_STRINGS_H
#define PA3_STRINGS_H

/*
 * Error strings used in main
 */
#define STR_ERR_FOPEN "\nError opening dictionary file"
#define STR_ERR_HCREATE "\nError creating hash table"
#define STR_ERR_DB_CREATE "\nError creating anagram database\n\n"

/*
 * String used for usage
 */
#define STR_USAGE "\nUsage: %s dictionary_file\n"\
                  "\tdictionary_file - containing a list of words\n\n"

/*
 * Strings used for user interaction
 */
#define STR_SEARCH "Enter a word to search for anagrams [^D to exit]: "
#define STR_NO_ANAGRAMS_FOUND "\nNo anagrams found."
#define STR_ANAGRAMS_FOUND "\nAnagram(s) are: "
#define STR_FIRST_ANAGRAM_WORD "%s"
#define STR_ANAGRAM_WORD ", %s"
#define STR_ONE_NEW_LINE "\n" /* use after displaying the last anagram word */
#define STR_NEW_LINE "\n\n" /* use after displaying the last anagram word */

#endif /* PA3_STRINGS_H */

