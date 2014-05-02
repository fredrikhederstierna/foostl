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

#include <stdint.h>

#include <math.h>

#define DBG(a,...)
//#define DBG printf

using namespace std;

static unsigned long long OUT[200];
static unsigned long long DEV[200];
static bool TAKEN[200];
static int SETUP[200];

static int best_sw;

static unsigned long long x = 0;

static int N;
static int L;

static int get_hamming(unsigned long long x, int L)
{
  int bits = 0;
  int i;
  for (i = 0; i < L; i++) {
    if (x & (1ULL << (L - i - 1))) {
      bits++;
    }
  }
  return bits;
}

static bool next_outlet(int oi)
{
  int di;

  if (oi == N) {
    // all outlets taken, found possible solution
    for (di = 0; di < N; di++) {
      DBG("TAKEN[%d] %d SETUP %d\n", di, TAKEN[di], SETUP[di]);
    }
    DBG("Found solution\n");
    return true;
  }


  for (di = 0; di < N; di++) {

    DBG("Check(di %d) : taken %d\n", di, TAKEN[di]);
    
    if (TAKEN[di]) {
      continue;
    }

    unsigned long long x2 = DEV[ di ] ^ OUT[ oi ];

    // try setup device Di in Outlet
    if ( x == x2 ) {

      DBG("Compare[%d/%d] %llx == %llx\n", oi, N-1, x, x2);

      TAKEN[ di ] = true;
      SETUP[ oi ] = di;
      bool possible = next_outlet(oi + 1);
      TAKEN[ di ] = false;
      if (possible) {
        return true;
      }
    }
  }

  return false;
}

int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  bool imp = true;

  int ti = 1;
  while(tn) {

    v = scanf("%d %d",&N,&L);

    DBG("N %d L %d\n",N,L);

    // inital flow
    int n;
    DBG("OUT\n");
    for (n = 0; n < N; n++) {
      char s[100];
      v = scanf("%s",s);
      OUT[n] = 0;
      int i;
      for (i = 0; i < L; i++) {
        OUT[n] |= (s[i] == '1') ? (1ULL << (L-i-1)) : 0;
      }
      DBG("(%d:%s,0x%llx,#%lli)\n",n,s,OUT[n],OUT[n]);
    }

    // required devices
    DBG("DEV\n");
    for (n = 0; n < N; n++) {
      char s[100];
      v = scanf("%s",s);
      DEV[n] = 0;
      int i;
      for (i = 0; i < L; i++) {
        DEV[n] |= (s[i] == '1') ? (1ULL << (L-i-1)) : 0;
      }
      DBG("(%d:%s,0x%llx,#%lli)\n",n,s,DEV[n],DEV[n]);
    }
    DBG("\n");
      
    imp = true;
    best_sw = 9999;

    int oi = 0;
    int di;
    for (di = 0; di < N; di++) {

      DBG("Try place DEV %d (%lli) at OUT %d (%lli)\n", di, DEV[di], oi, OUT[oi]);

      // try setup device Di in Outlet 0     
      x = DEV[ di ] ^ OUT[ oi ];

      int sw = get_hamming(x, L);
      if (sw >= best_sw) {
        // already found better solution
        continue;
      }

      // try plug in all other devices

      TAKEN[di] = true;
      SETUP[oi] = di;
      bool possible = next_outlet(oi + 1);
      TAKEN[di] = false;

      if (possible) {

        // how many bits needed to flip?

        DBG("Calc hamming of %016llx - %d best %d\n", x, sw, best_sw);

        if (sw < best_sw) {
          best_sw = sw;
          imp = false;
        }
      }
    }





    if (imp) {
      printf("Case #%d: NOT POSSIBLE\n", ti);
    }
    else {
      printf("Case #%d: %d\n", ti, best_sw);
    }

    ti++;
    tn--;
  }

  return 0;
}
