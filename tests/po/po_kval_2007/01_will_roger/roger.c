#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
  int na;
  long long sa = 0;
  cout << "Antal tal i grupp A? ";
  cin >> na;
  vector<int> va(na);
  for(int i = 0; i < (int)va.size(); i++) {
    cout << "Tal ? ";
    cin >> va[i];
    sa += va[i];
  }

  int nb;
  long long sb = 0;
  cout << "Antal tal i grupp B? ";
  cin >> nb;
  vector<int> vb(nb);
  for(int i = 0; i < (int)vb.size(); i++) {
    cout << "Tal ? ";
    cin >> vb[i];
    sb += vb[i];
  }

  for(int i = 0; i < (int)va.size(); i++) {
    if ((nb*va[i] > sb) && (na*va[i] < sa)) {
      cout << "Flytta talet " << va[i] << " till B.\n";
      return 0;
    }
  }

  for(int i = 0; i < (int)vb.size(); i++) {
    if ((na*vb[i] > sa) && (nb*vb[i] < sb)) {
      cout << "Flytta talet " << vb[i] << " till A.\n";
      return 0;
    }
  }

  cout << "Omöjligt!\n";

  return 0;
}
