#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
long long int x, a, r, n,m;

const long long mod = 1e9+7;
// ham tinh luy thua
// a^b = (a^(b/2)^2 * a^(b%2))
long long  power(long long a, long long b) {
  if(b ==0)
    return 1;
  if (b==1)
    return a % mod;
  long long x =power(a,b/2);
  x = (x*x)%mod;
  x = (x*power(a, b%2)) %mod;
  return x;
}
long long f(int m) {
  if (m == 0)
    return 0;
  if (m==1)
    return 1;
  long long x=0;
  if (n % 2 != 0) {
    x = power(r, m - 1);
    m -=1;
  }
  int k = (m-1)/2;
  x += f(k+1) * (1 + power(r, k+1));
  x%=mod;
  return x;
}
long long p(int n) {
  if (n == 0)
    return 0;
  if (n==1)
    return 1;
  long long x=0;
  if (n % 2 != 0) {
    x = power(r, n - 1);
    n -=1;
  }
  int k = (n-1)/2;
  x += f(k+1) * (1 + power(r, k+1));
  x%=mod;
  return x;
}
int main() {
  cin >> a >>r>>n>>m;
  long long int sum = a * (f(m)-p(n));
    sum%=mod;
  sum+=mod;
  cout << sum%mod;
  return 0;
}