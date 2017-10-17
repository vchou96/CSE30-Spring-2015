/*
 * Expands tabs into a buffer. 
 * Author: Casey Graff <cagraff@ucsd.edu>
 * Date: 5-15-15
 */

/*
 * Includes
 */
#include <string.h>

#include "pa4.h"

/*
 * Parameters:
 *  s1: dest buffer 
 *  s2: src buffer
 *  n:  max chars to copy to dest buffer
 */
void
expandTabs(char* s1, const char* s2, int n) {
  int i, j, numSpaces, colPos = 0;
  char srcChar;
  
  // Iterate over each char in s2 until n or null
  for(i = 0;;i++) {
    srcChar = s2[i]; 
    
    // stoping conditions
    if( (colPos >= (n -1)) || (srcChar == '\0')) {
      break;
    }

    // expand tab
    if(srcChar == '\t') {
      numSpaces = TAB_WIDTH - (colPos % TAB_WIDTH);
      for(j = 0; j < numSpaces; j++) {
        s1[colPos++] = ' ';
        // stoping conditions
        if( colPos >= (n -1) ) {
          goto end;
        }
      }
    }
    else {
      s1[colPos++] = srcChar;
    }
  }

end:
  s1[colPos] = '\0';
}
