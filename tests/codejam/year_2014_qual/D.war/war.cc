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

static int R;
static int C;
static int M;

static int imposs = 0;
static int pad_mines = 0;

static char F[51][51];

int main()
{
  int v;

  int tc;
  v = scanf("%d",&tc);

  int tt = 1;
  while(tc) {

    imposs = 0;
    pad_mines = 1;
    // mark all undefined
    memset(F, 'u', sizeof(F));

    v = scanf("%d %d %d",&R,&C,&M);

    DBG("%d %d %d\n",R,C,M);

    //----------

    // R = row
    // C = col
    // M = mines
    
    // Always place Click in (0,0)
    // Special case M = 0      --->  OK  all . and one C
    // Special case M = R*C-1  --->  OK  all * and one C
    // Otherwise, needs to put . around Click

    // Ex 2x2 3 mines
    // ..
    // **
    // Impossible

    // Idea, put C on (0,0), try fill .
    // C=1  (. below|right) - need one
    // C=2  (. below+right) - need two
    // C>2  (. b+r then fill) - need two

    //----------

    // number sq to place
    int n_sq = R*C;

    if (M == 0) {
      // no mines
      memset(F,'.',sizeof(F));
      F[0][0] = 'c';
      n_sq = 0;
      pad_mines = 0;
    }
    if (M == ((R*C)-1)) {
      // all mines
      memset(F,'*',sizeof(F));
      F[0][0] = 'c';
      n_sq = 0;
      pad_mines = 0;
    }
#if 0
    if ((M == ((R*C)-2)) && ((R > 1) || (C > 1))) {
      // all mines except 2
      memset(F,'*',sizeof(F));
      F[0][0] = 'c';
      if (R > 1) {
        F[1][0] = '.';
      }
      else if (C > 1) {
        F[0][1] = '.';
      }
      n_sq = 0;
      pad_mines = 0;
    }
    if ((M == ((R*C)-3)) && (R > 1) && (C > 1)) {
      // all mines except 3
      memset(F,'*',sizeof(F));
      F[0][0] = 'c';
      F[1][0] = '.';
      F[0][1] = '.';
      n_sq = 0;
      pad_mines = 0;
    }
#endif

    if (n_sq > 0) {
      // set click in corner
      F[0][0] = '.';
      n_sq--;

      // sub mines (fill last)
      n_sq -= M;

      // try pad . down and right
      if (R > 1) {
        F[1][0] = '.';        
        n_sq--;
      }
      if (C > 1) {
        F[0][1] = '.';        
        n_sq--;
      }

      // also need to set . at 1,1 if larger than 1
      if ((R > 1) && (C > 1)) {
        F[1][1] = '.';
        n_sq--;
      }

      // check sq left
      if (n_sq < 0) {
        imposs = 1;
      }
    }

    int r,c;
      
    // otherwise needs to place .
    while (n_sq > 0) {

      // continue prune .   first try prune one sq

      int best_xus = 99;
      int best_r   = 0;
      int best_c   = 0;
      for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
          
          // can we prune this? 
          if (F[r][c] == '.') {
            // ok, we can try
            
            int nbr_xus = 0;
            
            // check up left
            if ((r > 0) && (c > 0)) {
              if (F[r-1][c-1] == 'u') {
                nbr_xus++;
              }
            }
            // check up
            if (r > 0) {
              if (F[r-1][c] == 'u') {
                nbr_xus++;
              }
            }
            // check up right
            if ((r > 0) && (c < C-1)) {
              if (F[r-1][c+1] == 'u') {
                nbr_xus++;
              }
            }
            // check left
            if (c > 0) {
              if (F[r][c-1] == 'u') {
                nbr_xus++;
              }
            }
            // check right
            if (c < C-1) {
              if (F[r][c+1] == 'u') {
                nbr_xus++;
              }
            }
            // check down left
            if (c > 0 && r < R-1) {
              if (F[r+1][c-1] == 'u') {
                nbr_xus++;
              }
            }
            // check down
            if (r < R-1) {
              if (F[r+1][c] == 'u') {
                nbr_xus++;
              }
            }
            // check down right
            if (c < C-1 && r < R-1) {
              if (F[r+1][c+1] == 'u') {
                nbr_xus++;
              }
            }

            // always prefer full prune
            if (nbr_xus == n_sq) {
              // perfect
              best_xus = nbr_xus;
              best_c = c;
              best_r = r;
              goto done;
            }

            if ((nbr_xus > 0) && (nbr_xus < best_xus)) {
              best_xus = nbr_xus;
              best_c = c;
              best_r = r;
            }
          } // if .
        } // for c
      } // for r

    done:
      DBG("BEST=%d r %d c %d\n", best_xus, best_r, best_c);
      
      // prune
      r = best_r;
      c = best_c;
      
      // check up left
      if ((r > 0) && (c > 0)) {
        if (F[r-1][c-1] == 'u') {
          F[r-1][c-1] = '.';
          n_sq--;
        }
      }
      // check up
      if (r > 0) {
        if (F[r-1][c] == 'u') {
          F[r-1][c] = '.';
          n_sq--;
        }
      }
      // check up right
      if ((r > 0) && (c < C-1)) {
        if (F[r-1][c+1] == 'u') {
          F[r-1][c+1] = '.';
          n_sq--;
        }
      }
      // check left
      if (c > 0) {
        if (F[r][c-1] == 'u') {
          F[r][c-1] = '.';
          n_sq--;
        }
      }
      // check right
      if (c < C-1) {
        if (F[r][c+1] == 'u') {
          F[r][c+1] = '.';
          n_sq--;
        }
      }
      // check down left
      if (c > 0 && r < R-1) {
        if (F[r+1][c-1] == 'u') {
          F[r+1][c-1] = '.';
          n_sq--;
        }
      }
      // check down
      if (r < R-1) {
        if (F[r+1][c] == 'u') {
          F[r+1][c] = '.';
          n_sq--;
        }
      }
      // check down right
      if (c < C-1 && r < R-1) {
        if (F[r+1][c+1] == 'u') {
          F[r+1][c+1] = '.';
          n_sq--;
        }
      }
      
      // if prune too many
      if (n_sq < 0) {
        DBG("Pruned too many\n");
        imposs = 1;
      }
    }
    
      
    // if all done
    if ((! imposs) && pad_mines && (n_sq == 0)) {
      // pad with *
      int mines = 0;
      for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
          if (F[r][c] == 'u') {
            F[r][c] = '*';
            mines++;
          }
        }
      }
      if (mines != M) {
        DBG("mines %d M %d\n", mines, M);
        imposs = 1;
      }
    }
  
    
    if (imposs) {
      printf("Case #%d:\nImpossible\n", tt);
    }
    else {

      // remark click in corner
      F[0][0] = 'c';

      int r,c;
      printf("Case #%d:\n", tt);
      for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
          printf("%c",F[r][c]);
        }
        printf("\n");
      }
    }

    tt++;
    tc--;
  }

  (void)v;
  return 0;
}
