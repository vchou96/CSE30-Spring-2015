/*
 * Filename: testappendResult.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function appendResult.
 * Date: 5-27-15
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
#define NUM_TESTS 4
#define STR_TEST_OUTPUT "\n=== Test #%d ===\nf1Line: %d\tstr1: '%s'\t" \
                        "f2Line: %d\tstr2: '%s'\ttype: %d\n\n"

static int testCount = 0;

/*
 * Helper function to test a struct result.
 */
static void
testResult( struct result* rElem, int retVal, char* str1, char* str2, int f1Line,
            int f2Line, int type ) {
  (void) fprintf( stdout, STR_TEST_OUTPUT, testCount++, f1Line, str1, f2Line,
                  str2, type );
  TEST( retVal == 0 );
  TEST( strcmp(rElem->str1, str1) == 0 ); 
  TEST( strcmp(rElem->str2, str2) == 0 ); 
  TEST( rElem->f1Line == f1Line );
  TEST( rElem->f2Line == f2Line );
  TEST( rElem->type == type );
}

static void
testappendResult() {
  struct resultList r;
  struct file f1, f2;
  struct file *file1[NUM_TESTS]; struct file *file2[NUM_TESTS];
  int pos1[NUM_TESTS], pos2[NUM_TESTS], type[NUM_TESTS], i = 0, retVal;

  // manually initialize files
  f1.numLines = 3;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f1.startPtr[0] = "abcde";
  f1.startPtr[1] = "fghij";
  f1.startPtr[2] = "klmnop";

  f2.numLines = 5;
  f2.startPtr = malloc(sizeof(char*) * f2.numLines);
  f2.startPtr[0] = "jjjk";
  f2.startPtr[1] = "cse30rules!";
  f2.startPtr[2] = "c>java";
  f2.startPtr[3] = "piazza";
  f2.startPtr[4] = "pizza";

  // initialize resultList
  r.startPtr = NULL; r.numResults = 0;

  /* #1. Test adding first element */
  pos1[0]   = rand() % f1.numLines; /* arbitrary for this test */
  pos2[0]   = rand() & f2.numLines; /* arbitrary for this test */
  type[0]   = TYPE_SAME;            /* arbitrary for this test */
  file1[0] = &f1;
  file2[0] = &f2;

  /* #2. Test adding with both positions being zero */ 
  pos1[1]   = 0;
  pos2[1]   = 0; 
  type[1]   = TYPE_CHANGE;          /* arbitrary for this test */
  file1[1] = &f1;
  file2[1] = &f2;

  /* #3. test adding a ADD result */
  pos1[2]   = rand() % f1.numLines; /* arbitrary for this test */
  pos2[2]   = rand() & f2.numLines; /* arbitrary for this test */
  type[2]   = TYPE_ADD;
  file1[2] = NULL;
  file2[2] = &f2;

  /* #4. test adding a DELETE result */
  pos1[3]   = rand() % f1.numLines; /* arbitrary for this test */
  pos2[3]   = rand() & f2.numLines; /* arbitrary for this test */
  type[3]   = TYPE_DELETE;
  file1[3] = &f1;
  file2[3] = NULL;
  
  // run tests
  for( i = 0; i < NUM_TESTS; i++ ) {
    char *str1 = file1[i] ? file1[i]->startPtr[pos1[i]]: EMPTY;
    char *str2 = file2[i] ? file2[i]->startPtr[pos2[i]]: EMPTY;

    // append element w/ defined values
    retVal = 
    appendResult(&r.startPtr, file1[i], file2[i], pos1[i], pos2[i], type[i], i);

    // test result
    testResult( &r.startPtr[i], retVal, str1, str2, pos1[i], pos2[i], type[i] ); 
  }

  /*
   * TODO: Add addtional tests
   * - Test using type CHANGE
   * - Test using type SAME
   * - Test adding results with positions at end of file
   */
}

int
main() {
  testappendResult();
  (void) printf("\n");
  return 0;
}

