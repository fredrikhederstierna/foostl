#include <string.h>
#include <stdbool.h>

#include <iostream>
#include <string>
#include <set>


using namespace std;

struct side {
  int d[4]; // [up right down left]
};

bool tinsert(struct side sx[6], int s0, int s1, int s2)
{
  struct side* s = &(sx[s0]);

  cout << "insert: [" << s0+1 << "]: (" << s1 << "," << s2 << ")\n";

  for (int i = 0; i < 4; i++) {

    int ni = (i+1)%4;
    int pi = (i+3)%4;

    // try place s1 or s2 if already set
    if (s->d[i] == s1) {
      // try put s2 on next
      // if space free. put it
      if (s->d[ni] == 0) {
        s->d[ni] = s2;
        return true;
      }
      else if (s->d[ni] == s2) {
        // if already put
        return true;
      }
      else {
        return false;
      }
    }
    else if (s->d[i] == s2) {
      // try put s1 on prev
      
      // if space free. put it
      if (s->d[pi] == 0) {
        s->d[pi] = s1;
        return true;
      }
      else if (s->d[pi] == s2) {
        // if already put
        return true;
      }
      else {
        return false;
      }
    }
  }

  // ok, s1,s2 not already set
  
  // set in first free slot
  for (int i = 0; i < 4; i++) {

    int ni = (i+1)%4;
    int pi = (i+3)%4;

    if (s->d[i] == 0) {
      if (s->d[ni] == 0) {
        // put
        s->d[i] = s1;
        s->d[ni] = s2;
        return true;
      }
      else if (s->d[pi] == 0) {
        // put
        s->d[pi] = s1;
        s->d[ni] = s2;
        return true;
      }
      else {
        return false;
      }
    }
  }
  
  cout << " !! Strange !!\n";

  return false;
}

int main() {


  string s[4];

  cout << "Tärning 1 ? ";
  cin >> s[0];

  cout << "Tärning 2 ? ";
  cin >> s[1];

  cout << "Tärning 3 ? ";
  cin >> s[2];

  cout << "Tärning 4 ? ";
  cin >> s[3];


  cout << "Tärningar:" << s[0] << ":" << s[1] << ":" << s[2] << ":" << s[3] << "\n";


  // try exclude each
  for (int e = 0; e < 4; e++) {

    bool ok = true;
    struct side sides[6];
    memset(sides, 0, sizeof(struct side)*6);

    cout << "\n New round\n";
    for (int t = 0; t < 4; t++) {

      // exclude one die
      if (t == e) {
        cout << "Exclude die: " << (t+1) << "\n";
        continue;
      }

      int i0 = s[t].at(0) - '1' + 1;
      int i1 = s[t].at(1) - '1' + 1;
      int i2 = s[t].at(2) - '1' + 1;

      cout << "INSERT : " << i0 << ":" << i1 << ":" << i2 << "\n";

      ok = tinsert(sides, i0-1, i1, i2);
      if (!ok)
        break;
      ok = tinsert(sides, i1-1, i2, i0);
      if (!ok)
        break;
      ok = tinsert(sides, i2-1, i0, i1);
      if (!ok)
        break;
    }
    
    if (ok) {
      cout << "Udda tärning: " << (e+1) << "\n";
      break;
    }
  }

  return 0;
}
