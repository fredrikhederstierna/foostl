#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string s;
  getline(cin, s);
  int n;
  for (n = 0; n < N; n++) {

    stack<string> words;

    getline(cin, s);

    istringstream iss(s);

    do {
      string sub;
      iss >> sub;
      words.push(sub);
    } while (iss);

    words.pop();
    cout << "Case #" << (n+1) << ": ";

    int r;
    int siz = (int)words.size();
    for (r = 0; r < siz; r++) {
      cout << words.top() << " ";
      words.pop();
    }

    cout << "\n";
  }
  cout << "\n";

  return 0;
}
