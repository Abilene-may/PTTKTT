#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int n, S, sum =0;

int A[100];
int db[100][5001];
int solve(int i, int s)
{

    if( i==-1 ) return s;
    if (s==0) return 0;
    if(db[i][s] != -1) return db[i][s];
    db[i][s]=s;

    int r =solve(i-1,s);     //TH ko lay
    // cout<<"r="<<r<<endl;
    // cout<<"s-A["<<i<<"]"<<s-A[i]<<endl;
    if(s-A[i]>=0)
    {
        r = min(r, solve(i-1, s - A[i]));
    }
    //cout<<"r ="<<r<<endl;
    return db[i][s] = r;
    
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n;i++)  {
        cin>>A[i];
        sum += A[i];
    }
    S = sum/2;
    for(int i=0; i<n;i++) 
    {
        for(int j=0; j<=S;j++)
        {  db[i][j] =-1; }
    }   
    int b = S-solve(n-1,S);
    int c = sum - b;
    int chenhlech = abs(c-b);
    cout<<chenhlech<<endl;

    return 0;
}

/*
TH tim max
int solve(int i, int wt)
{
    if(i==0 || wt ==0) return 0;
    if(db[i][wt] != -1) return db[i][wt];
    int r = solve(i-1, wt);
    if(wt >= wt[i])
    {
        r = max(r, solve(i-1, db[i-1][wt-A[i]] + A[i]))

    }
    return db[i][wt] = r;
}

*/