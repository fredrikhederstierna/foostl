#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const string T9[26] =
  { "2","22","222",
    "3","33","333",
    "4","44","444",
    "5","55","555",
    "6","66","666",
    "7","77","777","7777",
    "8","88","888",
    "9","99","999","9999"
  };

int main()
{
  int N;
  cin >> N;
  string s;
  getline(cin, s);
  int n;
  for (n = 0; n < N; n++) {

    getline(cin, s);

    cout << "Case #" << (n+1) << ": ";

    int i;
    int slen = (int)s.size();
    char last = '?';
    for (i = 0; i < slen; i++) {

      string t9;
      if (s[i] == ' ') {
        t9 = "0";
      }
      else {
        t9 = T9[s[i]-'a'];
      }

      if (t9[0] == last) {
        cout << " ";
      }

      cout << t9;

      last = t9[0];
    }

    cout << "\n";
  }
  cout << "\n";

  return 0;
}
