#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

//#define DBG(a,...)
#define DBG printf

using namespace std;


struct Node;
struct Node {
  bool valid;
  bool deleted;
  int parents;
  int childs;
};

struct Node G[1000+1];


int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  int ti = 1;
  while(tn) {

    int N;

    v = scanf("%d",&N);

    DBG("N %d\n",N);

    memset(G,0,sizeof(G));

    int XV[N+1];
    int YV[N+1];

    int n;
    for (n = 0; n < N-1; n++) {

      int X,Y;
      v = scanf("%d %d",&X,&Y);
      DBG("X %d Y %d\n",X,Y);

      XV[n] = X;
      YV[n] = Y;

      G[X].valid = true;
      G[X].childA = 
    }


    // first all nodes with one child must be remved...
    for (n = 1; n <= N; n++) {
      // count childs
      for (
    }

    if (0) {
      printf("Case #%d:\nImpossible\n", ti);
    }
    else {
      printf("Case #%d:\n", ti);
      printf("\n");
    }

    ti++;
    tn--;
  }

  return 0;
}
