/*
 * Filename: testsetDisplayMode.c
 * Author: TODO
 * Userid: TODO  
 * Description: Unit test program to test the function setDisplayMode.
 * Date: TODO
 */

/*
 * C Std Lib Includes 
 */
#include <getopt.h>
#include <stdlib.h>

/*
 * PA4 Includes
 */
#include "pa4.h"
#include "test.h"

/*
 * Constants
 */
#define PROG_NAME "./mysdiff"
#define STR_TEST_OUTPUT "\n=== Test #%d ===\n"

static int testCount = 0;
static void
testsetDisplayMode() {
  int argc, retVal;
  char ** argv;
  struct displayOpts display;

  /* #1. Test no arguments */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  argc = 1;
  argv = malloc(sizeof(char*) * argc);
  argv[0] = PROG_NAME;
  retVal = setDisplayMode( argc, argv, &display);

  TEST( retVal == MISSING_OP_ERR );
  TEST( display.displayMode == ERR_FLAG );
  TEST( display.width == DEFAULT_WIDTH );

  optind = 0; /* reset optind for getopt_long() */

  /* #2. Test invalid option (w/ valid # of files) */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  argc = 4;
  argv = malloc(sizeof(char*) * argc+1);
  argv[0] = PROG_NAME;
  argv[1] = "-zz", argv[2] = "filea", argv[3] = "fileb";
  retVal = setDisplayMode( argc, argv, &display);

  TEST( retVal == INVALID_OPT_ERR );
  TEST( display.displayMode == ERR_FLAG );
  TEST( display.width == DEFAULT_WIDTH );

  optind = 0; /* reset optind for getopt_long() */

  /* #3. Test multiple valid flags (w/ valid # of files) */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  argc = 5;
  argv = malloc(sizeof(char*) * argc+1);
  argv[0] = PROG_NAME;
  argv[1] = "-l", argv[2] = "-i", argv[3] = "filea", argv[4] = "fileb";
  retVal = setDisplayMode( argc, argv, &display);

  TEST( retVal == 0 );
  TEST( display.displayMode == (L_FLAG | I_FLAG) );
  TEST( display.width == DEFAULT_WIDTH );

  optind = 0; /* reset optind for getopt_long() */

  /*
   * TODO
   * - Test valid flags w/ invalid # files
   * - Test invalid flags w/ invalid # files
   * - Test all other flags
   * - Test setting width
   * - etc.
   */
}

int
main() {
  testsetDisplayMode();
  (void) printf("\n");
  return 0;
}

