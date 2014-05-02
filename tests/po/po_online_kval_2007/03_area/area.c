#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "mytime.h"

using namespace std;

#define HEIGHT 51
#define WIDTH  51
#define DEPTH  51

//-----------------
int main()
{
  int nx, ny;

  cin >> ny >> nx;

  vector<vector<vector<unsigned char> > > blocks;

  // Set up sizes. (HEIGHT x WIDTH)
  blocks.resize(HEIGHT);
  for (int i = 0; i < HEIGHT; ++i) {
    blocks[i].resize(WIDTH);
    for (int j = 0; j < WIDTH; ++j) {
      blocks[i][j].resize(DEPTH);
      for (int k = 0; k < DEPTH; ++k) {
        blocks[i][j][k] = 0;
      }
    }
  }

  int x,y,h;
  for (y = 0; y < ny; y++) {
    for (x = 0; x < nx; x++) {
      int nh;
      cin >> nh;
      for (h = 0; h < nh; h++) {
        blocks[y][x][h] = 1;
      }
    }
  }

  int b = 0;

  for (y = 0; y < HEIGHT - 1; y++) {
    for (x = 0; x < WIDTH - 1; x++) {
      for (h = 0; h < DEPTH - 1; h++) {
        if (blocks[y][x][h] == 1) {
          if (y == 0) {
            b++;
          }
          else if (blocks[y - 1][x][h] == 0) {
            b++;
          }

          if (x == 0) {
            b++;
          }
          else if (blocks[y][x - 1][h] == 0) {
            b++;
          }

          if (h == 0) {
            b++;
          }
          else if (blocks[y][x][h - 1] == 0) {
            b++;
          }

          if (blocks[y + 1][x][h] == 0) {
            b++;
          }
          if (blocks[y][x + 1][h] == 0) {
            b++;
          }
          if (blocks[y][x][h + 1] == 0) {
            b++;
          }
        }
      }
    }
  }

  cout << b << " end\n";
  cout.flush();

  return 0;
}
