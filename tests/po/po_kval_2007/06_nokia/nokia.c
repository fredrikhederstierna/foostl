#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>

#include "mytime.h"

using namespace std;

#define NOT_SOLVED (100)
#define MAX_MOVES  (11)
#define GOAL_BOARD (123456789)

static int history[MAX_MOVES];

static int best_moves;

// start, end (index), min_moves
#define MAX_TRANS (21)
static const int trans[MAX_TRANS][3] = {
  {0,8,4},
  {2,6,4},
  {8,0,4},
  {6,2,4},
  {0,7,3},
  {0,5,3},
  {1,6,3},
  {1,8,3},
  {2,3,3},
  {2,7,3},
  {3,2,3},
  {3,8,3},
  {5,0,3},
  {5,6,3},
  {6,5,3},
  {6,1,3},
  {7,0,3},
  {7,2,3},
  {8,1,3},
  {8,3,3}
};


static void board2v(int board, char vboard[9]) {
  int i;
  int tmp = board;
  for (i = 0; i < 9; i++) {
    vboard[i] = tmp % 10;
    tmp /= 10;
  }
}

static void v2board(char vboard[9], int* board) {
  int i;
  int tmp = vboard[8];
  for (i = 7; i >= 0; i--) {
    tmp *= 10;
    tmp += vboard[i];
  }
  *board = tmp;
}

static void solve(int board, int moves)
{
  //  cout << "[" << board << "]\n";

  // check if solved
  if (board == GOAL_BOARD) {
    if (moves < best_moves) {
      best_moves = moves;
      cout << "New high: " << best_moves << "\n";
    }
    return;
  }

  // max 11 moves
  if (moves == MAX_MOVES)
    return;

  // if we found better
  if (moves >= best_moves)
    return;

  // check history
  int i;
  for (i = 0; i < moves; i++) {
    // if board was eval previously
    if (history[ moves ] == board)
      return;
  }
  
#if 1
  char bb[9];
  board2v(board, bb);
  // check cost paths
  for (i = 0; i < MAX_TRANS; i++) {
    int start_ix = trans[i][0];
    int end_ix   = trans[i][1];
    if (bb[start_ix] == bb[end_ix]) {
      int min_cost = trans[i][2];
      // max 11 moves, if more required bail out
      if (moves + min_cost > MAX_MOVES)
        return;
      // if we found better
      if (moves + min_cost >= best_moves)
        return;      
    }
  }
#endif

  // put in history
  history[ moves ] = board;

  // rotate left and right, all different comb
  int x,y;
  for (y = 0; y < 2; y++) {
    for (x = 0; x < 2; x++) {

      char bcw[9];
      int tboard;
      char tmp;

      // rotate clockwise
      board2v(board, bcw);
      tmp = bcw[y*3 + x];
      bcw[y*3 + x] = bcw[(y+1)*3 + x];
      bcw[(y+1)*3 + x] = bcw[(y+1)*3 + x+1];
      bcw[(y+1)*3 + x+1] = bcw[y*3 + x+1];
      bcw[y*3 + x+1] = tmp;

      // convert
      v2board(bcw, &tboard);

      // recurse
      solve(tboard, moves + 1);
      
      //--------

      // rotate clockwise
      board2v(board, bcw);
      tmp = bcw[y*3 + x];
      bcw[y*3 + x] = bcw[y*3 + x+1];
      bcw[y*3 + x+1] = bcw[(y+1)*3 + x+1]; 
      bcw[(y+1)*3 + x+1] = bcw[(y+1)*3 + x];
      bcw[(y+1)*3 + x] = tmp;

      // convert
      v2board(bcw, &tboard);

      // recurse
      solve(tboard, moves + 1);
    }
  }

  return;
}

//-----------------
int main()
{
  int start_board = 0;

  cout << "Ställning ? ";
  cin >> start_board;

  e2_time_start();

  best_moves = NOT_SOLVED;

  solve(start_board, 0);

  e2_time_print_duration();

  cout << "Denna ställning kräver " << best_moves << " drag\n";

  cout.flush();

  return 0;
}
