/*
 * Filename: pa3.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Header used in pa3.
 */

#ifndef _PA3_H_
#define _PA3_H_

#define HASH_TABLE_SIZE 403229
#define EXPECTED_ARGS   1
#define MAX_WORD_LENGTH 80 /* Longest word that can be stored in an anagram
                              struct */
/*
 * C Standard Library headers
 */
#include <stdio.h>  /* FILE* */

/*
 * Anagram entry. We make the size MAX_WORD_LENGTH + 1 to allow for words whose
 * lengths are actually MAX_WORD_LENGTH or less.
 */
struct anagram {
  char word[MAX_WORD_LENGTH+1]; /* original anagram word */
};

/*
 * Anagram header which holds the key (representing the lowercase sorted version
 * of the word) and an array of anagrams who lowercase sorted representation
 * matches key.
 */
struct anagramHeader {
  char key[MAX_WORD_LENGTH+1]; /* lowercase sorted version of word */
  struct anagram *anagrams;
  size_t numElements;
};

/*
 * Function prototypes
 */
int
appendAnagram(struct anagramHeader *head, struct anagram *anagram);

struct anagramHeader *
createAnagramHeader(const char *key);

int
initTable(FILE *file);

int
charCompare(const void *lhs, const void *rhs);

void
createHashKey(char *key,
              const char *src,
              int (*compare)(const void *, const void *));

void
printAnagrams(struct anagramHeader *head, char *word);

void
printUsage(const char *programName);

void
searchForAnagrams();

void
stripNewLine(char *str);

#endif /* _PA3_H_ */

