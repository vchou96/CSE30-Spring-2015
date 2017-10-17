/*
 * Filename: testmakeResults.c
 * Author: TODO
 * Userid: TODO  
 * Description: Unit test program to test the function makeResults.
 * Date: TODO
 */

/*
 * C Std Lib Includes 
 */
#include <stdlib.h>
#include <strings.h>

/*
 * PA4 Includes
 */
#include "pa4.h"
#include "lcs.h"
#include "test.h"

/*
 * Constants
 */
#define STR_TEST_OUTPUT "\n=== Test #%d ===\n"
#define STR_ERR_RET "Returned value is non-zero.\n"
#define STR_ERR_NUM "Number of results do not match, skipping remaining"\
                    "tests.\n"

/*
 * Helper function to compare to resultLists.
 */
static int testCount = 0;
static void
testResults( struct resultList * r1, struct resultList * r2, int returned ) {
  int retVal, i;
  (void) printf(STR_TEST_OUTPUT, testCount++);

  TEST( returned == 0 );
  if( returned ) {
    (void) fprintf(stderr, STR_ERR_RET);
    return;
  }

  retVal = r1->numResults == r2->numResults;
  TEST( retVal );

  if (!retVal) {
    (void) fprintf(stderr, STR_ERR_NUM); 
    return;
  }

  // compare each line
  for( i = 0; i < r1->numResults; i++ ) {
    struct result *res1, *res2; 
    res1 = &r1->startPtr[i], res2 = &r2->startPtr[i];

    TEST( strcmp( res1->str1, res2->str1 ) == 0 );
    TEST( strcmp( res1->str2, res2->str2 ) == 0 );
    TEST( res1->f1Line == res2->f1Line );
    TEST( res1->f2Line == res2->f2Line );
    TEST( res1->type == res2->type );
  }
}

static void
testmakeResults() {
  struct lcsList* l;
  struct resultList r1, r2;
  struct file f1, f2;
  int retVal;

  /* #1. test empty files */

  // design files
  f1.numLines = 0;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f2.numLines = 0;
  f2.startPtr = malloc(sizeof(char*) * f2.numLines);

  // manually build resultList
  r1.numResults = 0;
  r1.startPtr = NULL;

  // use makeResults to build resultList
  (void) findLCS( &f1, &f2, &l, defaultCompare );
  retVal = makeResults(&f1, &f2, l, &r2);

  // test results
  testResults( &r1, &r2, retVal );


  /* #2. test file one empty file and file two non-empty */

  // design files (only have to update parts that change)
  f2.numLines = 1;
  f2.startPtr = malloc(sizeof(char*) * f2.numLines);
  f2.startPtr[0] = "abc";

  // manually build resultList
  r1.numResults = 1;
  r1.startPtr = malloc(sizeof(struct result) * r1.numResults);
  r1.startPtr[0].str1 = EMPTY;
  r1.startPtr[0].str2 = f2.startPtr[0];
  r1.startPtr[0].f1Line = 0;
  r1.startPtr[0].f2Line = 0;
  r1.startPtr[0].type = TYPE_ADD;

  // use makeResults to build resultList
  (void) findLCS( &f1, &f2, &l, defaultCompare );
  retVal = makeResults(&f1, &f2, l, &r2);

  // test results
  testResults( &r1, &r2, retVal );

  /* #3. test two one-line files that are different */

  // design files (only have to update parts that change)
  f1.numLines = 1;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f1.startPtr[0] = "hij";

  // manually build resultList (only have to update parts that change)
  r1.startPtr[0].str1 = f1.startPtr[0];
  r1.startPtr[0].type = TYPE_CHANGE;

  // use makeResults to build resultList
  (void) findLCS( &f1, &f2, &l, defaultCompare );
  retVal = makeResults(&f1, &f2, l, &r2);

  // test results
  testResults( &r1, &r2, retVal );

  /*
   * TODO
   * - Multi-line files
   * - Files with other types of results (DELETE, SAME)
   * - etc.
   */
}

int
main() {
  testmakeResults();
  (void) printf("\n");
  return 0;
}

