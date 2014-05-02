#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define SAVE_P1_V1()     do { saved_p1a = v1[p1a]; saved_p1b = v1[p1b]; } while(0)
#define RESTORE_P1_V1()  do { v1[p1a] = saved_p1a; v1[p1b] = saved_p1b; } while(0)
#define SAVE_P2_V1()     do { saved_p2a = v1[p2a]; saved_p2b = v1[p2b]; } while(0)
#define RESTORE_P2_V1()  do { v1[p2a] = saved_p2a; v1[p2b] = saved_p2b; } while(0)

#define SAVE_P1_V2()     do { saved_p1a = v2[p1a]; saved_p1b = v2[p1b]; } while(0)
#define RESTORE_P1_V2()  do { v2[p1a] = saved_p1a; v2[p1b] = saved_p1b; } while(0)
#define SAVE_P2_V2()     do { saved_p2a = v2[p2a]; saved_p2b = v2[p2b]; } while(0)
#define RESTORE_P2_V2()  do { v2[p2a] = saved_p2a; v2[p2b] = saved_p2b; } while(0)

#define SWAP(x1,x2) do { int temp = (x1); (x1) = (x2); (x2) = temp;  } while(0)

void print(int i) {
  cout << i << ",";
}

int prodsum(vector<int> v1, vector<int> v2) {
  int sum = 0;
  int len = v1.size();
  int i;
  for (i = 0; i < len; i++) {
    sum += v1[i] * v2[i];
  }
  return sum;
}

int main()
{
  int T;
  cin >> T;
  string s;
  getline(cin, s);

  //T = 1; // test
  
  //cout << "T=" << T << endl;

  int t;
  for (t = 0; t < T; t++) {

    int n;
    cin >> n;

    //cout << "n=" << n << endl;

    vector<int> v1;

    int ni;
    for (ni = 0; ni < n; ni++) {
      int v;
      cin >> v;
      v1.push_back(v);
    }

    vector<int> v2;

    for (ni = 0; ni < n; ni++) {
      int v;
      cin >> v;
      v2.push_back(v);
    }

    //for_each (v1.begin(), v1.end(), print);
    //cout << endl;
    //for_each (v2.begin(), v2.end(), print);
    //cout << endl;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    //reverse(v2.begin(), v2.end());

#if 0
    vector<int>::iterator v1first = v1.begin();
    vector<int>::iterator v1last  = v1.end();
    vector<int>::iterator v2first = v2.begin();
    vector<int>::iterator v2last  = v2.end();
#endif

    long long int Y = LLONG_MAX;


#if 0
    // CORRECT SMALL;

    //FF do {

    //vector<int> v3(n);
    // copy ( v1.begin(), v1.end(), v3.begin() );    
      //for_each (v3.begin(), v3.end(), print);
      //cout << endl;

      do {
        long long int sprod = 0;
        int i;
        for (i = 0; i < n; i++) {
          sprod += v1[i] * v2[i];
          //cout << v1[i] << " * " << v2[i] << " (" << sprod << ")" << endl;
          //if (sprod >= min_value) // can add negative value!
          //  break;
        }
        if (sprod < Y) {
          // store highscore
          Y = sprod;
          //cout << "Y update: " << Y << endl;
        }

        //cout << "--\n";

      } while (next_permutation(v1.begin(),v1.end()));

      //cout << "===\n";

      //FF } while (next_permutation(v2first,v2last));
#endif


        long long int sprod = 0;
        int i;
        for (i = 0; i < n; i++) {
          sprod += (long long)v1[i] * (long long)v2[n - i - 1];
          //cout << v1[i] << " * " << v2[i] << " (" << sprod << ")" << endl;
          //if (sprod >= min_value) // can add negative value!
          //  break;
        }
        //cout << sprod << endl;
        if (sprod < Y) {
          // store highscore
          Y = sprod;
          //cout << "Y update: " << Y << endl;
        }
       

#if 0
    int eval;
    int saved_p1a;
    int saved_p1b;
    int saved_p2a;
    int saved_p2b;
    int p1a;
    int p1b;
    int p2a;
    int p2b;
    int pp; // v1 v1, v1 v2, v2 v1, v2 v2
    for (p1a = 0; p1a < n; p1a++) {
      for (p1b = p1a + 1; p1b < n; p1b++) {
        for (p2a = 0; p2a < n; p2a++) {
          for (p2b = p2a + 1; p2b < n; p2b++) {
            for (pp = 0; pp < 4; pp++) {
              switch (pp) {
              case 0: // v1v1
                SAVE_P1_V1();
                SAVE_P2_V1();
                SWAP(v1[p1a], v1[p1b]);
                SWAP(v1[p2a], v1[p2b]);
                eval = prodsum(v1,v2);
                if (eval < Y) {
                  Y = eval;
                }
                RESTORE_P1_V1();
                RESTORE_P2_V1();
                break;
              case 1: // v1v2
                SAVE_P1_V1();
                SAVE_P2_V2();
                SWAP(v1[p1a], v1[p1b]);
                SWAP(v2[p2a], v2[p2b]);
                eval = prodsum(v1,v2);
                if (eval < Y) {
                  Y = eval;
                }
                RESTORE_P1_V1();
                RESTORE_P2_V2();
                break;
              case 2: // v2v1
                SAVE_P1_V2();
                SAVE_P2_V1();
                SWAP(v2[p1a], v2[p1b]);
                SWAP(v1[p2a], v1[p2b]);
                eval = prodsum(v1,v2);
                if (eval < Y) {
                  Y = eval;
                }
                RESTORE_P1_V2();
                RESTORE_P2_V1();
            break;
              case 3: // v2v2
                SAVE_P1_V2();
                SAVE_P2_V2();
                SWAP(v2[p1a], v2[p1b]);
                SWAP(v2[p2a], v2[p2b]);
                eval = prodsum(v1,v2);
                if (eval < Y) {
                  Y = eval;
                }
                RESTORE_P1_V2();
                RESTORE_P2_V2();
                break;
              }
            }
          }
        }
      }
    }
#endif

    cout << "Case #" << (t+1) << ": " << Y << endl;
  }
  cout << "\n";

  return 0;
}
