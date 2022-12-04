#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    //L[i] do dai cua day con tang dai nhat ket thuc o i
    //L[i] = max(L[i], L[j]+1) : a[i] > a[j]
    //freopen("input.txt", "r", stdin);
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> L(n,1);     //vector co n phan tu =1
    for(int i=0; i<n;i++)
    { 
        for(int j=0; j<i;j++)
        {
            if(a[i]>a[j]) L[i] = max(L[i],L[j]+1);
            
        }
    }
    // int max = L[0];
    // for(int i=0; i<n;i++)
    // {
    //     if(max < L[i]) max = L[i];
    // }
    // cout<<max<<endl;
    cout<<*max_element(L.begin(), L.end())<<endl;
    
    return 0;
}
