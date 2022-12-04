#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string x, y;


int main() {
    cin>>x>>y;
    int n= x.size(), m= y.size();
    int A[n+1][m+1];
    for(int i=0; i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) A[i][j] =0;
            else{
                if(x[i-1] == y[j-1])   A[i][j] = A[i-1][j-1] +1;
                else A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
        }
    }
    cout<<A[n][m]<<endl;
    return 0;
}
