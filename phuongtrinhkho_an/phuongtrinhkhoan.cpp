#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double p, q, r, s, t, u;
double le, ri, mid;
double f(double x)
{
    return p * exp(-x) + q*sin(x)+ r * cos(x) + s * tan(x) + t * x*x + u;
}

int main()
{
    
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        if (f(1) *f(0) > 0){
          cout << "No solution" << endl;
          continue;
        }
        le = 0;
        ri = 1;
        while (abs(ri - le) > 1e-12)
        {
            mid = (le + ri) / 2;
            double no = f(mid);
            if (no < 0)
                ri = mid;
            else
                le = mid;

        }
        cout << setprecision(4) << fixed << le << endl;
    }

    return 0;
}