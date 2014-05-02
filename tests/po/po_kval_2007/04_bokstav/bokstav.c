#include <iostream>
#include <string>

using namespace std;

int main() {

  string s;
  int n;

  cout << "Sekvens ? ";
  cin >> s;

  cout << "Antal omflyttningar ? ";
  cin >> n;

  for (int i = 0; i < (int)s.length() - 1; i++) {
    int high = 0;
    int hpos = 0;
    for (int j = i; j < (int)s.length(); j++) {
      if ((s[i] > s[j]) && ((j - i) <= n) && ((s[i] - s[j]) > high)) {
        hpos = j;
        high = s[i] - s[j];
      }
    }
    if (hpos > 0) {
      char tmp = s[hpos];
      for (int k = hpos; k >= i; k--) {
        s[k] = s[k - 1];
      }
      s[i] = tmp;

      //cout << "Ny sekvens: " << s << "\n";

      n -= (hpos - i);
      if (n == 0)
        break;
    }
  }


  cout << "Bästa sekvens: " << s << "\n";

  return 1;
}
