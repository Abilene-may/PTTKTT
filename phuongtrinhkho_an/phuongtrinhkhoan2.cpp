#include <cmath>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int p, q, r, s, t, u;

double solve(double x) {
    return (-p * exp(-x) - q * sin(x) - r * cos(x) - s * tan(x) - t * x * x - u);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (solve(0) > 0 || solve(1) < 0) {
            cout << "No solution" << endl;
            continue;
        }
        double le = 0, ri = 1, mid;
        while (abs(ri - le) > 1e-15) {
            mid = (le + ri) / 2;
            if (solve(mid) >= 0) ri = mid;
            else le = mid;
        }
        cout << fixed << setprecision(4) << le << endl;
    }
    return 0;
}
