/*
 * Filename: testbuildFileStruct.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function buildFileStruct.
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
#define testFile1 "unit_tests/test_files/testFile1"
#define testFile2 "unit_tests/test_files/testFile2"
#define testFile3 "unit_tests/test_files/testFile3"
#define STR_TEST_OUTPUT "\n=== Test #%d ===\n"
#define STR_ERR_RET "Returned value is non-zero.\n"
#define STR_ERR_NUM "Number of lines do not match, skipping remaining tests.\n"\
                    "Expected: %d, Found: %d\n"

/*
 * Helper function to compare two files.
 */
static int testCount = 0;
static void
testFiles( struct file * f1, struct file * f2, int returned ) {
  int retVal, i;

  (void) fprintf(stdout, STR_TEST_OUTPUT, testCount++);

  TEST( returned == 0 );
  if( returned ) {
    (void) fprintf(stderr, STR_ERR_RET);
    return;
  }

  retVal = f1->numLines == f2->numLines;
  TEST( retVal );

  if (!retVal) {
    (void) fprintf(stderr, STR_ERR_NUM, f1->numLines, f2->numLines);
    return;
  }

  // compare each line
  for( i = 0; i < f1->numLines; i++ ) {
    TEST( strcmp( f1->startPtr[i], f2->startPtr[i] ) == 0 );
  }
}

static void
testbuildFileStruct() {
  struct file f1, f2;
  int retVal;

  /* #1. Test empty file  */

  // manually build file
  f1.numLines = 0;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);

  // build file
  retVal = buildFileStruct( testFile1, &f2 );

  // test file
  testFiles( &f1, &f2, retVal );


  /* #2. Test one line file */

  // manually build file
  f1.numLines = 1;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f1.startPtr[0] = "abcde";

  // build file
  retVal = buildFileStruct( testFile2, &f2 );

  // test file
  testFiles( &f1, &f2, retVal );


  /* #3. Test normal file */

  // manually build file
  f1.numLines = 5;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f1.startPtr[0] = "jjjk";
  f1.startPtr[1] = "cse30rules!";
  f1.startPtr[2] = "c>java";
  f1.startPtr[3] = "piazza";
  f1.startPtr[4] = "pizza";

  // build file
  retVal = buildFileStruct( testFile3, &f2 );

  // test file
  testFiles( &f1, &f2, retVal );

  /*
   * TODO
   * - Test files with longer lines
   * - Test files with more lines
   * - etc.
   */
}

int
main() {
  testbuildFileStruct();
  (void) printf("\n");
  return 0;
}

