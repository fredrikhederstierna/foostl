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
  int nkund, nkassa;

  cin >> nkund >> nkassa;

  vector<int> kund(nkund);
  vector<int> kassa(nkassa);

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
    vector<int>::iterator itr;
    vector<int>::iterator itrx;
    for (itr = kassa.begin(); (itr != kassa.end()); itr++) {
      if (*itr < mini) {
        mini = *itr;
        itrx = itr;
      }
    }
    // wait this time
    wait += mini;
    // decrease with this
    for (itr = kassa.begin(); (itr != kassa.end()); itr++) {
      *itr -= mini;
    }
    // enqueue new kund
    if (exped_kund < nkund) {
      *itrx = kund[exped_kund];
    }
    exped_kund++;
  }


  cout << wait << "\n";
  cout.flush();

  return 0;
}
