#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>

#include "mytime.h"

using namespace std;

//-----------------
int main()
{
  int n;
  string s;

  cin >> n;
  cin >> s;

  //e2_time_start();


  
  int k = 0;
  int solved;
  do {

    k++;
    solved = 1;

    for (int i = 0; i < (int)s.length() - 1; i++) {
      if ((s[i] == 'H') && (s[i+1] == 'V')) {
        s[i] = 'V';
        s[i+1] = 'H';
        solved = 0;
      }
    }

  } while (! solved);

  //e2_time_print_duration();


  cout << k << "\n";
  cout.flush();

  return 0;
}
