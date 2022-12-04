#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;


int main() {
    cin>>n;
    vector<int> A(n);
    for (int i=1; i<=n;i++) cin>>A[i];
    
    freopen("input.txt", "r",stdin);
    bool B[n+1][n+1];
    memset(B, false,sizeof(B));
    for(int i=1; i<=n; i++) B[i][i] = true;   //xau con co do dai bang 1
    //xet xau con co do dai tu 2 den n
    int ans =1;
    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<= n-l +1;i++)
        {
            int j = i+l-1;
            //B[i][j] co do dai bang l
            if(l==2 && A[i]==A[j] ) B[i][j] = true;
            else {
                B[i][j] = B[i+1][j-1] && (A[i] == A[j]);
            }
            if(B[i][j]) ans = max(ans, l);
        }
    }
    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}




