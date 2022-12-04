#include <bits/stdc++.h>
using namespace std ; 
int t[100001];
int r[100001];
int N ; 
int memo[100001];
int time(int i){ // time(i): thoi gian it nhat de phat den nha thu i
    if (memo[i] != -1) return memo[i];
    if (i == 0) return t[i];
    if (i == 1) return min(t[0]+t[1],r[1]);
    return memo[i]= min(time(i-1)+t[i],r[i]+time(i-2)); 
}

int main(){
    cin >> N ;
    for(int i=0; i<N ; i++){
        memo[i]= -1;
        cin >> t[i] ;
    }
    for (int i = 1; i < N; i++)
        cin >> r[i];
    cout << time(N-1) << endl;
    return 0;
}