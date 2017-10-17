/*
 * Filename: testdefaultCompare.c
 * Author: TODO
 * Userid: TODO  
 * Description: Unit test program to test the function defaultCompare.
 * Date: TODO
 */

/*
 * C Std Lib Includes 
 */

/*
 * PA4 Includes
 */
#include "pa4.h"
#include "test.h"

/*
 * Constants
 */
#define STR_TEST_OUTPUT "\n=== Test #%d ===\n"

static int testCount = 0;
static void
testdefaultCompare() {
  char *a, *b;

  /* #1. Test empty strings */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "", b = "";
  TEST( defaultCompare( a, b ) == 0 );


  /* #2. Test empty against non-empty */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "a", b = "";
  TEST( defaultCompare( a, b ) > 0 );


  /* #3. Test string of different length */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "abc", b = "xyz";
  TEST( defaultCompare( a, b ) < 0 );


  /* #4. Test a < b */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "a", b = "b";
  TEST( defaultCompare( a, b ) < 0 );

  /*
   * TODO
   * - Test a == b, a > b
   * - Test case-sensitivity
   * - etc.
   */
}

int
main() {
  testdefaultCompare();
  (void) printf("\n");
  return 0;
}

