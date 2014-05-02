#include <stdio.h>
#include <limits.h>

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

int main()
{
  const long double X = sqrtl(5) + 3;
  int tc;
  int r = scanf("%d",&tc);
  (void)r;
  int tt = 1;
  while(tc) {
    int n = 0;
    int r = scanf("%d",&n);
    (void)r;

    long double res;

    if (n == 0) {
      res = 1;
    }
    else {
      int nn = n;
      res = X;
      nn--;
      while (nn > 0) {
        res *= X;
        nn--;
      }
    }

    long long p = ((long long)res) % 1000; 
    printf("(%d):Case #%d: %03lld\n", n, tt++, p);

    tc--;
  }

  return 0;
}


/*

 (a + b)2 = a2 + 2ab + b2
 (3 + sqrt(5))2 = 3_2 + 2*3*sq5 + 5 = 9+5+6sq5 = 14 + 6sq5

 10 up log10(3 + sq5)n  = 10 n log(3 + sq5) = (10 n) up log (3+sq5)
 = 10 n * (3 + sq5)

 n = 10 up log(n)

 10 up log(n up x) = 10 up x log(n)
 */
