#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "mytime.h"

using namespace std;

static vector<string> words(1000);
static vector<string>::iterator itr;
static int wcount = 0;

static void match(string s, int pos, vector<string> alfa, int letter, string result)
{
  // try match letter
  string test = alfa[letter];
  bool found = true;
  for (int i = 0; i < (int)test.size(); i++) {
    if (pos + i >= (int)s.length()) {
      found = false;
      break;
    }
    if (s[pos + i] != test[i]) {
      found = false;
      break;
    }
  }
  if (found) {
    
    int newpos = pos + (int)test.size();
    string newres = result + (char)('A' + letter);

    if (newpos == (int)s.length()) {
      //cout << "MATCH: " << newres << "\n";
      itr = words.begin();
      words.insert(itr, newres);
      wcount++;
    }
    else {
      for (int i = 0; i < 26; i++) {
        match(s, newpos, alfa, i, newres);
      }
    }
  }
}

//-----------------
int main()
{
  string s;

  vector<string> alfa(26);

  cin >> s;

  for (int i = 0; i < 26; i++) {
    cin >> alfa[i];
  }

  for (int i = 0; i < 26; i++) {
    match(s, 0, alfa, i, "");
  }

  for (int i = wcount - 1; i >= 0; i--) {
    cout << "\"" << words[i] << "\"" << "\n";
  }

  cout << " end\n";
  cout.flush();

  return 0;
}
