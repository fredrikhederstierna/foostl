#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

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

char seen[10];
int seen_total;

void update(uint64_t x)
{
  while (x) {
    int d = x % 10;
    if (seen[d] == 0) {
      seen_total++;
    }
    seen[d] = 1;
    x /= 10;
  }
}

int main()
{
  int v;

  int tc;
  v = scanf("%d",&tc);

  int tt = 1;
  while(tc) {

    int N = 0;
    v = scanf("%d",&N);

    //---------

    //printf("N=%d\n", N);
    
    int found = 0;
    uint64_t sol = -1;

    memset(seen, 0, 10);
    seen_total = 0;
    
    if (N > 0) {
        
      uint64_t M = 1;
      do {
        
        uint64_t R = N*M;

        //printf("R=%llu %d\n", (unsigned long long)R, seen_total);
        
        update(R);
        if (seen_total == 10) {
          sol = M*N;
          found = 1;
          break;
        }
        
        M++;

      } while (1);
    }
    
    //----------

    if (found == 0) {
      printf("Case #%d: INSOMNIA\n", tt);
    }
    else {
      printf("Case #%d: %llu\n", tt, (unsigned long long)sol);
    }

    tt++;
    tc--;
  }

  (void)v;
  return 0;
}
