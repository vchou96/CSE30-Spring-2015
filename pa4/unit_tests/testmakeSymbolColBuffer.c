/*
 * Filename: testmakeSymbolColBuffer.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function makeSymbolColBuffer.
 * Date: 5-27-15
 */

/*
 * C Std Lib Includes 
 */
#include <string.h>

/*
 * PA4 Includes
 */
#include "pa4.h"
#include "pa4_strings.h"
#include "test.h"

/*
 * Constants
 */
#define STR_TEST_OUTPUT "\n=== Test #%d ===\n"

static int testCount = 0;
static void
testmakeSymbolColBuffer() {
  int type, n = 6;
  char dest[n];

  /* #1. Test invalid type */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  type = -999;
  char zeroBlock[n];
  (void) memset( zeroBlock, '\0', n );
  makeSymbolColBuffer( dest, type, n );
  TEST( memcmp( dest, zeroBlock, n ) == 0 );

  /* #2. Test type ADD */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  type = TYPE_ADD;
  makeSymbolColBuffer( dest, type, n );
  TEST( strncmp( dest, STR_ADD, n ) == 0 );


  /* #3. Test type DELETE */
  (void) printf(STR_TEST_OUTPUT, testCount++);
  type = TYPE_DELETE;
  makeSymbolColBuffer( dest, type, n );
  TEST( strncmp( dest, STR_DELETE, n ) == 0 );

  /*
   * TODO
   * - Test other types (SAME, CHANGE)
   * - etc.
   */

}

int
main() {
  testmakeSymbolColBuffer();
  (void) printf("\n");
  return 0;
}
