#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <iostream>
#include <string>
#include <set>

using namespace std;

//
//          |---|
//          | 0 |
//      -----------------
//     | 1  | 2 | 3 | 4 |
//     ------------------
//          | 5 |
//          -----
//
//
//
//             |---|
//             | 0 |
//     -----------------
//     | 2 | 3 | 4 | 1 |
//     -----------------
//             | 5 |
//             -----
//



// TEST
//         |---|
//         | 6 |
//     -----------------
//     | 1 | 4 | 1 | 5 |
//     -----------------
//         | 2 |
//         -----


static bool found_sol = false;
static const int cv[8][3] = {{1,0,2}, {1,2,5}, {2,3,5}, {0,3,2}, {0,4,3}, {1,4,0}, {5,3,4}, {1,5,4}};

//----------------
static void solve(int tv[3][3], int pos, int len, int sv[6])
{
  if (found_sol)
    return;

  // if all dice set
  if (pos == 3) {

    //cout << "try solution: " << sv[0] << "," << sv[1] << "," << sv[2] << "," << sv[3] << "," << sv[4] << "," << sv[5] << "\n";

    int dotuse[6+1] = {0,0,0,0,0,0,0};
    // check that all sides set
    for (int k = 0; k < 6; k++) {

#if 0
      // no all sides needs to be set!!
      if (sv[k] == 0) {
        // not ok sol
        return;
      }
#endif

#define UNIQUE_DOTS
#ifdef UNIQUE_DOTS
      // 
      assert(sv[k] < (int)sizeof(dotuse));
      if (dotuse[sv[k]] != 0) {
        // only use number dots once on die
        return;
      }
      dotuse[sv[k]] = 1;
#endif
    }
    //    cout << "FOUND SOLUTION: " << sv[0] << "," << sv[1] << "," << sv[2] << "," << sv[3] << "," << sv[4] << "," << sv[5] << "\n";
    found_sol = true;
    return;
  }

  // first check if its ok to place corner here
  int t0 = tv[pos][0];
  int t1 = tv[pos][1];
  int t2 = tv[pos][2];

  //  cout << "POS: " << pos << " (" << t0 << "," << t1 << "," << t2 <<  ")\n";        
          
  // for all corners
  for (int ci = 0; ci < 8; ci++)
    {
      int c1 = cv[ci][0];
      int c2 = cv[ci][1];
      int c3 = cv[ci][2];

      //      cout << "CORN: " << c1 << ";" << c2 << ";" << c3 << "\n";        
  
      // try all 3 rotations

      if (((sv[c1] == 0) || (sv[c1] == t0)) &&
          ((sv[c2] == 0) || (sv[c2] == t1)) &&
          ((sv[c3] == 0) || (sv[c3] == t2)))
        {
          int svx[6];
          memcpy(svx, sv, 6*sizeof(int));

          svx[c1] = t0;
          svx[c2] = t1;
          svx[c3] = t2;

          //      cout << "ROT1\n";

          solve(tv, pos+1, len, svx);
        }

      if (((sv[c1] == 0) || (sv[c1] == t2)) &&
          ((sv[c2] == 0) || (sv[c2] == t0)) &&
          ((sv[c3] == 0) || (sv[c3] == t1)))
        {
          int svx[6];
          memcpy(svx, sv, 6*sizeof(int));

          svx[c1] = t2;
          svx[c2] = t0;
          svx[c3] = t1;

          //          cout << "ROT2\n";

          solve(tv, pos+1, len, svx);
        }

      if (((sv[c1] == 0) || (sv[c1] == t1)) &&
          ((sv[c2] == 0) || (sv[c2] == t2)) &&
          ((sv[c3] == 0) || (sv[c3] == t0)))
        {
          int svx[6];
          memcpy(svx, sv, 6*sizeof(int));

          svx[c1] = t1;
          svx[c2] = t2;
          svx[c3] = t0;

          //          cout << "ROT3\n";

          solve(tv, pos+1, len, svx);
        }
    }
}


//-----------------
int main()
{
  string s[4];

  cout << "Tärning 1 ? ";
  cin >> s[0];

  cout << "Tärning 2 ? ";
  cin >> s[1];

  cout << "Tärning 3 ? ";
  cin >> s[2];

  cout << "Tärning 4 ? ";
  cin >> s[3];


  //  cout << "Tärningar:" << s[0] << ":" << s[1] << ":" << s[2] << ":" << s[3] << "\n";

  // try exclude each
  for (int e = 0; e < 4; e++) {

    //    cout << "\n*** New round\n";

    int tv[3][3];
    int ti = 0;
    for (int t = 0; t < 4; t++) {

      // exclude one die
      if (t == e) {
        //cout << "Exclude die: " << (t+1) << "\n";
        continue;
      }

      int i0 = s[t].at(0) - '1' + 1;
      int i1 = s[t].at(1) - '1' + 1;
      int i2 = s[t].at(2) - '1' + 1;

      tv[ti][0] = i0;
      tv[ti][1] = i1;
      tv[ti][2] = i2;

      //cout << "CORNER[" << ti << "] = {" << i0 << "," << i1 << "," << i2 << "}\n";

      ti++;
    }
    
    

    int sv[6] = {0,0,0,0,0,0};
    found_sol = false;
    solve(tv, 0, 3, sv);

    
    if (found_sol) {
      cout << "Udda tärning: " << (e+1) << "\n";
      break;
    }
  }

  cout.flush();

  return 0;
}
