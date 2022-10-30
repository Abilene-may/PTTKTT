#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxx = 1e6;
const int mod = 1e9 +7;
int id[maxx];
int sz[maxx];
int slg[maxx];

int root(int i)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void Union(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if (i == j)
    {
        return;
    }
    else
    {
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
}
long long fac(int x)   //ham tinh gia thua
{
  if(x==1) return 1;
    return (fac(x-1)*x)%mod;
}

int main() {
  int n;        //so luong svien
  int m;         //so cap svien
  cin>>n>>m;
    for (int i =0; i <=n; i++)
    {
        id[i] = i;
        sz[i] = 1;
        slg[i] =0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
  
    for(int i = 1;i<=n;i++){
        int c = root(i);
        slg[c]=sz[c];
    }

    long long int ans =0;
    for(int i = 1;i<=n;i++){
        if(slg[i]>2)
            ans=(ans+fac(slg[i]))%mod;
    }
  cout<<ans<<endl;
    
    return 0;
}