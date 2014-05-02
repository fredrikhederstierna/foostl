#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int min1(int a){return a-1;}
bool is0(int a){return a==0;}

int main()
{
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
