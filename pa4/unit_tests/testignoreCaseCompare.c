/*
 * Filename: testignoreCaseCompare.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function ignoreCaseCompare.
 * Date: 5-27-15
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
testignoreCaseCompare() {
  char *a, *b;

  /* #1. Test empty strings */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "", b = "";
  TEST( ignoreCaseCompare( a, b ) == 0 );


  /* #2. Test empty against non-empty */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "a", b = "";
  TEST( ignoreCaseCompare( a, b ) > 0 );


  /* #3. Test string of different length */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "abc", b = "xyz";
  TEST( ignoreCaseCompare( a, b ) < 0 );


  /* #4. Test a < b */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "a", b = "b";
  TEST( ignoreCaseCompare( a, b ) < 0 );


  /* #5. Test case-insensitivity */ 
  (void) printf(STR_TEST_OUTPUT, testCount++);
  a = "abCH", b = "ABch";
  TEST( ignoreCaseCompare( a, b ) == 0 );

  /*
   * TODO
   * - Test a == b, a > b
   * - Test more case-insensitive examples
   * - etc.
   */

}

int
main() {
  testignoreCaseCompare();
  (void) printf("\n");
  return 0;
}

