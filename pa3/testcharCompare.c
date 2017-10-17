#include "test.h"
#include <stdio.h>

testcharCompare() {
  char lhs = 'a';
  char rhs = 'a';
  TEST(charCompare(&lhs, &rhs) == 0);

  lhs = 'a';
  rhs = 'b';
  TEST(charCompare(&lhs, &rhs) == -1);
  TEST(charCompare(&rhs, &lhs) == 1);

  /* Check additional edge cases. */
  /*  - Is it a leaf subroutine?
   *  - If you are using a signed byte load (instead of an usigned byte)?
   *  - Etc.
   */
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_charCompare\n");

  testcharCompare();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
