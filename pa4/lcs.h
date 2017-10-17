/*
 * Filename: lcs.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Finding the longest common substring of lines of text.
 */

#ifndef LCS_H
#define LCS_H

/*
 * Constants
 */
#define EMPTY ""

/*
 * Struct Definitions
 */

// An array of char* for each line of a file.
struct file {
  char** startPtr;
  int numLines;
};

// A common element between the files.
struct lcsElem {
  const void* elem;
  int f1Line;
  int f2Line;
};

/* 
 * An array of struct lcsElem* for all similarities between the files.
 * In total, the array represents the longest common subsequence.
 */
struct lcsList {
  struct lcsElem* startPtr;
  int numElems;
};

/*
 * Function prototypes
 */
int
findLCS(const struct file* f1, const struct file* f2,struct lcsList** list,
        int (*compar)(const void*, const void*));

#endif /* LCS_H */
