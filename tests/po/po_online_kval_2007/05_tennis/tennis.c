#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "mytime.h"

using namespace std;

//-----------------
int main()
{
  int n;
  int k;
  int m;

  cin >> n;  // antal spelare
  cin >> k;  // rank vi vill kolla
  cin >> m;  // rader

  vector<int> win(m);
  vector<int> lost(m);
  for (int i = 0; i < m; i++) {
    cin >> win[i];
    cin >> lost[i];
  }

  cout << " end\n";
  cout.flush();

  return 0;
}
