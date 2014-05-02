#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int min1(int a){return a-1;}
bool is0(int a){return a==0;}

int main()
{
  int N;
  cin >> N;

  int n;
  for (n = 0; n < N; n++) {

    int C;
    cin >> C;
    int I;
    cin >> I;

    vector<int> L(I);

    int i;
    for (i = 0; i < I; i++) {
      int P;
      cin >> P;
      L[i] = P;
    }

    int k;
    for (k = 0; k < I; k++) {
      int p;
      for (p = k + 1; p < I; p++) {
        if (L[k] + L[p] == C) {
          cout << "Case #" << (n+1) << ": " << (k+1) << " " << (p+1) << "\n";
          p = k = I;
          break;
        }
      }
    }
  }

  return 0;

  vector<vector<int> > books;
  cout << "Antal travar ? ";
  int sz;
  cin >> sz;
  vector<int> cur(sz);
  for (int i = 0; i < sz; i++) {
    cout << "Böcker i trace " << i+1 << " ? ";
    cin >> cur[i];
  }
  cur.erase(remove_if(cur.begin(),cur.end(),is0),cur.end());
  books.push_back(cur);
  while(1) {
    transform(cur.begin(),cur.end(),cur.begin(),min1);
    cur.push_back(cur.size());
    cur.erase(remove_if(cur.begin(),cur.end(),is0),cur.end());
    vector<vector<int> >::iterator iter = find(books.begin(),books.end(),cur);
    if (iter != books.end()) {
      cout << "Dag " << books.size()+1 << " uppkom ett upplägg, som redan förekommit dag " << distance(books.begin(),iter)+1 << "\n";
      return 0;
    }
    books.push_back(cur);
  }
}
