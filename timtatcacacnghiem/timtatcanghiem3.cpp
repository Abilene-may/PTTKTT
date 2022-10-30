#include <iostream>
using namespace std;
int N, K;
void solve(string s, int n, int k){
    if (k == 0){
        for(int i=0; i<n;i++) 
            if (s.size() == 0) s+= "0";
            else s+= " 0";
        cout<<s<<endl;
        return;
    }
    if (n == 0)
        return;
    for(int i= k; i >= 0; i--){
        if (i % n != 0) 
            continue;
        string st;
        if (s.size() == 0)
            st= to_string(i/n);
        else
            st= s+ " " + to_string(i/n);
        solve(st, n-1, k-i);
    }
}
int main(){
    
    cin>>N>>K;
    solve("", N, K);
    return 0;
}