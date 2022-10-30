#include <bits/stdc++.h>

using namespace std;
int W;
int n;
int w[2000], v[2000];
int db[2000][2000];
int solve(int i, int wt)
{
    if( i==-1) return 0;
    if(wt == 0) return 0;
    if(db[i][wt] != -1) return db[i][wt];
    int r =solve(i-1,wt);     //TH ko lay
    if(wt >= w[i])
        r = max(r, solve(i-1, wt - w[i]) +v[i]);
    return db[i][wt] = r;
}
int main()
{
    cin>>W>>n;
    for(int i=0; i<n;i++)  cin>>w[i];
    for(int i=0; i<n;i++) cin>>v[i];
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<=W; j++)
            db[i][j] = -1;
    }
    cout<<solve(n-1,W);

    return 0;
}
