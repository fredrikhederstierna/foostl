#ifndef _FOOSTL_H_
#define _FOOSTL_H_

// CLIB/STL includes
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdbool>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// Work in global namespace
using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

typedef vector<int>  vi;
typedef vector<ii> vii;

// AdjList
typedef vector<vii> graph;

#define INF (1000*1000*1000)

//#define REP,  TRvii

// macros on <vector>
#define ALL(x) x.begin(), x.end()
#define UNIQ(c) (c).resize(unique(ALL(c)) - (c).begin())

#define MKP make_pair
#define NXP next_permutation
#define PBK push_back
#define PRQ priority_queue

// make_pair, next_permutation, push_back, sort
// stack, queue, deque, priority_queue
// set, map

// NOT: list, hashtable




#endif //_FOOSTL_H_
