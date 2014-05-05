
#include <foostl.h>

//#define DBG(a,...)
#define DBG printf

// max 101 nodes
graph G(101);

vi visited(101);

// for every node, test if root, recurse and report deleted.
int getDel(int parent, int node, vector<ii> edges)
{
  int size = edges.size();

  if (size <= 1) {  // one parent back
    // nothing to delete
    DBG("LEAF(%d)\n", node);
    return 0;
  }

  vector<int> costs(size);
  costs.clear();
  int k;
  for (k = 0; k < (int)edges.size(); k++) {
    pair<int,int> p = edges[k];
    int child = p.first;
    if (child == parent) {
      // dont go back
      costs[k] = INF;
      continue;
    }
    if (visited[child] == 1) {
      costs[k] = INF;
      continue;
    }

    DBG("TRY(%d --> %d --> %d)\n", parent, node, child);

    vector<ii> c2 = G[child];
    visited[child] = 1;
    int cost = getDel(node, child, c2);
    visited[child] = 0;

    costs[k] = cost;
  }

  if (size == 1+1) { // one parent back
    int cost = costs[0] + costs[1]; // all is cost
    DBG("FULL(%d) cost %d\n", node, cost);
    return cost;
  }

  
  sort(costs.begin(), costs.end());
  reverse(costs.begin(), costs.end());

  // add costs of the others, except 2 highest cost
  int totCost = 0;
  for (k = 2; k < size; k++) {
    if (costs[k] != INF) {
      totCost += costs[k];
    }
  }
  
  return totCost;
}


int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  int ti = 1;
  while(tn) {
    int N;
    int n;

    v = scanf("%d",&N);
    DBG("N %d\n",N);

    // clear all vectors
    G.clear();
    for (n = 0; n < N; n++) {
      G[n].clear();
    }

    for (n = 0; n < N-1; n++) {
      int X,Y;
      v = scanf("%d %d",&X,&Y);
      DBG("X %d Y %d\n",X,Y);

      int W = -1; // dont use weights
      G[X].push_back(make_pair(Y,W));
      // also push back direction
      G[Y].push_back(make_pair(X,W));
    }


    // first all nodes with one child must be remved...
    int minDel = INF;
    for (n = 1; n <= N; n++) {
      vector<ii> e = G[n];

      if (e.size() > 0) {
        visited[n] = 1;
        int del = getDel(-1,n,e);
        visited[n] = 0;
        if (del < minDel) {
          minDel = del;
        }
        DBG("[%d]-- minDel %d / %d --\n", ti, del, minDel);
      }
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
