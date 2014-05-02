#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n = 0;
  cout << "Antal travar ? ";
  cin >> n;

  int vt[102][16];
  memset(vt,0,102*16);

  for (int i = 1; i <= n; i++) {
    int t;
    cout << "Böcker i trave " << i << " ? ";
    cin >> t;
    vt[1][i] = t;
  }

  for (int d = 1; d < 100; d++) {   
    int hi2 = 1;
    int hi;
    for (hi = 1; hi <= 15; hi++) {
      int nh = vt[d][hi];
      if (nh == 0)
        break;
      else if (nh > 1) {
        vt[d+1][hi2++] = nh - 1;
      }
    }
    vt[d+1][hi2++] = hi - 1;

#if 1
    cout << "Dag " << (d+1) << ": ";
    for (int k = 0; k < hi2; k++) {
      cout << vt[d+1][k] << ",";
    }
    cout << "\n";
#endif

    for (int d2 = 1; d2 <= (d - 1); d2++) {
      int h = 1;
      while (vt[d][h] == vt[d2][h]) {
        h++;
        if ((vt[d][h] == 0) && (vt[d2][h] == 0)) {
          cout << "Dag " << d2 << " uppkom ett upplägg, som redan förekommit dag " << d << "\n";
          return 0;
        }
        else if ((vt[d][h] == 0) || (vt[d2][h] == 0)) {
          break;
        }
      }      
    }

  }

  return 0;
}
