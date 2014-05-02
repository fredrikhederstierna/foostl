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
  int nkund, nkassa;

  cin >> nkund >> nkassa;

  int kund[nkund];
  int kassa[nkassa];

  int i;
  for (i = 0; i < nkund; i++) {
    cin >> kund[i];
  }

  int exped_kund;
  // initial fill
  for (exped_kund = 0; exped_kund < nkassa; exped_kund++) {
    if (exped_kund == nkund) {
      exped_kund++;
      break;
    }
    kassa[exped_kund] = kund[exped_kund];
  }

  int wait = 0;

  //e2_time_start();
  //e2_time_print_duration();

  while (exped_kund <= nkund) {
    
    // find least customer
    int mini = 9999;
    int mi = 0;
    for (i = 0; i < nkassa; i++) {
      if (kassa[i] < mini) {
        mini = kassa[i];
        mi = i;
      }
    }
    // wait this time
    wait += mini;
    // decrease with this
    for (i = 0; i < nkassa; i++) {
      kassa[i] -= mini;
    }
    // enqueue new kund
    if (exped_kund < nkund) {
      kassa[mi] = kund[exped_kund];
    }
    exped_kund++;
  }


  cout << wait << "\n";
  cout.flush();

  return 0;
}
