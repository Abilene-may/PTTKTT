#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
double a, b, c, delta, x1, x2;
int main()
{
    cin>>a>>b>>c;
    if(a == 0) {
        
        if(b == 0) {
            if (c == 0) {
                cout << "Vo so nghiem\n";
            } else {
                cout << "Vo nghiem";
            }
        } else {
            cout <<round((-c/b)*10000)/10000 << endl;
        }
    } else {
        delta = b*b - 4*a*c;
        if(delta > 0) {
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            if(x1<x2)
                cout<<round(x1*10000)/10000<<"\n"<<round(x2*10000)/10000<<"\n";
            else 
                cout<<round(x2*10000)/10000<<"\n"<<round(x1*10000)/10000<<"\n";
        } else if ( delta == 0) {
            cout <<round((-b/2*a)*10000)/10000 << endl;
        } else {
            cout << "Vo nghiem" << endl;
        }
    }
    return 0;
}
