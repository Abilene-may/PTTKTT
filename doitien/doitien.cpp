#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int n;
map <long long int, long long int> MEMO;
long long int solve( long long int n)
{

    if(n==0) {return 0;}
    if(MEMO[n] != 0)
        return MEMO[n];
   return MEMO[n] = max(solve(n/2)+solve(n/3)+solve(n/4),n);

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    while(cin>>n)
    {
        cout<<solve(n)<<endl;
    }
    return 0;
}