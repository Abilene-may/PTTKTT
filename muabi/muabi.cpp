#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>   
using namespace std;
int N,M;
int sum = 0;
int m=0;
int main(){
vector<vector<int>> a;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        vector<int> t(2);
        cin>>t[1]>>t[0];
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    while(!a.empty() && m<N) {
        if(a[a.size()-1][1]<=0){
            a.pop_back();
            
        }
        else {
            sum+=a[a.size()-1][0];
            a[a.size()-1][1]--;
            m++;
        }
    }
    cout << sum;
    return 0;
}