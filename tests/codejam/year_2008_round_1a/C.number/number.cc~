#include <stdio.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#define MAX_COSTUMERS  (2000)
#define MAX_FLAVORS    (2000)

//#define DBG

using namespace std;

int main()
{
  int T; // tests
  cin >> T;
  int tc = 1;
  while (tc <= T) {
    int F; // flavors
    cin >> F;
    int C; // customers
    cin >> C;
    int c = 0;

    bitset<MAX_FLAVORS+1> U[C]; // unmalted
    bitset<MAX_FLAVORS+1> M[C]; // malted

    bitset<MAX_FLAVORS+1> Sol; // solution, all unmalted
    Sol.reset();

    bitset<MAX_COSTUMERS+1> Sat; // satisfied

    bitset<MAX_COSTUMERS+1> Flav;
    Flav.reset();
      
    // 0. Read all

    while (c < C) {
      int tin;
      cin >> tin;

#ifdef DBG
      printf("Customer %d:\n", c);
#endif

      U[c].reset();
      M[c].reset();

      int t = 0;
      while (t++ < tin) {

        int xin, yin;
        cin >> xin;
        cin >> yin;

#ifdef DBG
        printf("x,y=(f:%d m:%d) ", xin, yin);
#endif

        if (yin) {
          M[c][xin] = 1;
        }
        else {
          U[c][xin] = 1;
        }
        // mark flavor present
        Flav[xin] = 1;
      }

      c++;
   
#ifdef DBG   
      printf("\n");
#endif
    }

    // all customers read

    // 1. check satisfied

  calc_sat:

    Sat.reset();

    // all customers
    for (c = 0; c < C; c++) {

      int satisfied = 0;

      // all flavors
      int f;
      for (f = 1; f <= F; f++) {

        if (! Flav[f])
          continue;

        // if customer wants this flavor unmelted
        if ((U[c][f] == 1) && (Sol[f] == 0)) {
          Sat[c] = 1;
          satisfied = 1;
          break;
        }
        if ((M[c][f] == 1) && (Sol[f] == 1)) {
          Sat[c] = 1;
          satisfied = 1;
          break;
        }
      } //f

      if (satisfied) {
        //printf("c %d satisfied\n", c);
      }
      else {
#ifdef DBG
        // this customer was not satisfied
        printf("c %d not satisfied\n", c);
#endif
      }

    } // c


    // 2. scan for unsatisfied customers, try make flavors 'malted'.
 
    // all customers
    for (c = 0; c < C; c++) {
      // if not satisfied
      if (Sat[c] == 0) {
        // make malted.
        int f;
        for (f = 1; f <= F; f++) {

          if (! Flav[f])
            continue;

          // max one flavor malted, and only melted
          if ((M[c][f] == 1) && (U[c][f] == 0) && (Sol[f] == 0)) {
            // malt it, might require malting a previous satisfied customer
            Sol[f] = 1;
            //break;
            goto calc_sat;
          }
        }
      }
    }
   
    // 3. check if solution ok

    int impossible = 0;

    // all customers
    for (c = 0; c < C; c++) {

      int satisfied = 0;

      // all flavors
      int f;
      for (f = 1; f <= F; f++) {

        if (! Flav[f])
          continue;

        // if customer wants this flavor unmelted
        if ((U[c][f] == 1) && (Sol[f] == 0)) {
          satisfied = 1;
          break;
        }
        if ((M[c][f] == 1) && (Sol[f] == 1)) {
          satisfied = 1;
          break;
        }
      } //f

      if (! satisfied) {
        impossible = 1;
      }

    } // c

    printf("Case #%d: ", tc);

    if (! impossible) {
      int f;
      for (f = 1; f <= F; f++) {

        printf("%d", Sol[f] ? 1 : 0);
        if (f < F) {
          printf(" ");
        }
      }
      printf("\n");
    }
    else {
      printf("IMPOSSIBLE\n");
    }

    tc++;

#ifdef DBG
    printf("------------------\n");
#endif
  }
}
