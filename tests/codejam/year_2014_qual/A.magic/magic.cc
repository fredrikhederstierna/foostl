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

static char card1[4][4]; // row,col
static char card2[4][4]; // row,col

int main()
{
  int v;
  int r,c;

  int tc;
  v = scanf("%d",&tc);

  int tt = 1;
  while(tc) {

    int a1 = 0;
    v = scanf("%d",&a1);
    a1--;

    for (r = 0; r < 4; r++) {
      for (c = 0; c < 4; c++) {
        int p;
        v = scanf("%d",&p);
        card1[r][c] = p;
        //printf("%d ", p);
      }
      //printf("\n");
    }

    //---------

    int a2 = 0;
    v = scanf("%d",&a2);
    a2--;

    for (r = 0; r < 4; r++) {
      for (c = 0; c < 4; c++) {
        int p;
        v = scanf("%d",&p);
        card2[r][c] = p;
        //printf("%d ", p);
      }
      //printf("\n");
    }

    //----------

    //printf("\n");
    
    int c1,c2;
    int found = 0;
    int sol = -1;

    for (c1 = 0; c1 < 4; c1++) {
      for (c2 = 0; c2 < 4; c2++) {
        if (card1[a1][c1] == card2[a2][c2]) {
          sol = card1[a1][c1];
          found++;
        }
      }
    }
    
    //----------

    if (found == 0) {
      printf("Case #%d: Volunteer cheated!\n", tt);
    }
    else if (found == 1) {
      printf("Case #%d: %d\n", tt, sol);
    }
    else {
      // found > 1
      printf("Case #%d: Bad magician!\n", tt);
    }

    tt++;
    tc--;
  }

  (void)v;
  return 0;
}
