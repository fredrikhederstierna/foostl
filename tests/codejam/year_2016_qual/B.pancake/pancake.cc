#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

//#define DBG

using namespace std;

static bool all_happy(char *s, int len)
{
  bool happy = true;
  int i;
  for (i = 0; i < len; i++) {
    if (s[i] != '+') {
      happy = false;
      break;
    }
  }
  return happy;
}


// CODE AS BITS.

static void flip(char *src, int len, int n, int depth, int max_depth, int *found_depth)
{
  //printf("[%d/%d] (%s) {%d:%d} max %d\n", depth, max_depth, src, n, len, *found_depth);
  
  if (*found_depth < depth) {
    //printf("TOO DEEP\n");
    return;
  }
  
  if (all_happy(src, len)) {
    if (*found_depth > depth) {
      //printf("HIGH:%d\n", depth);
      *found_depth = depth;
    }
    //printf("HAPPY\n");    
    return;
  }

  if (depth == max_depth) {
    //printf("MAXDEPTH\n");
    return;
  }

  //  char dst[11];
  char dst[101];
  int p = 0;

  // flip first
  int i;
  for (i = 0; i < n; i++) {
    //printf("Flip %c\n", src[n - i - 1]);
    if (src[n - i - 1] == '+') {
      //printf("Write -\n");
      dst[p++] = '-';
    }
    else {
      //printf("Write +\n");
      dst[p++] = '+';
    }
  }
  // copy rest
  for (i = n; i < len; i++) {
    //printf("Copy\n");
    dst[p++] = src[i];
  }
  
  dst[p++] = 0; //z-term
  //printf("dst (%s)\n", dst);

#if 0
  // last must be + to continue
  if (dst[len-1] != '+') {
    return;
  }
#endif
  
  // next depth
  int fc;
  for (fc = len; fc >= 0; fc--) {
    // skip flip of not same sign
    if ((fc < len) && (fc > 0) && (dst[0] == dst[fc])) {
      continue;
    }
    
    flip(dst, len, fc, depth+1, max_depth, found_depth);
  }
}

int main()
{
  int v;

  int tc;
  v = scanf("%d",&tc);

  int tt = 1;
  while(tc) {

    //    char S[11];
    char S[101];
    //    memset(S,0,11);
    memset(S,0,101);
    v = scanf("%s",S);

    int SLEN = strlen(S);
    
    //---------

    //printf("S=%s\n", S);

    int found = 0;
    
    int max_depth = SLEN + 1;
    int found_depth;

    do {

      found_depth = INT_MAX;
        
      int fc;
      for (fc = SLEN; fc >= 0; fc--) {        
        flip(S, SLEN, fc, 0, max_depth, &found_depth);
      }

      if (found_depth < INT_MAX) {
        //printf("FOUND! %d\n", found_depth);
        found = 1;
        break;
      }
#if 0
      else {        
        // try next depth
        max_depth++;
        printf("Try depth:%d\n", max_depth);
      }
#endif
      
    } while(found == 0);

    //----------

    if (found == 0) {
      printf("Case #%d: INSOMNIA\n", tt);
    }
    else {
      printf("Case #%d: %d\n", tt, found_depth);
    }
    
    tt++;
    tc--;
  }

  (void)v;
  return 0;
}
