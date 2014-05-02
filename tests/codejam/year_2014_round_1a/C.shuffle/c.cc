#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

#define DBG(a,...)
//#define DBG printf

using namespace std;

int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  int ti = 1;
  while(tn) {

    int X;

    v = scanf("%d",&X);

    DBG("%d\n",X);

    
    if (0) {
      printf("Case #%d:\nImpossible\n", ti);
    }
    else {
      printf("Case #%d:\n", ti);
      printf("\n");
    }

    ti++;
    tn--;
  }

  return 0;
}
