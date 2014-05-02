#include <iostream>
#include <vector>

using namespace std;

struct child_s {
  char name;
  int left;
  int right;
};

int main() {

  int n;

  cout << "Antal barn ? ";
  cin >> n;

  vector<struct child_s> child(n);
  vector<struct child_s> result(n);

  for (int b = 0; b < n; b++) {

    char name = (char)('A'+b);
    child[b].name = name;

    cout << "Barn " << name << ", vänster ? ";
    cin >> child[b].left;

    cout << "Barn " << name << ", höger ? ";
    cin >> child[b].right;
  }

  for (int b = 0; b < n; b++) {
    int sum = 999999;
    int ix = 0;
    int tall_ix = 0;
    do {
      struct child_s *ch = &child[ix];
      if ((ch->left + ch->right) < sum) {
        sum = ch->left + ch->right;
        tall_ix = ix;
      }
      ix++;      
    } while (ix < (int)child.size());

    // insert tallest in new vector
    vector<struct child_s>::iterator it;
    it = result.begin();
    for (int p = 0; p < child[tall_ix].left; p++) { it++; }
    result.insert(it, child[tall_ix]);
    

    child.erase( child.begin() + tall_ix);
  }

  cout << "Uppställningen: ";
  for (int p = 0; p < n; p++) {
    cout << result[p].name << " ";
  }
  cout << "\n";

  return 0;
}
