#include <iostream>
#include <string>
#include <set>


using namespace std;

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


  //  cout << "Tärningar:" << s[0] << ":" << s[1] << ":" << s[2] << ":" << s[3] << "\n";


  for (int t = 0; t < 4; t++) {

    set<int> sets[6+1];

    //cout << "setsize: " << sets[0].size() << "\n";

    for (int e = 0; e < 4; e++) {

      // exclude one die
      if (t == e) {
        //cout << "Skip : " << e << "\n";
        continue;
      }

      int i0 = s[e].at(0) - '1' + 1;
      int i1 = s[e].at(1) - '1' + 1;
      int i2 = s[e].at(2) - '1' + 1;

      sets[i0].insert(10*i1 + i2);
      sets[i1].insert(10*i2 + i0);
      sets[i2].insert(10*i0 + i1);

      //cout << "INSERT : " << i0 << ":" << i1 << ":" << i2 << "\n";
    }

    int k;
    for (k = 1; k <= 6; k++) {
      
      int f[7] = {0,0,0,0,0,0,0};
      int p[7] = {0,0,0,0,0,0,0};
   
      //cout << "---dump:" << k << " ------\n";

      set<int>::iterator it = sets[k].begin();
      while (it != sets[k].end()) {

        int prim = (*it / 10);
        int follow = (*it % 10);

        //        cout << "Nbr[" << *it << ":" << k << "] " << follow << " follow " << prim << "\n";

        if ((f[prim] != 0) &&
            (f[prim] != follow)) {
          // not feasible
          goto not_feasible;
        }

        if ((p[follow] != 0) &&
            (p[follow] != prim)) {
          // not feasible
          goto not_feasible;
        }

        // set predecessor
        p[follow] = prim;
        // set follower
        f[prim] = follow;

        //cout << *it << "\n";

        it++;
      }

      // count number of nodes around
      int n = 0;
      for (int z = 0; z < 7; z++) {
        if (f[z] || p[z])
          n++;        
      }

      if (n > 4) {
        // not feasible
        goto not_feasible;
      }

      //cout << "------end---\n";

    }

    cout << "Udda tärning: " << (t+1) << "\n";
    //return 0;

  not_feasible:
    
    //    cout << "New try...\n";
    ;

  }

  return 0;
}
