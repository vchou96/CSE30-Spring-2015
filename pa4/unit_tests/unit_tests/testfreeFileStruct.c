/*
 * Filename: testfreeFileStruct.c
 * Author: TODO
 * Userid: TODO  
 * Description: Unit test program to test the function freeFileStruct.
 * Date: TODO
 */

/*
 * C Std Lib Includes 
 */
#include <stdlib.h>

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

static int testCount = 0;
static void
testfreeFileStruct() {
  struct file f1;

  /* #1. Test empty file  */
  (void) printf(STR_TEST_OUTPUT, testCount++);

  // manually build
  f1.numLines = 0;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);

  // test freeing
  TEST( freeFileStruct( &f1 ) == f1.numLines + 1 );


  /* #2. Test non-empty file */
  (void) printf(STR_TEST_OUTPUT, testCount++);

  // manually build file
  f1.numLines = 5;
  f1.startPtr = malloc(sizeof(char*) * f1.numLines);
  f1.startPtr[0] = "jjjk";
  f1.startPtr[1] = "cse30rules!";
  f1.startPtr[2] = "c>java";
  f1.startPtr[3] = "piazza";
  f1.startPtr[4] = "pizza";

  // test freeing
  TEST( freeFileStruct( &f1 ) == f1.numLines + 1 );

  /*
   * TODO
   * - Test longer files
   * - Test files with blank lines
   * - etc.
   */
}

int
main() {
  testfreeFileStruct();
  (void) printf("\n");
  return 0;
}

