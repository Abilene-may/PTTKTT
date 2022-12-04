#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;
const int maxx = 1e6 + 5;
int id[maxx];
int sz[maxx];
int lead[maxx];

int root(int p) {
  while (p != id[p]) {
    p = id[p];
  }
  return p;
}
int getlead(int i) {
  while (i != lead[i])
    i = lead[i];
  return i;
}
bool connected(int p, int q) {
  if (getlead(p) == getlead(q)) {
    return 1;
  } else
    return 0;
}

void Union(int p, int q) {
  int lp = getlead(p);
  int lq = getlead(q);
  int rp = root(p);
  int rq = root(q);
  if (lp == lq) {
    return;
  }
  if (lp < lq) {
    lead[lq] = lp;
    id[rq] = rp;
    sz[lp] += sz[lq];
  } else {
    lead[lp] = lq;
    id[rp] = rq;
    sz[lq] += sz[lp];
  }
}

int main() {

  int m;
  cin >> m;
  for (int i = 1; i <= 2 * m; i++) {
    id[i] = i;
    lead[i] = i;
    sz[i] = 1;
  }
  map<string, int> mapp;
  int count = 1;
  string memory[maxx];
  for (int j = 1; j <= m; j++) {
    string x1, x2;
    cin >> x1 >> x2;
    if (mapp[x1] == 0) {
      mapp[x1] = count;
      memory[count] = x1;
      count++;
    }
    if (mapp[x2] == 0) {
      mapp[x2] = count;
      memory[count] = x2;
      count++;
    }
    Union(mapp[x1], mapp[x2]);
  }

  int x, sonhom=0;
  for (int i = 1; i < count; i++) {
    int li = getlead(i);
    if (i == li) {
      x = sz[root(i)];
      ++sonhom;
    }
  }
    cout<<sonhom<<endl;
 for (int i = 1; i < count; i++) {
    int li = getlead(i);
    if (i == li) {
      x = sz[root(i)];
      cout << memory[i] << " " << x << endl;
    }
  }
  return 0;
}
