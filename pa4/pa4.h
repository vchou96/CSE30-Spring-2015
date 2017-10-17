/*
 * Filename: pa4.h
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Struct defintions and function prototypes for pa4.
 */


#ifndef PA4_H
#define PA4_H

#include "lcs.h"

/*
 * Program constants
 */
// input flags
#define ERR_FLAG     0x1
#define D_FLAG       0x2
#define H_FLAG       0x4
#define I_FLAG       0x8
#define L_FLAG       0x10
#define S_LOWER_FLAG 0x20
// extra credit
#define S_UPPER_FLAG 0x40
#define W_UPPER_FLAG 0x80

// input constraints
#define MIN_WIDTH     20 
#define MAX_WIDTH     200
#define DEFAULT_WIDTH 130
#define NUM_FILES     2

// error types
#define INVALID_OPT_ERR 1
#define MISSING_OP_ERR  2
#define EXTRA_OP_ERR    3
#define VALUE_ERR       4 
#define EXCLUSION_ERR   5

// result types
#define TYPE_ADD    1
#define TYPE_DELETE 2
#define TYPE_CHANGE 3
#define TYPE_SAME   4

// etc.
#define TAB_WIDTH           8
#define SYMBOL_WIDTH        5

/*
 * Structure definitions
 */

// A single similarity or difference between the two files. Used for output.
struct result {
  const char* str1;
  const char* str2;
  int f1Line;
  int f2Line;
  unsigned int type;
};

// An array of struct result* for the whole comparison between the files.
struct resultList {
  struct result* startPtr;
  int numResults;
};

// Defines display options
struct displayOpts {
  unsigned int displayMode;
  unsigned int width;
};

/*
 * Function prototypes
 */

/* Comparison functions */
int
defaultCompare(const void* p1, const void* p2);

int
ignoreCaseCompare(const void* p1, const void* p2);

/* Display */
void
expandTabs(char* s1, const char*s2, int n);

void
makeSymbolColBuffer(char* s1, unsigned int type, int n);

void
makeFileColBuffer(char* s1, const char* s2, int n); 

void
printUsage(const char *filename);

int
setDisplayMode(int argc, char* argv[], struct displayOpts* display);

/* File Handling */
int
buildFileStruct(const char* name, struct file* file);

int
freeFileStruct(const struct file* file);

void
stripNewLine(char *s1);

/* Results */
int
appendResult(struct result** results, const struct file* f1,
                  const struct file* f2, int pos1, int pos2, 
                  unsigned int type, int count);

void
displayResults(const struct resultList* results, const struct displayOpts);

int
makeResults(const struct file* f1, const struct file* f2,
            const struct lcsList* list, struct resultList* results);

/* Extra credit */
/*
int
stripWSCompare(const void* p1, const void* p2);

int
stripWSAndIgnoreCaseCompare(const void* p1, const void* p2);

void
stripWhitespace(char *str);
*/

#endif /* PA4_H */

